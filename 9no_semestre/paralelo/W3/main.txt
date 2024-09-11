"""
    Estudiante 
        Carlos Daniel Agamez Palomino T00059006
"""

# Instalar las librerías necesarias:
# pip install pillow opencv-python-headless reportlab numpy

from PIL import Image, ImageDraw
import cv2
import numpy as np
from reportlab.lib.pagesizes import letter
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import inch
from reportlab.platypus import SimpleDocTemplate, Paragraph, Table, TableStyle, Image as RLImage, Spacer
from reportlab.lib import colors
import threading
import time
import os
import io


# funciones para el tratamiento de las imagenes --------------------------------------

# pasar imagen a escala de grises 
def grayscale_conversion(image):
    return image.convert("L")

# identificador de bordes o contrastes 
def edge_detection(image):
    # Convertir imagen PIL a arreglo numpy
    image_np = np.array(image)
    
    # Convertir la imagen a escala de grises
    gray = cv2.cvtColor(image_np, cv2.COLOR_RGB2GRAY)
    
    # Aplicar el detector de bordes de Canny
    edges = cv2.Canny(gray, 100, 200)
    
    # Convertir el arreglo numpy de vuelta a imagen PIL
    return Image.fromarray(edges)

# aplicar desenfoque a la imagen
def blur(image):
    
    # controla el tamaño del kernel utilizado en el desenfoque gaussiano aplicado a la imagen
    ksize=201

    # Convertir imagen PIL a arreglo numpy
    image_np = np.array(image)

    # Aplicar desenfoque gaussiano
    blurred = cv2.GaussianBlur(image_np, (ksize, ksize), 0)

    # Convertir el arreglo numpy de vuelta a imagen PIL
    blurred_image = Image.fromarray(blurred)

    return blurred_image

# Manejador de tratamientos de imágenes
treatments = {
    "grayscale-conversion": grayscale_conversion,  # Función para convertir la imagen a escala de grises.
    "edge-detection": edge_detection,  # Función para detectar bordes en la imagen.
    "blurring": blur  # Función para aplicar desenfoque gaussiano a la imagen.
}

# Reporte de resultados de tiempos de ejecución
report = {
    "grayscale-conversion": {
        "threads": [],  # Lista para almacenar el número de hilos utilizados en las pruebas.
        "times": [],  # Lista para almacenar los tiempos de ejecución (en segundos) para cada prueba.
        "speedUp": 0,  # Factor de aceleración que compara el tiempo de ejecución en paralelo con el tiempo de ejecución secuencial.
        "image-return": ""  # bufer con la imagen retornada del tratamiento en cuestion 
    },
    "edge-detection": {
        "threads": [],  
        "times": [],  
        "speedUp": 0,  
        "image-return": "" 
    },
    "blurring": {
        "threads": [],  
        "times": [], 
        "speedUp": 0, 
        "image-return": "" 
    }
}

# funciones para el procesamiento en paralelo de las imagenes -----------------------------

# divion de la imagen segun la cantidad de hilos a disponer 
def divide_image(image, num_workers):
    width, height = image.size
    chunk_height = height // num_workers
    chunks = []

    for i in range(num_workers):
        start_y = i * chunk_height
        end_y = (i + 1) * chunk_height if i != num_workers - 1 else height
        chunks.append((0, start_y, width, end_y))
    
    return chunks


# Generar una imagen que muestra cómo se divide la imagen original
def create_division_image(image, chunks):
    image_with_divisions = image.copy()
    draw = ImageDraw.Draw(image_with_divisions)
    
    for chunk in chunks:
        draw.line([(0, chunk[1]), (image.size[0], chunk[1])], fill=(255, 0, 0), width=10)
    
    # Guardar en un buffer en lugar de archivo
    buffer = io.BytesIO()
    image_with_divisions.save(buffer, format="JPEG")
    buffer.seek(0)
    return buffer


def process_chunk(image, chunk, treatment, result_image, lock):
    """
    Procesa una sección (chunk) de la imagen aplicando un tratamiento específico y combina el resultado en la imagen de salida.

    Args:
        image (PIL.Image.Image): Imagen original que se va a dividir en partes.
        chunk (tuple): Tupla que define una región de la imagen en formato (left, top, right, bottom).
        treatment (function): Función que aplica el tratamiento deseado a la imagen.
        result_image (PIL.Image.Image): Imagen que almacenará el resultado del procesamiento.
        lock (threading.Lock): Objeto de bloqueo para sincronizar el acceso a la imagen de resultado entre hilos.

    Description:
        La función extrae un segmento de la imagen original, aplica el tratamiento especificado y luego combina el resultado en la imagen final.
        El uso del bloqueo garantiza que solo un hilo acceda y modifique la imagen de resultado a la vez.
    """
    segment = image.crop(chunk)  # Extraer la sección de la imagen definida por chunk
    processed_segment = treatment(segment)  # Aplicar el tratamiento a la sección
    
    with lock:  # Sincronizar el acceso a la imagen de resultado
        result_image.paste(processed_segment, (0, chunk[1]))  # Pegar el segmento procesado en la posición correcta


def parallel_image_processing(image, num_workers, treatment, treatment_type):
    """
    Procesa una imagen en paralelo aplicando un tratamiento específico y calcula el tiempo de ejecución.

    Args:
        image (PIL.Image.Image): Imagen original a procesar.
        num_workers (int): Número de hilos a utilizar para el procesamiento paralelo.
        treatment (function): Función que aplica el tratamiento deseado a la imagen.
        treatment_type (str): Tipo de tratamiento que se está aplicando (usado para registrar y guardar el resultado).

    Returns:
        io.BytesIO: Buffer que contiene la imagen procesada en formato JPEG.
    
    Description:
        La función divide la imagen en partes iguales según el número de hilos, procesa cada parte en paralelo y combina los resultados.
        Calcula el tiempo de ejecución total y guarda la imagen procesada en un buffer en lugar de un archivo.
        Los resultados de tiempo de ejecución se almacenan en el reporte para análisis posterior.
    """
    start_time = time.time()  # Registrar el tiempo de inicio

    width, height = image.size  # Obtener las dimensiones de la imagen
    chunks = divide_image(image, num_workers)  # Dividir la imagen en partes según el número de hilos
    
    # Crear una nueva imagen para almacenar el resultado
    if treatment_type == "blurring":
        result_image = Image.new("RGB", (width, height))  # Imagen en color para el desenfoque
    else:
        result_image = Image.new("L", (width, height))  # Imagen en escala de grises para otros tratamientos
    
    lock = threading.Lock()  # Crear un objeto de bloqueo para sincronizar el acceso
    threads = []  # Lista para almacenar los hilos

    # Procesar cada sección en paralelo
    for chunk in chunks:
        thread = threading.Thread(target=process_chunk, args=(image, chunk, treatment, result_image, lock))
        threads.append(thread)
        thread.start()

    # Esperar a que todos los hilos completen su trabajo
    for thread in threads:
        thread.join()
    
    end_time = time.time()  # Registrar el tiempo de finalización
    execution_time = end_time - start_time  # Calcular el tiempo de ejecución

    # Guardar el resultado en un buffer en lugar de un archivo
    buffer = io.BytesIO()
    result_image.save(buffer, format="JPEG")
    buffer.seek(0)

    # Guardar los tiempos de ejecución en el reporte
    report[treatment_type]["times"].append(round(execution_time, 4))
    report[treatment_type]["threads"].append(num_workers)

    print(f'with {num_workers} workers took {execution_time:.2f} seconds')

    return buffer


# Función para crear el informe con la estructura especificada
def crear_report():
    print("\nCreando reporte...")

    # Crear el documento PDF
    doc = SimpleDocTemplate("reporte.pdf", pagesize=letter, leftMargin=inch/2, rightMargin=inch/2, topMargin=inch/2, bottomMargin=inch/2)
    elements = []

    # Estilos de fuente
    styles = getSampleStyleSheet()
    estilo_titulo = styles['Title']
    estilo_parrafo = ParagraphStyle(
    'BodyTextLarge', 
    parent=styles['BodyText'], fontSize=14, leading=18, spaceAfter=12, textColor=colors.black)
    estilo_subtitulo = ParagraphStyle('Subtitulo', parent=styles['Heading2'], spaceAfter=14, textColor=colors.black)

    titulo = Paragraph("Reporte de Tratamiento de Imágenes en Paralelo", estilo_titulo)
    elements.append(titulo)

    parrafo_intro = Paragraph("Este informe detalla el tratamiento de imágenes mediante diferentes métodos de procesamiento paralelo. Las imágenes fueron tratadas mediante conversión a escala de grises, detección de bordes y desenfoque. A continuación se presentan los resultados obtenidos para cada tratamiento.", estilo_parrafo)
    elements.append(parrafo_intro)

    # Metodología
    subtitulo_metodologia = Paragraph("Metodología", estilo_subtitulo)
    elements.append(subtitulo_metodologia)
    parrafo_metodologia = Paragraph(f"El script se ejecutó en un equipo con {report['num_cores']} núcleos. Las imágenes fueron procesadas en paralelo utilizando distintos números de hilos (workers) para comparar tiempos de ejecución. Se aplicaron los siguientes tratamientos: conversión a escala de grises, detección de bordes y desenfoque.", estilo_parrafo)
    elements.append(parrafo_metodologia)
    elements.append(Spacer(1, 12))
    # Análisis
    subtitulo_analisis = Paragraph("Análisis", estilo_subtitulo)
    elements.append(subtitulo_analisis)
    parrafo_analisis_intro = Paragraph(f"Para el analisis se tiene en cuenta que la imagen debe ser dividida en partes iguales segun el numero de hilos a trabajar que en nuestro caso seria {report['num_cores']*4} hilos, he aqui una imagen que ilustar esta divicion:", estilo_parrafo)
    elements.append(parrafo_analisis_intro)


    # Crear y agregar imagen de divisiones desde el buffer
    division_img_buffer = create_division_image(image, divide_image(image, report['num_cores']*4))
    division_img = RLImage(division_img_buffer, width=6*inch, height=4*inch)
    elements.append(division_img)
    elements.append(Spacer(1, 24))
    elements.append(Spacer(1, 24))
    

    # Descripciones de cada tratamiento
    descripciones_tratamientos = {
        "grayscale-conversion": "La conversión a escala de grises transforma la imagen a un formato donde sólo se representan tonos de gris, eliminando la información de color.",
        "edge-detection": "La detección de bordes resalta los contornos presentes en la imagen, permitiendo identificar las transiciones bruscas de color o brillo.",
        "blurring": "El desenfoque aplica un filtro que suaviza los detalles finos de la imagen, reduciendo el ruido y haciendo la imagen más borrosa."
    }

    # Iterar sobre cada tratamiento y generar una tabla con datos y comparación de imágenes
    for treatment_type in report.keys():
        if treatment_type != "num_cores":  # Ignorar la clave 'num_cores'
            
            # Título de la sección de cada tratamiento
            subtitulo = Paragraph(f"Tratamiento: {treatment_type.replace('-', ' ').capitalize()}", estilo_subtitulo)
            elements.append(subtitulo)

            # Descripción del tratamiento
            descripcion = descripciones_tratamientos.get(treatment_type, "Descripción no disponible.")
            parrafo_descripcion = Paragraph(descripcion, estilo_parrafo)
            elements.append(parrafo_descripcion)

            # Datos del tratamiento en una tabla
            data_table = Table([
                ["Tratamiento", "Tiempo Serial (s)", "Tiempo Paralelo (s)", "Speed Up"],
                [treatment_type.replace("-", " ").capitalize(),
                 f"{report[treatment_type]['times'][0]:.4f}",
                 f"{report[treatment_type]['times'][1]:.4f}",
                 f"{report[treatment_type]['speedUp']:.2f}"]
            ])
            data_table.setStyle(TableStyle([
                ('BACKGROUND', (0, 0), (-1, 0), colors.grey),
                ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
                ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
                ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
                ('GRID', (0, 0), (-1, -1), 1, colors.black),
            ]))
            elements.append(data_table)

            # Espacio antes de las imágenes
            elements.append(Spacer(1, 12))
    
            processed_img_buffer =  report[treatment_type]["image-return"]
            processed_img = RLImage(processed_img_buffer, width=5*inch, height=3*inch)
            elements.append(processed_img)

            # Espacio después de las imágenes
            elements.append(Spacer(1, 24))

    # Generar el documento PDF
    doc.build(elements)
    print("Reporte generado: reporte_imagenes.pdf")



if __name__ == "__main__":

    image_path = "nasa.jpg"
    image = Image.open(image_path)
    
    # Obtén el número de núcleos físicos
    num_cores = os.cpu_count()
    print(f"Número de núcleos (cores): {num_cores}")
    
    print(f"Tamaño de imagen: {image.size}")
    
    for treatment_type, treatment in treatments.items():
        print(f"\nTratamiento: {treatment_type}")
        saved = False  
        
        for num_workers in [1, num_cores*4]: 
            # Procesar la imagen en paralelo
            chunks = divide_image(image, num_workers)
            report[treatment_type]["image-return"] = parallel_image_processing(image, num_workers, treatment, treatment_type)
            
        
        # Calcular el speed up
        serial_time = report[treatment_type]["times"][0]
        parallel_time = report[treatment_type]["times"][1]
        speed_up = serial_time / parallel_time
        report[treatment_type]["speedUp"] = speed_up
        print("Speed Up:", speed_up)

    # guardamos el valor de la cantidad de cores para mostrarlos en el informe 
    report["num_cores"] = num_cores

    # generacion de imagen que ilustra el preprocesamiento echo a la imegen 
    division_image_path = create_division_image(image, chunks)

    # Generar reporte
    crear_report()

