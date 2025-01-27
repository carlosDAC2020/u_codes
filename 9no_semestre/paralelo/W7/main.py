"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""

import numpy as np
import time
import os
import threading
import queue

# Número de núcleos disponibles en el dispositivo
num_consumers = os.cpu_count()

# Tamaño de las matrices a calcular
n = int(input("Ingresar tamaño de las matrices a calcular: "))

print(f"\nProbando con n: {n}")

# Generar matrices aleatorias
matrix_a = np.random.rand(n, n)
matrix_b = np.random.rand(n, n)

# Convertir matrices a un formato que se puede imprimir fácilmente
def print_matrix(matrix, name):
    print(f"\n{name}:")
    print(matrix)

# Imprimir las matrices
print_matrix(matrix_a, "Matrix A")
print_matrix(matrix_b, "Matrix B")

# Ejecutar la forma serial usando numpy para referencia
start_serial = time.time()
result_matrix_serial = np.dot(matrix_a, matrix_b)
end_serial = time.time()
time_serial = end_serial - start_serial
print(f"Tiempo de ejecución serial: {time_serial:.4f} segundos")

# Definir el tamaño de las submatrices (intervalos)
sise_sub_m = int(n / num_consumers)
parts_num = int(n / sise_sub_m)

# Cola compartida para las tareas
task_queue = queue.Queue()
result_queue = queue.Queue()

# Producer: llenar la cola con submatrices de matrix_a
def producer():
    for i in range(0, n, sise_sub_m):
        sub_matrix_a = matrix_a[i:i + sise_sub_m]
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

list_consumers = []
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
    result_matrix_accumulated[i:i + sise_sub_m] = result_sub_matrix

end_parallel = time.time()
time_parallel = end_parallel - start_parallel

# Imprimir los tiempos de ejecución
print(f"Tiempo de ejecución paralelo: {time_parallel:.4f} segundos")

# Imprimir la matriz resultante de la multiplicación paralela
print_matrix(result_matrix_accumulated, "Resultado Matrix Paralelo")

# Validar si las matrices generadas son iguales
if np.allclose(result_matrix_serial, result_matrix_accumulated):
    print("La matriz resultante de la multiplicación paralela es igual a la de la multiplicación serial.")
else:
    print("La matriz resultante de la multiplicación paralela NO es igual a la de la multiplicación serial.")

# Calcular el speedup
speedup = time_serial / time_parallel
print(f"Speedup: {speedup:.4f}")

"""
Comentarios:
- La implementación utiliza la multiplicación de matrices usando tanto un enfoque serial (con numpy) como paralelo (con hilos).
- Se imprimen las matrices originales y el resultado final de la multiplicación paralela.
- En el enfoque paralelo, el productor divide la matriz en submatrices y las coloca en una cola de tareas.
- Los consumidores extraen las submatrices de la cola, realizan la multiplicación y colocan los resultados en una cola de resultados.
- Los resultados se ensamblan finalmente en una única matriz.
- Se valida si la matriz resultante de la multiplicación paralela es igual a la de la serial, usando np.allclose para tolerar pequeñas diferencias numéricas.
- El speedup se calcula como la razón del tiempo serial sobre el tiempo paralelo. Generalmente, el speedup aumenta con el tamaño de las matrices, mientras que para matrices más pequeñas, el rendimiento paralelo puede no ser significativamente mejor que el serial.
"""
