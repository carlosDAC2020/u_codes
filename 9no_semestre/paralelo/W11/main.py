"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""

import multiprocessing
import random

# Función que simula un productor que genera números aleatorios y los envía al proceso principal
def producer(queue, pipe, producer_id):
    # Recibe la cantidad de números a generar desde el proceso principal
    cant_nums = pipe.recv()
    print(f"\nProducer {producer_id} start ...")

    # Generar números aleatorios
    numbers = [random.randint(1, 100) for _ in range(cant_nums)]  # Genera números aleatorios entre 1 y 100
    
    for number in numbers:
        queue.put(number)  # Envía los números a la cola compartida
    
    print(f"\nProducer {producer_id} generated: {numbers}")
    
    # Envía los números al proceso principal para la suma inicial
    pipe.send(numbers)
    pipe.close()

# Función que simula un consumidor que suma los números de la cola
def consumer(queue, pipe, consumer_id):
    print(f"\nConsumer {consumer_id} start...")
    nums_received = []
    total_sum = 0
    
    while True:
        try:
            number = queue.get(timeout=3)  # Recibe números de la cola
            nums_received.append(number)
            total_sum += number  # Suma los números
        except multiprocessing.queues.Empty:
            break  # Sale si la cola está vacía y no llegan más números
    
    print(f"\nConsumer {consumer_id}: Calculated the numbers {nums_received}. Sum: {total_sum} \n ")
    pipe.send(total_sum)  # Envía la suma al proceso principal
    pipe.close()

if __name__ == "__main__":

    num_producers = int(input("Productores: "))  # Cantidad de productores
    cant_nums_per_producer = int(input("Cantidad de numeros por productor: "))  # Cantidad de números a generar por productor
    num_consumers = int(input("Consumidores: "))  # Cantidad de consumidores

    print(f"Productores: {num_producers}") 
    print(f"Cantidad de numeros por productor: {cant_nums_per_producer}")
    print(f"Consumidores: {num_consumers}")

    # Cola compartida entre productores y consumidores
    queue = multiprocessing.Queue()

    # Lista para almacenar los pipes y procesos
    producer_pipes = []
    consumer_pipes = []
    producer_processes = []
    consumer_processes = []

    # Variable para la suma inicial de los números recibidos de los productores
    main_sum = 0

    # Crear y lanzar los procesos productores
    for i in range(num_producers):
        producer_pipe_parent, producer_pipe_child = multiprocessing.Pipe()
        process = multiprocessing.Process(target=producer, args=(queue, producer_pipe_child, i + 1))
        producer_pipes.append(producer_pipe_parent)
        producer_processes.append(process)
        process.start()
        
        # El proceso principal envía la cantidad de números a generar a través del pipe
        producer_pipe_parent.send(cant_nums_per_producer)

    # Recibir los números de los productores y calcular la suma inicial
    for producer_pipe in producer_pipes:
        generated_numbers = producer_pipe.recv()  # Recibe los números generados por el productor
        print(f"Main: Received numbers from producer: {generated_numbers}")
        main_sum += sum(generated_numbers)  # Suma los números recibidos

    print(f"\nMain: Sum of numbers before consumers: {main_sum}")

    # Crear y lanzar los procesos consumidores
    for i in range(num_consumers):
        consumer_pipe_parent, consumer_pipe_child = multiprocessing.Pipe()
        process = multiprocessing.Process(target=consumer, args=(queue, consumer_pipe_child, i + 1))
        consumer_pipes.append(consumer_pipe_parent)
        consumer_processes.append(process)
        process.start()

    # Recibir las sumas de los consumidores
    total_sum_by_consumers = 0
    for consumer_pipe in consumer_pipes:
        consumer_sum = consumer_pipe.recv()  # Recibe la suma de cada consumidor
        total_sum_by_consumers += consumer_sum

    # Imprimir la suma total calculada por los consumidores
    print(f"\nMain: Total sum by consumers: {total_sum_by_consumers}")

    # Comparar los resultados
    if main_sum == total_sum_by_consumers:
        print("\nMain: The sum matches! Both methods calculated the same result.")
    else:
        print("\nMain: The sums do not match! There might be a discrepancy.")

    # Esperar a que todos los procesos terminen
    for process in producer_processes + consumer_processes:
        process.join()
