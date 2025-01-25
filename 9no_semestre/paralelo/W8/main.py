"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""
import threading
import random
import numpy as np
from queue import Queue
import time
import os 

num_cores = os.cpu_count()

# Definir trabajadores con sus funciones lambda
workers = {
    "w1": {  # Suma de valores de una lista muy larga
        "work": lambda large_list: sum(large_list),
        "parameters": []
    },
    "w2": {  # Multiplicación de matrices
        "work": lambda matrix_a, matrix_b: np.dot(matrix_a, matrix_b),
        "parameters": []
    },
    "w3": {  # Busca un patrón en un archivo de texto grande.
        "work": lambda word_to_search, large_text: sum([line.count(word_to_search) for line in large_text]),
        "parameters": []
    },
    "w4": {  # Simula un "random walk" con 100,000 pasos.
        "work": lambda steps: sum(random.choice([-1, 1]) for _ in range(steps)),
        "parameters": []
    },
    "w5": {  # Calcula el valor máximo en un array grande.
        "work": lambda large_array: max(large_array),
        "parameters": []
    }
}

# Función para dividir una lista en sublistas
def dividir_lista(lista, num_partes):
    longitud = len(lista)
    tamano_parte = longitud // num_partes
    return [lista[i * tamano_parte:(i + 1) * tamano_parte] for i in range(num_partes)] + [lista[num_partes * tamano_parte:]]

# Función genérica para ejecutar en paralelo
def parallel_execution(worker_name, func, inputs, num_threads, queue_results, barrier):
    start_time = time.time()

    # Paralelización basada en la primera entrada
    subresultados = []
    threads = []

    if worker_name == "w4" and num_threads > 1:  # Para el random walk (w4)
        pasos_por_hilo = inputs[0] // num_threads

        def random_walk_parcial(steps):
            return sum(random.choice([-1, 1]) for _ in range(steps))

        for i in range(num_threads):
            thread = threading.Thread(target=lambda: subresultados.append(random_walk_parcial(pasos_por_hilo)))
            threads.append(thread)
            thread.start()

        for thread in threads:
            thread.join()

        # Combinar los resultados sumando los random walks parciales
        result = sum(subresultados)
    elif worker_name == "w2" and num_threads > 1:  # Para la multiplicación de matrices (w2)
        # Dividimos la matriz A en submatrices por filas
        submatrices_a = dividir_lista(inputs[0], num_threads)
        matrix_b = inputs[1]

        # Cada hilo multiplicará una submatriz por B
        def worker_multiplicacion(sub_matrix_a):
            resultado_parcial = func(sub_matrix_a, matrix_b)
            subresultados.append(resultado_parcial)

        # Crear y lanzar los hilos
        for sub_matrix_a in submatrices_a:
            thread = threading.Thread(target=worker_multiplicacion, args=(sub_matrix_a,))
            threads.append(thread)
            thread.start()

        # Esperar a que todos los hilos terminen
        for thread in threads:
            thread.join()

        # Combinar los subresultados en la matriz final
        result = np.vstack(subresultados)  # Une las submatrices por filas
        
    elif isinstance(inputs[0], list) and num_threads > 1:  # Si es una lista y hay más de un hilo
        sublistas = dividir_lista(inputs[0], num_threads)

        # Ejecutar cada sublista en paralelo
        for i in range(num_threads):
            thread = threading.Thread(target=lambda sublista: subresultados.append(func(*([sublista] + inputs[1:]))), args=(sublistas[i],))
            threads.append(thread)
            thread.start()

        # Esperar a que terminen todos los hilos
        for thread in threads:
            thread.join()

        # Combinar resultados dependiendo de la operación del worker
        if worker_name in ["w1", "w3"]:  # Suma de subresultados
            result = sum(subresultados)
        elif worker_name == "w5":  # Máximo
            result = max(subresultados)
    else:
        result = func(*inputs)

    end_time = time.time()
    queue_results.put((worker_name, result, end_time - start_time))
    barrier.wait()

# Función para evaluar y paralelizar
def main(workers):
    num_threads_per_worker = {worker: 1 for worker in workers}  # Cada worker comienza con 1 hilo
    previous_times = {worker: float('inf') for worker in workers}  # Tiempos anteriores de cada worker
    improvement_threshold = 0.05  # Margen de mejora del 5%

    # Datos de entrada
    print("Generación de datos de entrada")

    # Worker 1 - Suma de valores de una lista muy larga
    print("Worker 1")
    sise_list = int(input("Ingrese el tamaño de la lista para Worker 1: "))
    large_list = np.random.rand(sise_list)

    # Worker 2 - Multiplicación de matrices
    print("Worker 2")
    sise_matrices = int(input("Ingrese el tamaño de las matrices (n x n) para Worker 2: "))
    matrix_a = np.random.rand(sise_matrices, sise_matrices)
    matrix_b = np.random.rand(sise_matrices, sise_matrices)

    # Worker 3 - Búsqueda de un patrón en un archivo de texto grande
    print("Worker 3")
    file_path = input("Ingrese la ruta del archivo de texto para Worker 3: ")
    pattern = input("Ingrese el patrón a buscar: ")
    with open(file_path, "r", encoding="utf-8") as file:
        large_text = [line.lower() for line in file]

    # Worker 4 - Random walk con n pasos
    print("Worker 4")
    steps = int(input("Ingrese la cantidad de pasos para el random walk de Worker 4: "))

    # Worker 5 - Calcular el valor máximo en un array grande
    print("Worker 5")
    sise_large_array = int(input("Ingrese el tamaño del array para Worker 5: "))
    large_array = list(range(sise_large_array))


    # Organizar entradas para ejecución de workers
    inputs = {
        "w1": [large_list],
        "w2": [matrix_a, matrix_b],
        "w3": [pattern, large_text],
        "w4": [steps],
        "w5": [large_array]
    }

    while True:
        results = Queue()
        barrier = threading.Barrier(len(workers))

        # Ejecutar cada worker con su número actual de hilos
        threads = []
        print("\nEjecución de hilos")
        for worker_name, worker_info in workers.items():
            num_threads = num_threads_per_worker[worker_name]
            thread = threading.Thread(target=parallel_execution, args=(worker_name, worker_info["work"], inputs[worker_name], num_threads, results, barrier))
            threads.append(thread)
            thread.start()

        for thread in threads:
            thread.join()

        # Mostrar los tiempos de ejecución
        exec_times = {}
        print("\nReporte de ejecución")
        while not results.empty():
            worker, result, exec_time = results.get()
            exec_times[worker] = exec_time
            print(f"{worker}: Execution time: {exec_time:.4f} seconds")
            print(result)

        # Calcular el margen de mejora promedio
        total_improvement = 0
        for worker_name in exec_times:
            previous_time = previous_times[worker_name]
            current_time = exec_times[worker_name]
            improvement = (previous_time - current_time) / previous_time if previous_time != float('inf') else 1
            total_improvement += improvement
            previous_times[worker_name] = current_time

        average_improvement = total_improvement / len(workers)
        print(f"Margen de mejora promedio: {average_improvement * 100:.2f}%")

        # Condiciones de parada
        if average_improvement < improvement_threshold:  # Si la mejora es menor al 5%
            print("El margen de mejora promedio es inferior al 5%. Deteniendo ejecución.")
            break

        # Encontrar el worker más lento
        slowest_worker = max(exec_times, key=exec_times.get)
        slowest_time = exec_times[slowest_worker]
        print(f"Worker más lento: {slowest_worker} con {slowest_time:.4f} segundos.")

        # Aumentar el número de hilos para el worker más lento
        num_threads_per_worker[slowest_worker] += 1
        print(f"Aumentando el número de hilos de {slowest_worker} a {num_threads_per_worker[slowest_worker]}.")

        # Otra condición de parada: limitar el número total de hilos
        total_threads = sum(num_threads_per_worker.values())
        if total_threads > num_cores * 4:
            print("Se ha alcanzado el límite de hilos. Deteniendo ejecución.")
            break

if __name__ == "__main__":
    main(workers)
