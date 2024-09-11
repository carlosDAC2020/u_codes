"""
    Estudiante
    - Carlos Daniel Agamez Palomino T00059006
"""

import time
import os
import threading

# Función para dividir la lista en subconjuntos según el número de trabajadores
def divide_list(nums, num_workers):
    """
    Divide una lista en subconjuntos según el número de trabajadores especificado.

    Args:
        nums (list): La lista de elementos a dividir.
        num_workers (int): El número de trabajadores (subconjuntos) deseados.

    Returns:
        list: Una lista de subconjuntos.
    """
    size_subset = len(nums) // num_workers
    subsets = [nums[i:i + size_subset] for i in range(0, len(nums), size_subset)]
    
    # Asegurarse de que el último subrango incluya los elementos restantes
    if len(subsets) > num_workers:
        subsets[-2].extend(subsets[-1])
        subsets.pop()
    
    return subsets

# Función para contar la palabra en un subconjunto
def count_word(subset, word_to_search, result_dict, lock):
    """
    Cuenta la cantidad de veces que una palabra aparece en un subconjunto de líneas y actualiza el resultado de manera segura.

    Ejemplo:
        Supongamos que `subset` es una lista de líneas de texto como sigue:
        subset = [
            "Hola mundo, bienvenido al mundo de Python.",
            "En el mundo de la programación, Python es muy popular.",
            "Hola a todos, espero que disfruten aprendiendo Python."
        ]
        
        Si `word_to_search` es "mundo", la función contará cuántas veces aparece la palabra "mundo" en el `subset`.
        En este caso, el conteo sería 2 (en la primera línea) + 1 (en la segunda línea) = 3 veces.

        Si `result_dict` es un diccionario como:
        result_dict = {"mundo": 0}

        Después de llamar a `count_word(subset, "mundo", result_dict, lock)`, 
        el `result_dict` se actualizará a:
        {"mundo": 3}

    Args:
        subset (list): Lista de líneas en las que contar la palabra.
        word_to_search (str): La palabra a buscar en el subconjunto.
        result_dict (dict): Diccionario para almacenar los resultados de conteo.
        lock (threading.Lock): Lock para garantizar la sincronización en el acceso al diccionario de resultados.
    """
    count = sum(line.count(word_to_search) for line in subset)
    with lock:
        result_dict[word_to_search] += count

# Función para medir el tiempo de ejecución
def measure_time(func, *args):
    """
    Mide el tiempo de ejecución de una función.

    Args:
        func (callable): La función cuya ejecución se desea medir.
        *args: Argumentos opcionales para pasar a la función.

    Returns:
        tuple: Un tuple con el resultado de la función y el tiempo de ejecución en segundos.
    """
    start_time = time.time()
    result = func(*args)
    end_time = time.time()
    return result, end_time - start_time

# Función para la ejecución en paralelo
def parallel_count_word_repeat(list_logs, num_workers, search_word):
    """
    Cuenta la cantidad de veces que una palabra aparece en un archivo de texto usando procesamiento paralelo.

    Args:
        list_logs (list): Lista de líneas del archivo de texto.
        num_workers (int): Número de trabajadores (hilos) a usar.
        search_word (str): La palabra a buscar en el archivo.

    Returns:
        int: El número total de veces que la palabra aparece en el texto.
    """
    # Divide la lista en subconjuntos según el número de trabajadores
    sub_set_lines = divide_list(list_logs, num_workers)
    
    # Inicializa el diccionario de resultados y el lock para sincronización
    result_dict = {search_word: 0}
    lock = threading.Lock()
    
    # Crea y arranca los hilos
    threads = []
    for subset in sub_set_lines:
        thread = threading.Thread(target=count_word, args=(subset, search_word, result_dict, lock))
        threads.append(thread)
        thread.start()
    
    # Espera a que todos los hilos terminen
    for thread in threads:
        thread.join()
    
    # Devuelve el resultado
    return result_dict[search_word]


report_times={
    "serial":0,
    "paralela":0
}
if __name__ == "__main__":

    # Obtén el número de núcleos físicos
    num_cores = os.cpu_count()
    print(f"Número de núcleos (cores): {num_cores}")

    # Ruta del archivo de texto
    file_path = input(" Ingresar la ruta del archivo: ")
    # Palabra a buscar
    search_word = input(" Ingresar la palabra a buscar (en minusculas): ")
    
    # Lista para almacenar las líneas del archivo
    list_logs = []

    # Abre el archivo en modo de lectura
    with open(file_path, "r", encoding="utf-8") as file:
         # Lee cada línea del archivo, convierte a minúsculas y agrega a la lista de logs 
        list_logs = [line.lower() for line in file]
    
    for num_workers in [1, num_cores*4]:
        # Mide el tiempo de ejecución y obtén el resultado
        count, elapsed_time = measure_time(parallel_count_word_repeat, list_logs, num_workers, search_word)
        
        # Imprime el resultado
        print(f"Con {num_workers} hilos, la palabra '{search_word}' aparece {count} veces.")
        print(f"Tiempo de ejecución: {elapsed_time} segundos.")

        if num_workers==1:
            report_times["serial"]=elapsed_time
        else:
            report_times["paralela"]=elapsed_time

    print("\n Analisis")

    # obtenemos la ejecucion mas rapida
    if  report_times["paralela"] < report_times["serial"]:
        print(f" la mejor configuracion fue ejecutando de froma paralela con un tiempo de {report_times['paralela']}")
    else:
        print(f" la mejor configuracion fue ejecutando de froma serial con un tiempo de {report_times['serial']}")
    
    try:
        speedup=report_times["serial"] / report_times["paralela"] 
    except ZeroDivisionError:
        speedup = 0
    print(f" se obtuvo un speed up de {speedup} se la forma paralela con respecto a la serial")