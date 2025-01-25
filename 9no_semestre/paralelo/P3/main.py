"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""
from PIL import Image
import cv2
import numpy as np
import os
from multiprocessing import Process, Queue, Pipe
import time
import matplotlib.pyplot as plt


# ------------------- Funciones de filtros -------------------

def grayscale_conversion(image):
    return image.convert("L")

def edge_detection(image):
    image_np = np.array(image)
    gray = cv2.cvtColor(image_np, cv2.COLOR_RGB2GRAY)
    edges = cv2.Canny(gray, 100, 200)
    return Image.fromarray(edges)

def blur(image):
    ksize = 31
    image_np = np.array(image)
    blurred = cv2.GaussianBlur(image_np, (ksize, ksize), 0)
    return Image.fromarray(blurred)

# ------------------- Funciones de proceso -------------------

def read_image(images_path, queue_in):
    """Lee las imágenes del directorio y las pasa a la cola del primer filtro."""
    for image_file in os.listdir(images_path):
        image_path = os.path.join(images_path, image_file)
        if image_file.endswith(('.png', '.jpg', '.jpeg')):
            print(f"Image Reader: Reading {image_file}...")
            image = Image.open(image_path)
            queue_in.put((image, image_file))  # Enviar la imagen original a la primera cola

    # Señal de finalización
    queue_in.put(None)

def process_and_save_image(queue_in, queue_out, treatment_func, output_dir, treatment_key):
    """Procesa la imagen con el filtro correspondiente y guarda la imagen procesada directamente."""
    os.makedirs(output_dir, exist_ok=True)
    
    while True:
        item = queue_in.get()
        if item is None:
            if queue_out:
                queue_out.put(None)
            break
        image, image_file = item
        print(f"Image Processor [{treatment_key}] processing and saving {image_file}")
        
        # Procesamos y guardamos la imagen directamente
        processed_image = treatment_func(image)
        output_file = os.path.join(output_dir, f"processed_{image_file}")
        processed_image.save(output_file)
        
        # Pasar la imagen original al siguiente filtro, si hay uno
        if queue_out:
            queue_out.put((image, image_file))


def parallel_pipeline(images_path):
    output_dir = "parallel_output_images"

    # Crear colas para conectar los procesos en serie
    queue_grayscale = Queue()
    queue_edges = Queue()
    queue_blur = Queue()

    # Proceso de lectura de imágenes
    reader_process = Process(target=read_image, args=(images_path, queue_grayscale))
    reader_process.start()

    # Procesos de filtros en serie
    grayscale_process = Process(target=process_and_save_image, args=(queue_grayscale, queue_edges, grayscale_conversion, os.path.join(output_dir, "grayscale-conversion"), "grayscale-conversion"))
    edges_process = Process(target=process_and_save_image, args=(queue_edges, queue_blur, edge_detection, os.path.join(output_dir, "edge-detection"), "edge-detection"))
    blur_process = Process(target=process_and_save_image, args=(queue_blur, None, blur, os.path.join(output_dir, "blurring"), "blurring"))

    # Iniciar los procesos de filtrado
    grayscale_process.start()
    edges_process.start()
    blur_process.start()

    # Esperar que todos los procesos terminen
    reader_process.join()
    grayscale_process.join()
    edges_process.join()
    blur_process.join()

    print("Pipeline completado.")

def serial_pipeline(images_path):
    output_dir = "serial_output_images"
    
    # Crear los subdirectorios si no existen
    os.makedirs(os.path.join(output_dir, "grayscale-conversion"), exist_ok=True)
    os.makedirs(os.path.join(output_dir, "edge-detection"), exist_ok=True)
    os.makedirs(os.path.join(output_dir, "blurring"), exist_ok=True)

    # Leer imágenes
    for image_file in os.listdir(images_path):
        image_path = os.path.join(images_path, image_file)
        if image_file.endswith(('.png', '.jpg', '.jpeg')):
            print(f"Image Reader: Reading {image_file}...")
            image = Image.open(image_path)

            # Procesamos cada imagen con el filtro correspondiente
            print(f"Grayscale Image Writer")
            grayscale_image = grayscale_conversion(image)
            print(f"Edge Image Writer")
            edge_image = edge_detection(image)
            print(f"Blur Image Writer")
            blur_image = blur(image)

            # Guardamos las imágenes procesadas en sus respectivos subdirectorios
            grayscale_image.save(os.path.join(output_dir, "grayscale-conversion", f"processed_{image_file}"))
            edge_image.save(os.path.join(output_dir, "edge-detection", f"processed_{image_file}"))  
            blur_image.save(os.path.join(output_dir, "blurring", f"processed_{image_file}"))

# ------------------- Programa Principal -------------------

if __name__ == "__main__":
    images_path = "images"

    # ejecutamos la version paralela
    print("\n Ejecutando la versión paralela...")
    time_start = time.time()
    parallel_pipeline(images_path)
    time_end = time.time()
    time_parallel = time_end - time_start
    print(f"Tiempo total: {time_parallel} segundos")

    # ejecutamos en serie
    print("\n Ejecutando la versión en serie...")
    time_start = time.time()
    serial_pipeline(images_path)
    time_end = time.time()
    time_serial = time_end - time_start
    print(f"Tiempo total: {time_serial} segundos")

    # grafico comprarativo de tiempos
    print("Mostrando gráfico de tiempos...")
    labels = ['Paralelo', 'Serie']
    times = [time_parallel, time_serial]

    plt.figure(figsize=(8, 6))
    plt.bar(labels, times, color=['skyblue', 'salmon'])
    plt.ylabel('Tiempo (segundos)')
    plt.title('Comparación de Tiempos de Ejecución')
    plt.show()

"""
El uso del pipeline paralelo mejora la paralelización del proceso de tratamiento de imágenes en comparación con el enfoque serial porque permite ejecutar varias etapas de procesamiento de forma concurrente, lo que reduce significativamente el tiempo total de ejecución. En el enfoque serial, cada imagen debe pasar por todos los filtros de forma secuencial (primero el filtro de escala de grises, luego detección de bordes y finalmente el desenfoque), lo que genera tiempos de espera acumulados entre cada filtro. Sin embargo, en la implementación paralela, los procesos de cada filtro se ejecutan de manera independiente, lo que aprovecha los recursos del sistema de manera más eficiente y permite que las imágenes se procesen más rápidamente, en paralelo, en lugar de esperar que se termine el procesamiento de una imagen en cada paso antes de pasar al siguiente filtro. Como resultado, la versión paralela puede manejar grandes cantidades de imágenes con una mejora significativa en el tiempo de ejecución.
"""


   
