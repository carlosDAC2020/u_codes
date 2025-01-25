"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""
import concurrent.futures
import requests
from bs4 import BeautifulSoup
from time import time
from collections import defaultdict
from queue import Queue
import os
import matplotlib.pyplot as plt

# Lista de URLs de sitios deportivos
URLS = [
    "https://www.skysports.com/",
    "https://www.bbc.com/sport",
    "https://www.cnn.com/sport",
    "https://www.espn.com/",
    "https://www.foxnews.com/sports",
    "https://sports.yahoo.com/",
    "https://www.goal.com/",
    "https://www.nbcsports.com/",
    "https://www.si.com/",
    "https://www.bleacherreport.com/",
    "https://www.sportingnews.com/",
    "https://www.sbnation.com/",
]
URLS = URLS * 2

# Lista de palabras clave relacionadas con deportes
SPORTS_KEYWORDS = [
    "fútbol", "baloncesto", "tenis", "natación", "golf", "ciclismo", "atletismo",
    "voleibol", "rugby", "cricket", "béisbol", "hockey", "esquí", "surf", "boxeo",
    "mma", "olimpiadas", "juegos", "competición", "entrenamiento", "atleta", "maratón"
]

# Función para obtener el contenido de una lista de URLs y ponerlo en la cola
def fetch_and_enqueue(url, queue):
    try:
        print(f"Fetching {url}")
        response = requests.get(url)
        response.raise_for_status()  # Verifica si hubo algún error en la respuesta
        queue.put(response.text)
    except Exception as exc:
        print(f'Error fetching {url}: {exc}')

# Función para extraer palabras clave deportivas del contenido HTML
def extract_keywords(html_content):
    print("Extracting keywords...")
    soup = BeautifulSoup(html_content, 'html.parser')
    text = soup.get_text()
    words = text.split()
    filtered_keywords = [word.lower() for word in words if word.lower() in SPORTS_KEYWORDS]
    keyword_freq = defaultdict(int)
    for keyword in filtered_keywords:
        keyword_freq[keyword] += 1
    return dict(keyword_freq)


def experiment(num_threads, num_processes):
    print(f"\n Testing with:\n  {num_threads} threads \n  {num_processes} processes ")
    start_time = time()
    queue = Queue()
    keyword_results = defaultdict(int)

    # Paso 1: Crear ThreadPoolExecutor para obtener páginas web
    with concurrent.futures.ThreadPoolExecutor(max_workers=num_threads) as thread_executor, \
        concurrent.futures.ProcessPoolExecutor(max_workers=num_processes) as process_executor:
        
        # Enviar tareas de obtención de contenido en hilos
        fetch_futures = [thread_executor.submit(fetch_and_enqueue, url, queue) for url in URLS]
        
        # Extraer palabras clave en cuanto haya contenido en la cola
        extract_futures = []
        while any(future.running() for future in fetch_futures) or not queue.empty():
            while not queue.empty():
                html_content = queue.get()
                extract_futures.append(process_executor.submit(extract_keywords, html_content))

        # Recogemos los resultados a medida que están disponibles
        for future in concurrent.futures.as_completed(extract_futures):
            try:
                keywords = future.result()
                for keyword, freq in keywords.items():
                    keyword_results[keyword] += freq
            except Exception as exc:
                print(f'Error extracting keywords: {exc}')

    # Mostrar resultados y medir el tiempo
    print("\n Keywords extracted:")
    for keyword, freq in keyword_results.items():
        print(f"{keyword}: {freq}")
    print(f"Time taken: {time() - start_time:.2f} seconds")

    return {
        "threads": num_threads, 
        "processes": num_processes, 
        "time": time() - start_time
        }


def plot_results(results):
    configurations = [f"{res['threads']}T-{res['processes']}P" for res in results]
    times = [res["time"] for res in results]

    min_time = min(times)
    min_index = times.index(min_time)

    plt.figure(figsize=(10, 6))
    plt.plot(configurations, times, marker='o', color='b', label='Execution Time')
    plt.plot(configurations[min_index], min_time, marker='o', markersize=10, color='r', label='Best Time')
    plt.xlabel("Configuration (Threads-Processes)")
    plt.ylabel("Execution Time (seconds)")
    plt.title("Execution Time per Configuration")
    plt.legend()
    plt.grid(True)
    plt.show()

# Función principal que coordina el proceso de obtención y extracción
def main():
    num_cores = os.cpu_count()
    print(f"Detected {num_cores} cores -------")

    # tipo de prueba
    print("fetching and extracting keywords")
    type_test = input("Enther the type of test \n 1. Manual \n 2. Automatic \n")

    if type_test == "1":
        # prueba manual
        print("Manual test")
        num_threads = int(input("Enter the number of threads: "))
        num_processes = int(input("Enter the number of processes: "))
        experiment(num_threads, num_processes)
    else:
        print("Automatic test")
        # prueba con aumento progresivo de nuemro de hilos y procesos
        results = []
        for num_cores in [1, 2, 4, 8, 16, 32]:
            result = experiment(num_cores, num_cores)
            results.append(result)
        plot_results(results)
        
if __name__ == "__main__":
    main()
