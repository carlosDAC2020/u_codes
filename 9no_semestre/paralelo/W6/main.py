"""
    Estudiante
    - Carlos Daniel Agamez Palomino T00059006
"""

import os
import time
import threading
import numpy as np
from reportlab.lib.pagesizes import letter, inch
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle
from reportlab.platypus import Image as RLImage
import io

# Función para multiplicar subconjuntos de filas
def multiply_subset(start, end, A, B, result):
    for i in range(start, end):
        result[i] = np.dot(A[i], B)

# Función para dividir la matriz entre hilos
def parallel_multiply(A, B, num_workers, with_join):
    n = A.shape[0]
    result = np.zeros((n, n))
    threads = []
    
    # Calcular cuántas filas asignar a cada hilo
    step = n // num_workers
    for i in range(num_workers):
        start = i * step
        # El último hilo se encarga del resto de las filas
        end = (i + 1) * step if i != num_workers - 1 else n
        thread = threading.Thread(target=multiply_subset, args=(start, end, A, B, result))
        threads.append(thread)
        thread.start()
    
    # Esperar que todos los hilos terminen
    if with_join:
        for thread in threads:
            thread.join()

    return result

# Función para medir el tiempo de ejecución
def measure_time(func, *args):
    start_time = time.time()
    result = func(*args)
    end_time = time.time()
    return result, end_time - start_time


# funcion para generar reporte de ejecucion 
def generate_report(results):
    print("\nCreando reporte...")

    # Crear el documento PDF
    doc = SimpleDocTemplate("reporte_multiplicacion_matrices.pdf", pagesize=letter, leftMargin=inch/2, rightMargin=inch/2, topMargin=inch/2, bottomMargin=inch/2)
    elements = []

    # Estilos de fuente
    styles = getSampleStyleSheet()
    estilo_titulo = styles['Title']
    estilo_parrafo = ParagraphStyle(
        'BodyTextLarge', 
        parent=styles['BodyText'], fontSize=14, leading=18, spaceAfter=12, textColor=colors.black)
    estilo_subtitulo = ParagraphStyle('Subtitulo', parent=styles['Heading2'], spaceAfter=14, textColor=colors.black)

    # Título del reporte
    titulo = Paragraph("Paralelización de Multiplicación de Matrices", estilo_titulo)
    elements.append(titulo)
    elements.append(Spacer(1, 12))

    # Introducción
    parrafo_intro = Paragraph(
        "Este informe detalla el proceso de paralelización en la multiplicación de matrices utilizando distintos números de hilos. "
        "Se ha comparado el tiempo de ejecución de la operación de multiplicación tanto en forma serial como en paralelo, "
        "además de analizar el impacto de utilizar 'join' en los hilos. El objetivo es evaluar la eficiencia del procesamiento paralelo "
        "en función de los recursos disponibles del sistema.",
        estilo_parrafo
    )
    elements.append(parrafo_intro)
    elements.append(Spacer(1, 12))

    # Metodología
    subtitulo_metodologia = Paragraph("Metodología", estilo_subtitulo)
    elements.append(subtitulo_metodologia)
    parrafo_metodologia = Paragraph(
        "El experimento se realizó en un equipo con {} núcleos. Se generaron matrices de tamaño 1000x1000 para las pruebas. "
        "Se realizaron operaciones de multiplicación de matrices utilizando diferentes números de hilos, tanto en modo paralelo "
        "con 'join' y sin 'join'. Se compararon los tiempos de ejecución y se calculó el speed up obtenido al usar múltiples hilos en comparación "
        "con un solo hilo.".format(results["num_cores"]),
        estilo_parrafo
    )
    elements.append(parrafo_metodologia)
    elements.append(Spacer(1, 12))
    
    del results["num_cores"]

    # Análisis
    subtitulo_analisis = Paragraph("Análisis", estilo_subtitulo)
    elements.append(subtitulo_analisis)

    parrafo_analisis_intro = Paragraph(
        "A continuación se presentan los resultados obtenidos para cada método de paralelización. Los datos incluyen los tiempos de ejecución "
        "en segundos y el speed up calculado para diferentes números de hilos. También se muestran las matrices resultantes para verificar su "
        "igualdad en función del método utilizado.",
        estilo_parrafo
    )
    elements.append(parrafo_analisis_intro)
    elements.append(Spacer(1, 12))

    # Crear tablas de resultados
    for join, info in results.items():
        
        subtitulo = Paragraph(f"Resultados {'join' if join == 'con join' else 'sin join'}", estilo_subtitulo)
        elements.append(subtitulo)

        data_table = Table([
            ["Número de Hilos", "Tiempo Serial (s)", "Tiempo Paralelo (s)", "Speed Up"],
            ["1", f"{info['times'][0]:.6f}", f"{info['times'][1]:.6f}", f"{info['speed_up']:.3f}"]
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
        elements.append(Spacer(1, 12))

        # Agregar matrices resultantes
        for idx, result in enumerate(info['result_matrices']):
            type_validation = "Serial" if idx == 0 else "Paralela"
            parrafo_matriz = Paragraph(f"<b>Resultado de forma {type_validation}:</b>", estilo_parrafo)
            elements.append(parrafo_matriz)

            # Convertir la matriz a cadena de texto
            matrix_str = np.array_str(result)
            parrafo_matriz = Paragraph(matrix_str, estilo_parrafo)
            elements.append(parrafo_matriz)

        # Verificar igualdad de matrices
        if np.array_equal(info['result_matrices'][0], info['result_matrices'][1]):
            conclusion = "Las matrices resultantes son iguales."
        else:
            conclusion = "Las matrices resultantes son diferentes."
        elements.append(Paragraph(conclusion, estilo_parrafo))
        elements.append(Spacer(1, 24))

    # Conclusiones generales
    subtitulo_conclusiones = Paragraph("Conclusiones", estilo_subtitulo)
    elements.append(subtitulo_conclusiones)
    parrafo_conclusiones = Paragraph(
    "El análisis de los resultados de la paralelización de la multiplicación de matrices muestra que el uso de la sincronización adecuada entre hilos, "
    "como el join, es crucial para lograr un rendimiento óptimo y resultados precisos. La paralelización con join mejora significativamente el tiempo de "
    "ejecución en comparación con la ejecución serial y asegura la precisión de los resultados al mantener la coherencia entre los hilos. En contraste, la falta "
    "de join puede llevar a resultados incorrectos y una disminución del rendimiento, evidenciado por resultados erróneos y tiempos de ejecución menos eficientes. "
    "Estos hallazgos subrayan la importancia de una correcta sincronización en la programación paralela para garantizar tanto la eficiencia como la exactitud en el procesamiento de datos.",
    estilo_parrafo)
    elements.append(parrafo_conclusiones)

    # Generar el documento PDF
    doc.build(elements)
    print("Reporte generado: reporte_multiplicacion_matrices.pdf")

if __name__ == "__main__":
    num_cores = os.cpu_count()
    n = 1000  # Tamaño de la matriz

    print("tamaño de matrices: ",n)
    # Crear matrices aleatorias
    print("generando matrices")
    matrixA = np.random.randint(1, 101, size=(n, n))  
    matrixB = np.random.randint(1, 101, size=(n, n))  
    print("---")
    # Almacenar resultados para validarlos después
    results = {
        "con join":{
            "times":[],
            "speed_up":0,
            "result_matrices":[]
        },
        "sin join":{
            "times":[],
            "speed_up":0,
            "result_matrices":[]
        },
    }
    for join, info in results.items():  
        with_join = True if join == "con join" else False
        print(f"\n Realizando operaciones {join}")
        # Multiplicación con diferentes cantidades de hilos
        for workers in [1, num_cores * 4]:  
            parallel_result, parallel_time = measure_time(parallel_multiply, matrixA, matrixB, workers, with_join)
            print(f"Tiempo con {workers} hilos: {parallel_time:.6f} segundos")
            # vamos guardando los resultados 
            info["result_matrices"].append(parallel_result)  
            info["times"].append(parallel_time)
        
        # obtenemos el speed up 
        info["speed_up"] =  info["times"][0] / info["times"][1]
        print(f" Spedd up obtenido de : {info['speed_up']:.3f}")

        # imprimimos las matrices resultantes de los 2 procesos
        type_validation="serial"
        for result in info["result_matrices"]:
            print(f"\nResultado de forma {type_validation} hilos:\n{result}")
            type_validation="paralela"

        # validamos la igyaldad de la matriz generada 
        if np.array_equal(info["result_matrices"][0], info["result_matrices"][1]):
            print(f"Las matrices resultantes son iguales.")
        else:
            print(f"Las matrices resultantes son diferentes.")

    # generaos reporte final de ejecucion 
    print("generando reporte de ejecucion....")
    results["num_cores"] = num_cores
    generate_report(results)
        
