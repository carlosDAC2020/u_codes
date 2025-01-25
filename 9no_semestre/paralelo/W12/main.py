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
from reportlab.lib.pagesizes import letter
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle
from reportlab.platypus import Image as RLImage
from reportlab.lib.units import inch

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

def process_image(queue_in, queue_out, queue_save, treatment_func, treatment_key, pipe_conn):
    """Procesa la imagen con el filtro correspondiente y la envía a la cola siguiente y de guardado."""
    while True:
        item = queue_in.get()
        if item is None:
            # Señal de finalización para las colas posteriores
            if queue_out:
                queue_out.put(None)
            queue_save.put(None)  # Señal de finalización para el guardado
            break
        image, image_file = item
        print(f"Image Processor [{treatment_key}] processing {image_file}")
        
        # Medir el tiempo de procesamiento
        start_time = time.time()
        processed_image = treatment_func(image)
        end_time = time.time()
        processing_time = end_time - start_time
        

        # Enviar los datos al proceso principal a través del pipe
        pipe_conn.send({
            "image_file": image_file,
            "filter": treatment_key,
            "processing_time": processing_time
        })

        # Enviar la imagen procesada al proceso de guardado
        queue_save.put((processed_image, image_file))

        # Enviar la imagen original (sin procesar) al siguiente filtro si hay un siguiente
        if queue_out:
            queue_out.put((image, image_file))

def save_image(queue_save, output_dir, treatment_key):
    """Guarda las imágenes procesadas por cada filtro en una carpeta específica."""
    output_path = os.path.join(output_dir, treatment_key)
    os.makedirs(output_path, exist_ok=True)

    while True:
        item = queue_save.get()
        if item is None:
            break
        processed_image, image_file = item
        output_file = os.path.join(output_path, f"processed_{image_file}")
        print(f"Image Writer [{treatment_key}] saving {image_file}")
        processed_image.save(output_file)

# -------------------- Generación de reporte -------------------
def generate_report(report, images_path, output_dir):
    # obtener infirmacion de las imagenes procesadas 
    rep = {}
    images = [entry['image_file'] for entry in report]
    images = list(set(images))
    
    for image in images:
         # tamaño original de la imagen
        image_path = os.path.join(images_path, image)
        image_size = os.path.getsize(image_path)
        rep[image] = {"original_size": image_size}
        for filter in ["grayscale-conversion", "edge-detection", "blurring"]:
            # tamaño de la imagen procesada y tiempo de ejecucion por cada tipo de filtro
            filter_path = os.path.join(output_dir, filter, f"processed_{image}")
            filter_size = os.path.getsize(filter_path)
            rep[image][filter] = {"processed_size": filter_size}
            for entry in report:
                if entry["image_file"] == image and entry["filter"] == filter:
                    rep[image][filter]["processing_time"] = entry["processing_time"]

    # mostrar los resultados en consola
    i=1
    for img, results in rep.items():
        print(f"\n Imagen: {img}")
        for filt, result in results.items():
            if filt == "original_size":
                print(f" Tamaño original: {result} ")
            else:
                print(f" Filtro: {filt}")
                print(f"  Tamaño: {result['processed_size']} Bytes")
                print(f"  Tiempo: {result['processing_time']} segundos")
        rep[img]["alias"] = f"img_{i}"
        i+=1
    print(f"\n{i} imágenes procesadas")

    return rep
            
# -------------------- Funciones para gráficas -------------------

def plot_processing_times(report, directorio):
    filters = ["grayscale-conversion", "edge-detection", "blurring"]
    processing_times = {filter: [] for filter in filters}
    aliases = []

    for img, results in report.items():
        aliases.append(results["alias"]) 
        for filter in filters:
            processing_times[filter].append(results[filter]["processing_time"])

    # Crear la gráfica de tiempos de procesamiento
    x = np.arange(len(aliases))  # el lugar donde se colocarán las barras
    width = 0.2  # el ancho de las barras

    plt.figure(figsize=(10, 6))

    for i, filter in enumerate(filters):
        plt.bar(x + i * width, processing_times[filter], width, label=filter)

    plt.title('Tiempos de procesamiento por filtro')
    plt.xlabel('Imágenes')
    plt.ylabel('Tiempo de procesamiento (segundos)')
    plt.xticks(x + width, aliases)  # ajustar las etiquetas en el eje x
    plt.legend()
    plt.grid(axis='y')  # solo líneas de cuadrícula en el eje y
    plt.tight_layout()

    # Guardar la gráfica en un directorio

    ruta_archivo = os.path.join(directorio, "tiempos_procesamiento.png")
    plt.savefig(ruta_archivo)
    plt.close()  # Cerrar la figura para liberar memoria


def plot_image_sizes(report, directorio):
    aliases = []
    original_sizes = []
    processed_sizes = {filter: [] for filter in ["grayscale-conversion", "edge-detection", "blurring"]}

    for img, results in report.items():
        aliases.append(results["alias"])  # Usar el alias aquí
        original_sizes.append(results["original_size"])
        for filter in processed_sizes.keys():
            processed_sizes[filter].append(results[filter]["processed_size"])

    # Crear la gráfica de tamaños de imágenes
    plt.figure(figsize=(10, 6))
    plt.bar(aliases, original_sizes, label='Tamaño original', alpha=0.6)
    
    for filter in processed_sizes.keys():
        plt.bar(aliases, processed_sizes[filter], label=filter, alpha=0.6)

    plt.title('Tamaño de imágenes originales y procesadas')
    plt.xlabel('Imágenes')
    plt.ylabel('Tamaño (Bytes)')
    plt.xticks(rotation=45)
    plt.legend()
    plt.grid()
    plt.tight_layout()

    # Guardar la gráfica en un directorio
    ruta_archivo = os.path.join(directorio, "tamanos_imagenes.png")
    plt.savefig(ruta_archivo)
    plt.close()


# ------------------- Función para crear el informe en PDF -------------------
def create_pdf_report(report_dict, images_path, output_dir):
    pdf_path = os.path.join(output_dir, "informe_experimento.pdf")
    doc = SimpleDocTemplate(pdf_path, pagesize=letter)
    styles = getSampleStyleSheet()
    Story = []

    # Título y descripción del experimento
    title = Paragraph("Informe del Experimento de Procesamiento de Imágenes", styles['Title'])
    description = Paragraph("Este informe detalla el experimento realizado para procesar imágenes mediante diferentes filtros y analiza los resultados obtenidos.", styles['BodyText'])
    Story.append(title)
    Story.append(Spacer(1, 12))
    Story.append(description)
    Story.append(Spacer(1, 24))

    # Metodología
    methodology = Paragraph(
        "Metodología: "
        "Se utilizó un pipeline de procesamiento de imágenes que incluye tres filtros: "
        "conversión a escala de grises, detección de bordes y desenfoque. "
        "Cada imagen original pasa por estos filtros en secuencia, y se registra el tiempo de procesamiento y el tamaño de las imágenes resultantes. "
        "Los pasos del proceso son los siguientes: "
        "1. Conversión a escala de grises: Esta transformación se realiza para simplificar la información de color, permitiendo un análisis más eficiente. "
        "2. Detección de bordes: Este filtro resalta las estructuras significativas en la imagen, ayudando en la identificación de contornos y formas. "
        "3. Desenfoque: Se aplica un desenfoque para suavizar la imagen y reducir el ruido. "
        "El tiempo de procesamiento de cada filtro y el tamaño de la imagen resultante se registran para el análisis posterior.",
        styles['BodyText']
    )
    Story.append(methodology)
    Story.append(Spacer(1, 24))


    # Análisis
    Story.append(Paragraph("Análisis:", styles['Heading2']))
    # Tabla con información básica de las imágenes procesadas
    data = [["Nombre de la Imagen", "Tamaño Original (Bytes)"]]
    for img, results in report_dict.items():
        data.append([img, results["original_size"]])
    
    table = Table(data)
    table.setStyle(TableStyle([('BACKGROUND', (0, 0), (-1, 0), colors.grey),
                                ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
                                ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                                ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                                ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
                                ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
                                ('GRID', (0, 0), (-1, -1), 1, colors.black)]))
    Story.append(table)
    Story.append(Spacer(1, 24))

    # Análisis de la primera gráfica
    first_graph_image_path = os.path.join(output_dir, "tiempos_procesamiento.png")  # Asegúrate de que la gráfica se guarde aquí
    first_graph_description = Paragraph("La primera gráfica muestra los tiempos de procesamiento para cada filtro aplicado a las imágenes. Se puede observar que el filtro de desenfoque requiere más tiempo en comparación con los otros filtros.", styles['BodyText'])
    Story.append(Paragraph("Análisis de la Primera Gráfica:", styles['Heading2']))
    Story.append(RLImage(first_graph_image_path, width=5*inch, height=3*inch))  # Ajusta el tamaño según sea necesario
    Story.append(first_graph_description)
    Story.append(Spacer(1, 24))

    # Análisis de la segunda gráfica
    second_graph_image_path = os.path.join(output_dir, "tamanos_imagenes.png")  # Asegúrate de que la gráfica se guarde aquí
    second_graph_description = Paragraph("La segunda gráfica ilustra los tamaños de las imágenes originales y procesadas, permitiendo una comparación visual de la eficiencia del procesamiento de cada filtro.", styles['BodyText'])
    Story.append(Paragraph("Análisis de la Segunda Gráfica:", styles['Heading2']))
    Story.append(RLImage(second_graph_image_path, width=5*inch, height=3*inch))  # Ajusta el tamaño según sea necesario
    Story.append(second_graph_description)
    Story.append(Spacer(1, 24))

    # Conclusiones
    conclusions = Paragraph("A partir de los resultados observados, se concluye que cada filtro tiene un impacto significativo en el tiempo de procesamiento y el tamaño de las imágenes. La optimización de estos filtros puede mejorar la eficiencia general del pipeline.", styles['BodyText'])
    Story.append(Paragraph("Conclusiones:", styles['Heading2']))
    Story.append(conclusions)

    # Generar el PDF
    doc.build(Story)
    print(f"Informe generado: {pdf_path}")

# ------------------- Programa Principal -------------------

if __name__ == "__main__":
    images_path = "images"
    output_dir = "output_images"

    # Lista para almacenar los tiempos de procesamiento y otros detalles
    report = []

    # Crear colas para conectar los procesos en serie y los procesos de guardado
    queue_grayscale = Queue()
    queue_edges = Queue()
    queue_blur = Queue()

    queue_save_grayscale = Queue()
    queue_save_edges = Queue()
    queue_save_blur = Queue()

    # Crear pipes para recibir resultados de los procesos
    parent_conn_grayscale, child_conn_grayscale = Pipe()
    parent_conn_edges, child_conn_edges = Pipe()
    parent_conn_blur, child_conn_blur = Pipe()

    # Proceso de lectura de imágenes
    reader_process = Process(target=read_image, args=(images_path, queue_grayscale))
    reader_process.start()

    # Procesos de filtros en serie (imagen original pasa al siguiente filtro)
    grayscale_process = Process(target=process_image, args=(queue_grayscale, queue_edges, queue_save_grayscale, grayscale_conversion, "grayscale-conversion", child_conn_grayscale))
    edges_process = Process(target=process_image, args=(queue_edges, queue_blur, queue_save_edges, edge_detection, "edge-detection", child_conn_edges))
    blur_process = Process(target=process_image, args=(queue_blur, None, queue_save_blur, blur, "blurring", child_conn_blur))

    # Procesos de guardado de imágenes (por cada filtro)
    save_grayscale_process = Process(target=save_image, args=(queue_save_grayscale, output_dir, "grayscale-conversion"))
    save_edges_process = Process(target=save_image, args=(queue_save_edges, output_dir, "edge-detection"))
    save_blur_process = Process(target=save_image, args=(queue_save_blur, output_dir, "blurring"))

    # Iniciar los procesos de filtrado y guardado
    grayscale_process.start()
    edges_process.start()
    blur_process.start()

    save_grayscale_process.start()
    save_edges_process.start()
    save_blur_process.start()

    # Esperar que todos los procesos terminen
    reader_process.join()
    grayscale_process.join()
    edges_process.join()
    blur_process.join()

    save_grayscale_process.join() 
    save_edges_process.join()
    save_blur_process.join()

    # Recibir los datos de los pipes y generar el reporte
    while parent_conn_grayscale.poll():
        report.append(parent_conn_grayscale.recv())

    while parent_conn_edges.poll():
        report.append(parent_conn_edges.recv())

    while parent_conn_blur.poll():
        report.append(parent_conn_blur.recv())

    # Generar y mostrar el informe
    report_dict = generate_report(report, images_path, output_dir)
    
     # Mostrar gráficas
    plot_processing_times(report_dict, output_dir)
   

    plot_image_sizes(report_dict, output_dir)
    

    # Crear el informe en PDF
    create_pdf_report(report_dict, images_path, output_dir)
    
   

    print("Pipeline completado.")
