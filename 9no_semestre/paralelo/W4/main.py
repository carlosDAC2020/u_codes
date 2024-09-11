"""
    Estudiante
    - Carlos Daniel Agamez Palomino T00059006
"""

import os
import random
import threading
import time
from io import BytesIO
import matplotlib.pyplot as plt
from reportlab.lib.pagesizes import A4
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Image
from reportlab.lib import colors
from reportlab.platypus import Table, TableStyle

# Función para calcular la suma de cuadrados en un subconjunto de números
def sum_of_squares(sublist, result, index, lock):
    local_sum = sum(x * x for x in sublist)
    with lock:
        result[index] = local_sum

# Función para dividir la lista en subconjuntos según el número de trabajadores
def divide_list(nums, num_workers):
    size_subset = len(nums) // num_workers
    subsets = [nums[i:i + size_subset] for i in range(0, len(nums), size_subset)]
    
    # Asegurarse de que el último subrango incluya los elementos restantes
    if len(subsets) > num_workers:
        subsets[-2].extend(subsets[-1])
        subsets.pop()
    
    return subsets

# Función para medir el tiempo de ejecución
def measure_time(func, *args):
    start_time = time.time()
    result = func(*args)
    end_time = time.time()
    return result, end_time - start_time

# Función paralela para calcular la suma de cuadrados usando hilos
def parallel_sum_of_squares(nums, num_workers):
    subsets = divide_list(nums, num_workers)
    result = [0] * num_workers
    threads = []
    lock = threading.Lock()

    for i in range(num_workers):
        thread = threading.Thread(target=sum_of_squares, args=(subsets[i], result, i, lock))
        threads.append(thread)
        thread.start()

    for thread in threads:
        thread.join()

    return sum(result)

# Reporte de resultados
report = {}

def generate_report(report, speedups):
    # Crear un documento PDF
    doc = SimpleDocTemplate("informe_ejecucion.pdf", pagesize=A4)
    elements = []

    # Estilos
    styles = getSampleStyleSheet()
    title_style = styles['Title']
    body_style = styles['BodyText']
    estilo_subtitulo = ParagraphStyle(
        'Subtitulo', parent=styles['Heading2'], spaceAfter=14, textColor=colors.black)

    # Título
    elements.append(Paragraph("Informe de Ejecución: Suma de Cuadrados Paralela", title_style))
    elements.append(Spacer(1, 12))

    # Descripción
    description = (
        "Este informe describe el proceso y los resultados de la ejecución de un script que calcula "
        "la suma de cuadrados de una lista de números utilizando una estrategia paralela con múltiples hilos. "
        "Se midió el tiempo de ejecución para diferentes números de hilos y se calculó el speedup correspondiente."
    )
    elements.append(Paragraph(description, body_style))
    elements.append(Spacer(1, 12))

    # Metodología
    methodology = (
        "El script divide una lista de números en subconjuntos y asigna a cada hilo la tarea de calcular la suma de "
        "cuadrados de un subconjunto. El tiempo de ejecución se midió para diferentes configuraciones de hilos "
        "(1, número de núcleos, 2 veces el número de núcleos, y 4 veces el número de núcleos)."
    )
    elements.append(Paragraph("Metodología", estilo_subtitulo))
    elements.append(Paragraph(methodology, body_style))
    elements.append(Spacer(1, 12))

    # Tiempo de ejecución secuencial
    secuencial_time = report["secuencial"]
    # numero de cores fisicos
    num_cores=report["cores"]
    elements.append(Paragraph(f"La ejecucion de este script se realizó en un pc con {num_cores}  cores."))
    elements.append(Paragraph(f"Tiempo de ejecución en modo secuencial: {secuencial_time:.4f} segundos", body_style))
    elements.append(Spacer(1, 12))

    # Análisis de Resultados
    elements.append(Paragraph("Análisis", estilo_subtitulo))
    analysis = "A continuación se presentan los tiempos de ejecución y el speedup calculado para cada configuración de hilos:"
    elements.append(Paragraph(analysis, body_style))
    elements.append(Spacer(1, 12))

    # Tabla de tiempos de ejecución y speedup
    data = [["Número de Hilos", "Tiempo de Ejecución (s)", "Speedup"]]
    execution_times = []

    for num_workers, speedup in speedups:
        time_execution = report[f"{num_workers} hilos"]
        data.append([str(num_workers), f"{time_execution:.4f}", f"{speedup:.4f}"])
        execution_times.append((num_workers, time_execution))

    table = Table(data)
    table.setStyle(TableStyle([
        ('BACKGROUND', (0, 0), (-1, 0), colors.grey),
        ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
        ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
        ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
        ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
        ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
    ]))
    elements.append(table)
    elements.append(Spacer(1, 12))

   
    workers, exec_times = zip(*execution_times)
    plt.plot(workers, exec_times, marker='o')
    plt.title("Tiempo de Ejecución vs Número de Hilos")
    secuential_time = report["secuencial"]
    plt.axhline(y=secuential_time, color='r', linestyle='--', label='Tiempo Secuencial')
    plt.xlabel("Número de Hilos")
    plt.ylabel("Tiempo de Ejecución (s)")
    plt.legend()
    plt.grid(True)
    buf = BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)
    plt.close()

    # Insertar la imagen en el PDF
    elements.append(Image(buf, width=400, height=300))
    elements.append(Spacer(1, 12))

    # Gráfico de Speedup usando un buffer en lugar de guardar la imagen
    workers, speedup_values = zip(*speedups)
    plt.plot(workers, speedup_values, marker='o')
    plt.title("Speedup vs Número de Hilos")
    plt.xlabel("Número de Hilos")
    plt.ylabel("Speedup")
    plt.grid(True)

    # Guardar la gráfica en un buffer en lugar de un archivo
    buf = BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)
    plt.close()

    # Insertar la imagen en el PDF
    elements.append(Image(buf, width=400, height=300))
    elements.append(Spacer(1, 12))

    # Conclusión
    best_config = max(speedups, key=lambda x: x[1])
    conclusion = (
        f"La configuración con el speedup más alto fue utilizando {best_config[0]} hilos, "
        f"obteniendo un speedup de {best_config[1]:.4f}."
    )
    elements.append(Paragraph("Conclusión", title_style))
    elements.append(Paragraph(conclusion, body_style))

    # Generar el PDF
    doc.build(elements)


# Ejemplo de uso
if __name__ == "__main__":
    num_cores = os.cpu_count()
    print(f"Número de núcleos (cores): {num_cores}")
    cant_nums = 1000000
    nums = [random.randint(1, 100) for _ in range(cant_nums)]

    speedups = []
    threads = [1, num_cores, num_cores * 2, num_cores * 4]

    for num_workers in threads:
        par_result, time_execution = measure_time(parallel_sum_of_squares, nums, num_workers)
        print(f"Suma paralela con {num_workers} hilos: {par_result}, Tiempo: {time_execution:.4f} segundos")
        
        if num_workers == 1:
            report["secuencial"] = time_execution
        else:
            speedup = report["secuencial"] / time_execution
            print("speedUp: ",speedup)
            speedups.append((num_workers, speedup))
            report[f"{num_workers} hilos"] = time_execution

    report["cores"]=num_cores
    generate_report(report, speedups)