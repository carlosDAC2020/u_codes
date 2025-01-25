import numpy as np
import os
import time
from queue import Queue
import threading

# Inicializa variables globales
GLOBAL_QUEUE = Queue(maxsize=10)
condition = threading.Condition()
result = None
stop_event = threading.Event()
fill_count = 0
empty_count = 0
producer_wait_times = []
consumer_wait_times = []

def serial_multiply_matrices(A, B):
    print("Multiplicación en serie...")
    size = A.shape[0]
    result = np.zeros((size, B.shape[1]))
    
    for i in range(size):
        result[i, :] = np.dot(A[i, :], B)

    return result

def split_matrix(A, chunk_size):
    size = A.shape[0]
    chunks = []
    for start_row in range(0, size, chunk_size):
        end_row = min(start_row + chunk_size, size)
        subA = A[start_row:end_row, :]
        chunks.append((subA, start_row))
    
    return chunks

def producer(A, num_threads):
    global GLOBAL_QUEUE, fill_count

    size = A.shape[0]
    chunk_size = size // num_threads
    chunks = split_matrix(A, chunk_size)

    for subA, start_row in chunks:
        with condition:
            while GLOBAL_QUEUE.full():
                start_time = time.time()
                print("Cola llena, productor esperando...")
                fill_count += 1
                condition.wait()
                producer_wait_times.append(time.time() - start_time)
            GLOBAL_QUEUE.put((subA, start_row))
            print(f"Se ha agregado el chunk de filas: {start_row} a {start_row + subA.shape[0] - 1} a la cola")
            condition.notify()
    stop_event.set()
    with condition:
        condition.notify_all()

def consumer(B):
    global GLOBAL_QUEUE, result, empty_count
    
    while True:
        with condition:
            while GLOBAL_QUEUE.empty():
                if stop_event.is_set():
                    return
                
                start_time = time.time()
                print("Cola vacía, consumidor esperando...")
                empty_count += 1
                condition.wait()
                consumer_wait_times.append(time.time() - start_time)

            subA, row_start = GLOBAL_QUEUE.get()
            print(f"Consumidor procesa chunk de filas {row_start} a {row_start + subA.shape[0] - 1}")
            result_chunk = np.dot(subA, B)
            result[row_start:row_start + subA.shape[0], :] = result_chunk
            condition.notify()

# Inicializa la prueba
def test_serial_multiply_matrices():
    global result
    A = np.random.rand(1000, 1000)
    B = np.random.rand(1000, 1000)

    start_time = time.time()
    result = serial_multiply_matrices(A, B)
    serial_time = time.time() - start_time

    print(f"Tiempo de multiplicación en serie: {serial_time:.4f} segundos")
    
    assert result.shape == (A.shape[0], B.shape[1]), "La forma del resultado es incorrecta."
    expected_result = np.dot(A, B)
    assert np.allclose(result, expected_result), "El resultado de la multiplicación es incorrecto."

def test_producer_consumer():
    global result
    A = np.random.rand(1000, 1000)
    B = np.random.rand(1000, 1000)
    num_threads = os.cpu_count()

    global result
    result = np.zeros((A.shape[0], B.shape[1]))

    producer_thread = threading.Thread(target=producer, args=(A, num_threads))
    consumer_threads = [threading.Thread(target=consumer, args=(B,)) for _ in range(num_threads)]

    start_time = time.time()
    producer_thread.start()
    for thread in consumer_threads:
        thread.start()

    producer_thread.join()
    stop_event.set()

    for thread in consumer_threads:
        thread.join()
    
    parallel_time = time.time() - start_time
    print(f"Tiempo de multiplicación en paralelo: {parallel_time:.4f} segundos")

    assert result.shape == (A.shape[0], B.shape[1]), "La forma del resultado es incorrecta."
    expected_result = np.dot(A, B)
    assert np.allclose(result, expected_result), "El resultado de la multiplicación es incorrecto."

# Llama a las pruebas
test_serial_multiply_matrices()
test_producer_consumer()

print("Todas las pruebas han pasado exitosamente.")
