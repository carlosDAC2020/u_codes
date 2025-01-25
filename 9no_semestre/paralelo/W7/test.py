"""import threading
import numpy as np
from collections import deque
import time
import os 

# Cola compartida
queue = deque()

# Tamaño de la cola
MAX_QUEUE_SIZE = 10

# Variables de condición
condition = threading.Condition()

# Función del Productor
def producer(matrix_a):
    for row in matrix_a:
        with condition:
            while len(queue) == MAX_QUEUE_SIZE:
                condition.wait()  # Esperar si la cola está llena

            # Insertar la fila en la cola para su multiplicación
            queue.append(row)
            condition.notify()  # Notificar a los consumidores que pueden procesar

    # Insertar una señal de terminación (None) para indicar que el productor terminó
    with condition:
        queue.append(None)
        condition.notify()  # Notificar al consumidor que puede terminar

# Función del Consumidor
def consumer(matrix_b, result_matrix):
    while True:
        with condition:
            while not queue:
                condition.wait()  # Esperar si la cola está vacía

            row = queue.popleft()

            # Verificar la señal de terminación
            if row is None:
                break

            # Procesar la fila, multiplicarla por la matriz B
            result_row = np.dot(row, matrix_b)
            result_matrix.append(result_row)

            condition.notify()  # Notificar al productor que puede producir más

# Tamaño de la matriz
n = 1000  # Aumenta el tamaño de las matrices para notar diferencias en tiempo
# Número de núcleos disponibles en el dispositivo
num_consumers = os.cpu_count()

while n<=5000:
    print(f"\n probando con n: {n}")
    # Generar matrices aleatorias
    matrix_a = np.random.rand(n, n)
    matrix_b = np.random.rand(n, n)

    # Ejecutar la forma serial
    start_serial = time.time()
    result_matrix_serial = np.dot(matrix_a, matrix_b)
    end_serial = time.time()

    # Imprimir el tiempo serial
    print(f"Tiempo de ejecución serial: {end_serial - start_serial:.4f} segundos")

    # Matriz resultante para la ejecución paralela
    result_matrix_parallel = []

    # Crear hilos para productor y consumidor
    start_parallel = time.time()
    producer_thread = threading.Thread(target=producer, args=(matrix_a,))
    consumer_thread = threading.Thread(target=consumer, args=(matrix_b, result_matrix_parallel))
    
    # Iniciar hilos
    producer_thread.start()
    consumer_thread.start()

    # Unir hilos
    producer_thread.join()
    consumer_thread.join()
    end_parallel = time.time()

    # Convertir la lista resultante paralela en un array de NumPy para facilitar la comparación
    result_matrix_parallel = np.array(result_matrix_parallel)

    # Imprimir el tiempo paralelo
    print(f"Tiempo de ejecución paralelo: {end_parallel - start_parallel:.4f} segundos")

    # Evaluar si ambas matrices son similares
    if np.allclose(result_matrix_serial, result_matrix_parallel):
        print("Las matrices resultantes en serial y paralelo son similares.")
    else:
        print("Las matrices resultantes en serial y paralelo no son similares.")

    n+=1000

# Imprimir el resultado final
#print(f"Matriz resultante serial:\n{result_matrix_serial}")
#print(f"Matriz resultante paralela:\n{result_matrix_parallel}")
"""


"""import numpy as np
import time
import os
import threading

# Número de núcleos disponibles en el dispositivo
num_consumers = os.cpu_count()

n = 1000
while n<=5000:
    print(f"\n probando con n: {n}")
    # Generar matrices aleatorias
    matrix_a = np.random.rand(n, n).tolist()  # Convertir a listas de listas
    matrix_b = np.random.rand(n, n).tolist()  # Convertir a listas de listas

    # Ejecutar la forma serial usando numpy para referencia
    start_serial = time.time()
    result_matrix_serial = np.dot(matrix_a, matrix_b)
    end_serial = time.time()
    time_serial = end_serial - start_serial
    print(f"Tiempo de ejecución serial: {time_serial:.4f} segundos")

    # Definir el tamaño de las submatrices (intervalos)
    sise_sun_m = int(n / num_consumers)
    parts_num = int(n / sise_sun_m)

    print(f"Tamaño de intervalo: {sise_sun_m}")
    print(f"Número de intervalos: {parts_num}")

    # Dividir matrix_a en sublistas de tamaño sise_sun_m
    sub_list_a = [matrix_a[i:i + sise_sun_m] for i in range(0, n, sise_sun_m)]

    # Lista compartida para acumular los resultados de cada hilo
    result_matrix_accumulated = [None] * len(sub_list_a)

    # Función para realizar la multiplicación de una sublista por matrix_b en un hilo
    def multiply_sublist(i, sub_list):
        result_matrix_sublist = np.dot(sub_list, matrix_b)
        result_matrix_accumulated[i] = result_matrix_sublist


    # Ejecutar la forma serial usando numpy para referencia
    start_parallel = time.time()
    # Crear los hilos para cada sublista
    threads = []
    for i, sub_list in enumerate(sub_list_a):
        thread = threading.Thread(target=multiply_sublist, args=(i, sub_list))
        threads.append(thread)
        thread.start()

    # Esperar a que todos los hilos terminen
    for thread in threads:
        thread.join()
    end_parallel = time.time()
    time_parallel = end_parallel - start_parallel

    # Imprimir los tiempos de ejecución
    print(f"Tiempo de ejecución paralelo: {time_parallel:.4f} segundos")

    # Unir todos los resultados en una única matriz
    result_matrix_accumulated = np.vstack(result_matrix_accumulated)

    # Comparar la matriz completa con la generada en serie
    if np.allclose(result_matrix_serial, result_matrix_accumulated):
        print("Las matrices generadas de forma serial y por hilos son similares.")
    else:
        print("Las matrices generadas de forma serial y por hilos NO son similares.")

    n+=1000
"""


import numpy as np
import time
import os
import threading
import queue

# Número de núcleos disponibles en el dispositivo
num_consumers = os.cpu_count()

n = 1000
while n <= 12000:
    print(f"\n probando con n: {n}")
    # Generar matrices aleatorias
    matrix_a = np.random.rand(n, n)
    matrix_b = np.random.rand(n, n)

    # Ejecutar la forma serial usando numpy para referencia
    start_serial = time.time()
    result_matrix_serial = np.dot(matrix_a, matrix_b)
    end_serial = time.time()
    time_serial = end_serial - start_serial
    print(f"Tiempo de ejecución serial: {time_serial:.4f} segundos")

    # Definir el tamaño de las submatrices (intervalos)
    sise_sun_m = int(n / num_consumers*2)
    parts_num = int(n / sise_sun_m)


    # Cola compartida para las tareas
    task_queue = queue.Queue()
    result_queue = queue.Queue()

    # Producer: llenar la cola con submatrices de matrix_a
    def producer():
        for i in range(0, n, sise_sun_m):
            sub_matrix_a = matrix_a[i:i + sise_sun_m]
            task_queue.put((i, sub_matrix_a))  # (índice de fila inicial, submatriz)
        # Colocar un marcador para indicar que se ha terminado
        for _ in range(num_consumers):
            task_queue.put(None)

    # Consumer: consumir las tareas de la cola y realizar la multiplicación
    def consumer():
        while True:
            task = task_queue.get()
            if task is None:
                break
            i, sub_matrix_a = task
            result_sub_matrix = np.dot(sub_matrix_a, matrix_b)
            result_queue.put((i, result_sub_matrix))
            task_queue.task_done()

    

    # Iniciar hilo producer
    producer_thread = threading.Thread(target=producer)
    
    list_consumers=[]
    for _ in range(num_consumers):
        consumer_thread = threading.Thread(target=consumer)
        list_consumers.append(consumer_thread)

    # Ejecutar la forma paralela usando hilos
    start_parallel = time.time()
    producer_thread.start()
    for c_t in list_consumers:
        c_t.start()

    producer_thread.join()   
    for c_t in list_consumers:
        c_t.join() 

    # Unir los resultados en una única matriz
    result_matrix_accumulated = np.zeros((n, n))
    while not result_queue.empty():
        i, result_sub_matrix = result_queue.get()
        result_matrix_accumulated[i:i + sise_sun_m] = result_sub_matrix

    end_parallel = time.time()
    time_parallel = end_parallel - start_parallel

    # Imprimir los tiempos de ejecución
    print(f"Tiempo de ejecución paralelo: {time_parallel:.4f} segundos")

    speedup=time_serial/time_parallel
    print(f" speedup. {speedup}")

    n += 1000

"""
import numpy as np
import time
import os
import threading
import queue
import multiprocessing


if __name__ == "__main__":
    # Número de núcleos disponibles en el dispositivo
    num_consumers = os.cpu_count()

    n = 1000
    while n <= 9000:
        print(f"\nProbando con n: {n}")
        # Generar matrices aleatorias
        matrix_a = np.random.rand(n, n)
        matrix_b = np.random.rand(n, n)

        # 1. Ejecución serial
        start_serial = time.time()
        result_matrix_serial = np.dot(matrix_a, matrix_b)
        end_serial = time.time()
        time_serial = end_serial - start_serial
        print(f"Tiempo de ejecución serial: {time_serial:.4f} segundos")

        # Definir el tamaño de las submatrices (intervalos)
        size_sub_m = int(n / (num_consumers + 1))
        parts_num = int(n / size_sub_m)

        # 2. Ejecución con hilos
        task_queue = queue.Queue()
        result_queue = queue.Queue()

        def producer():
            for i in range(0, n, size_sub_m):
                sub_matrix_a = matrix_a[i:i + size_sub_m]
                task_queue.put((i, sub_matrix_a))
            for _ in range(num_consumers):
                task_queue.put(None)

        def consumer():
            while True:
                task = task_queue.get()
                if task is None:
                    break
                i, sub_matrix_a = task
                result_sub_matrix = np.dot(sub_matrix_a, matrix_b)
                result_queue.put((i, result_sub_matrix))
                task_queue.task_done()

        start_threads = time.time()

        # Iniciar hilo producer
        producer_thread = threading.Thread(target=producer)
        producer_thread.start()

        # Iniciar hilos consumers
        consumer_threads = []
        for _ in range(num_consumers):
            consumer_thread = threading.Thread(target=consumer)
            consumer_threads.append(consumer_thread)
            consumer_thread.start()

        # Esperar a que el hilo producer termine
        producer_thread.join()

        # Esperar a que todos los hilos consumidores terminen
        for consumer_thread in consumer_threads:
            consumer_thread.join()

        # Unir los resultados
        result_matrix_threads = np.zeros((n, n))
        while not result_queue.empty():
            i, result_sub_matrix = result_queue.get()
            result_matrix_threads[i:i + size_sub_m] = result_sub_matrix

        end_threads = time.time()
        time_threads = end_threads - start_threads

        print(f"Tiempo de ejecución con hilos: {time_threads:.4f} segundos")
        speedup_threads = time_serial / time_threads
        print(f"Speedup con hilos: {speedup_threads:.4f}")

        # 3. Ejecución con procesos
        def worker_process(i, sub_matrix_a, matrix_b, result_queue):
            result_sub_matrix = np.dot(sub_matrix_a, matrix_b)
            result_queue.put((i, result_sub_matrix))

        start_processes = time.time()
        
        processes = []
        result_queue_multiprocessing = multiprocessing.Queue()

        for i in range(0, n, size_sub_m):
            sub_matrix_a = matrix_a[i:i + size_sub_m]
            p = multiprocessing.Process(target=worker_process, args=(i, sub_matrix_a, matrix_b, result_queue_multiprocessing))
            processes.append(p)
            p.start()

        for p in processes:
            p.join()

        # Unir los resultados
        result_matrix_processes = np.zeros((n, n))
        while not result_queue_multiprocessing.empty():
            i, result_sub_matrix = result_queue_multiprocessing.get()
            result_matrix_processes[i:i + size_sub_m] = result_sub_matrix

        end_processes = time.time()
        time_processes = end_processes - start_processes

        print(f"Tiempo de ejecución con procesos: {time_processes:.4f} segundos")
        speedup_processes = time_serial / time_processes
        print(f"Speedup con procesos: {speedup_processes:.4f}")

        n += 1000
"""