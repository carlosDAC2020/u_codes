"""
    Estudiante
    - Carlos Daniel Agamez Palomino T00059006
"""
import requests
import matplotlib.pyplot as plt
import time
from concurrent.futures import ThreadPoolExecutor, ProcessPoolExecutor, as_completed
from reportlab.lib.pagesizes import letter
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.lib.units import inch
from reportlab.platypus import SimpleDocTemplate, Paragraph, Table, TableStyle, Image
from reportlab.lib import colors
import matplotlib.pyplot as plt


# urls de RSS a obtener 
urls = [
    # Noticias generales
    "https://www.elmundo.es/rss/",
    "https://www.abc.es/rss/feeds/portada.xml",
    "https://www.europapress.es/rss/portada.xml",
    "https://www.bbc.com/news/rss.xml",
    "https://news.google.com/rss",

    # Deportes
    "https://www.marca.com/rss.aspx",
    "https://www.as.com/rss.xml",
    "https://www.espn.com/espn/rss/news",

    # Tecnología
    "https://www.xataka.com/feed",
    "https://www.engadget.com/rss.xml",
    "https://www.theverge.com/rss",

    # Economía
    "https://www.expansion.com/rss/portada.xml",
    "https://www.eleconomista.es/rss/economia.xml",
    "https://www.bloomberg.com/feeds/news/top-news.rss",

    # Entretenimiento
    "https://www.hollywoodreporter.com/feed",
    "https://www.sensacine.com/rss/",

    # Ciencia
    "https://www.nationalgeographic.com.es/rss/noticias",
    "https://www.sciencemag.org/rss/current-contents",

    # Otros
    "https://www.rtve.es/rss/noticias.xml",
    "https://www.publico.es/rss/ultimas-noticias",
    "https://www.france24.com/en/rss",
    "https://www.aljazeera.com/xml/rss/all.xml",
    "https://www.dw.com/en/rss",
    "https://www.reuters.com/rss/topNews",
    "https://www.apnews.com/rss/topnews.rss",
    "https://www.aljazeera.com/xml/rss/all.xml",
    "https://www.dw.com/en/rss",
    "https://www.reuters.com/rss/topNews",
    "https://www.apnews.com/rss/topnews.rss",
    "https://www.economist.com/rss/",
    "https://techcrunch.com/feed/",
    "https://www.bbc.com/mundo/ultimas_noticias/index.xml",
]


# resultados con tiempos de ejecucion por cada configuracion ademas de la calidad de red
performance_report={
    'threads':{
        "workers":[],
        "times":[]
    },
    'process':{
        "workers":[],
        "times":[]
    }
}

# funcion para la optencion de informacion desde las urls 
def fetch_url(url):
    response = requests.get(url)
    return response.content


def fetch_with_concurrency(worker_type, num_workers, parts_urls):
    start_time = time.time()
    
    futures = []

    if worker_type == 'threads':
        with ThreadPoolExecutor(max_workers=num_workers) as threads:
            for part in parts_urls:
                for url in part:
                    future = threads.submit(fetch_url, url)
                    futures.append(future)
            for future in as_completed(futures):
                future.result()

    elif worker_type == 'process':
        with ProcessPoolExecutor(max_workers=num_workers) as processes:
            for part in parts_urls:
                for url in part:
                    future = processes.submit(fetch_url, url)
                    futures.append(future)     
            for future in as_completed(futures):
                future.result()  

    else:
        raise ValueError("worker_type must be either 'thread' or 'process'")
    
    end_time = time.time()
    execution_time = end_time - start_time

    # reporte de performance
    performance_report[worker_type]["workers"].append(num_workers)
    performance_report[worker_type]["times"].append(round(execution_time,2))
    
    print(f'{worker_type.capitalize()} with {num_workers} workers took {execution_time:.2f} seconds')

def get_performance_report():
    report = {}

    # Obtener el menor tiempo de ejecución entre todas las configuraciones
    min_thread_time = min(performance_report['threads']['times']) if performance_report['threads']['times'] else None
    min_process_time = min(performance_report['process']['times']) if performance_report['process']['times'] else None

    # obtenemos la mejor configuracion segun los mejores tiempos obtenidos 
    if min_thread_time < min_process_time:
        report["type_worker"]='threads'
        report["config"]={
            "num_workers":performance_report['threads']['workers'][performance_report['threads']['times'].index(min_thread_time)],
            "time":min_thread_time
        }
    else:
        report["type_worker"]='process'
        report["config"]={
            "num_workers":performance_report['process']['workers'][performance_report['process']['times'].index(min_thread_time)],
            "time":min_process_time
        }
    
    # obtenemos el punto marginal teniendo en para el tipo de worker y configuracion q mejor ejecutarion la tarea asignada 
    times = performance_report[report["type_worker"]]["times"]
    workers = performance_report[report["type_worker"]]["workers"]
    report["performance_line"]={
        "improvement":[],
        "range_improvement":[]
    }
    report["marginal_point"]=[]
    for i in range(len(times)-1):
        # btenemos un rango de mejora de un numero de workers con respecto a otro
        improvement = abs(((times[i] - times[i+1]) / times[i]) * 100)
        # guardamos la mejora y el rango evaluados en el registro
        report['performance_line']["improvement"].append(round(improvement,3))
        report['performance_line']["range_improvement"].append([workers[i], workers[i+1]])
        
        # obtenemos el punto marginala a partir del mejor tiempo de ejecucion obtenido
        if workers[i]==report['config']["num_workers"]:    
            report["marginal_point"]=[workers[i], workers[i+1]]
            break
        if workers[i+1]==report['config']["num_workers"]:
            report["marginal_point"]=[workers[i+1]]
            break
        
    return report


def crear_report():
    print("\n creando reporte ........")
    doc = SimpleDocTemplate("report.pdf", pagesize=letter, leftMargin=inch/2, rightMargin=inch/2, topMargin=inch/2, bottomMargin=inch/2)

    elements = []

    # Estilos de fuentes
    styles = getSampleStyleSheet()
    estilo_titulo = styles['Title']
    estilo_parrafo = styles['BodyText']
    estilo_subtitulo = ParagraphStyle(
        'Subtitulo', parent=styles['Heading2'], spaceAfter=14, textColor=colors.black)

    # estructura de informe 
    
    titulo = Paragraph(" Concurrencia con Hilos y Procesos en Python (I/O-bound Tasks)", estilo_titulo)
    elements.append(titulo)
    parrafo = Paragraph("En este informe se analiza el desempeño de la obtención de datos desde varias fuentes RSS utilizando diferentes métodos de concurrencia en Python. Se emplearon tanto hilos (threads) como procesos (processes) para evaluar la eficiencia y el tiempo de ejecución en la descarga de contenido de múltiples URLs de RSS.", estilo_parrafo)
    elements.append(parrafo)
    

    subtitulo = Paragraph("Metodologia", estilo_subtitulo)
    elements.append(subtitulo)
    parrafo = Paragraph("El experimento se llevó a cabo utilizando un script en Python que descarga el contenido de varias URLs de RSS. Las URLs se dividen equitativamente según el número de trabajadores (workers) asignados. El script utiliza dos métodos de concurrencia: hilos y procesos, variando el número de trabajadores desde 1 hasta 32 en incrementos exponenciales. \nPara cada configuración de concurrencia (hilos y procesos) y cada número de trabajadores, se mide el tiempo total de ejecución. Los resultados se registran para un análisis comparativo.", estilo_parrafo)
    elements.append(parrafo)
    parrafo = Paragraph("Para cada configuración de concurrencia (hilos y procesos) y cada número de trabajadores, se mide el tiempo total de ejecución. Los resultados se registran para un análisis comparativo.", estilo_parrafo)
    elements.append(parrafo)

    # Datos para la tabla de hilos
    data_thread = [['Número de Workers', 'Tiempo de Ejecución (s)']]
    for workers, times in zip(performance_report['threads']['workers'], performance_report['threads']['times']):
        data_thread.append([workers, times])
    table_thread = Table(data_thread, colWidths=[2*inch]*2)
    table_thread.setStyle(TableStyle([('BACKGROUND', (0, 0), (-1, 0), colors.grey),
                                      ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
                                      ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                                      ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                                      ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
                                      ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
                                      ('GRID', (0, 0), (-1, -1), 1, colors.black)]))
    elements.append(Paragraph("Analisis para Hilos (Threads)", estilo_subtitulo))
    elements.append(table_thread)

    img_path_thread = "grafico_thread.png"
    img_thread = Image(img_path_thread, 6*inch, 4*inch)
    elements.append(img_thread)

    # Datos para la tabla de procesos
    data_process = [['Número de Workers', 'Tiempo de Ejecución (s)']]
    for workers, times in zip(performance_report['process']['workers'], performance_report['process']['times']):
        data_process.append([workers, times])
    table_process = Table(data_process, colWidths=[2*inch]*2)
    table_process.setStyle(TableStyle([('BACKGROUND', (0, 0), (-1, 0), colors.grey),
                                       ('TEXTCOLOR', (0, 0), (-1, 0), colors.whitesmoke),
                                       ('ALIGN', (0, 0), (-1, -1), 'CENTER'),
                                       ('FONTNAME', (0, 0), (-1, 0), 'Helvetica-Bold'),
                                       ('BOTTOMPADDING', (0, 0), (-1, 0), 12),
                                       ('BACKGROUND', (0, 1), (-1, -1), colors.beige),
                                       ('GRID', (0, 0), (-1, -1), 1, colors.black)]))
    elements.append(Paragraph("Analisis para Procesos (Processes)", estilo_subtitulo))
    elements.append(table_process)

    img_path_process = "grafico_process.png"
    img_process = Image(img_path_process, 6*inch, 4*inch)
    elements.append(img_process)

    subtitulo = Paragraph("Resultados", estilo_subtitulo)
    elements.append(subtitulo)
    parrafo = Paragraph("Teniendo en cuenta el analisis anterior tanto para hilos como para procesos se obtiene que:", estilo_parrafo)
    elements.append(parrafo)

    # Añade ejemplos de items con viñetas
    best_worker_type = performance_report['results']['type_worker']
    best_config = performance_report['results']['config']
    marginal_point = performance_report['results']["marginal_point"]
    items = [
        f"El tipo de worker más eficiente para esta tarea es el de {best_worker_type}.",
        f"La configuración más óptima se logró utilizando {best_worker_type} con {best_config['num_workers']} workers, alcanzando un tiempo de ejecución de {best_config['time']} segundos.",
    ]
    if len(marginal_point)>1:
        items.append(f"El punto de mejora marginal se observa entre {marginal_point[0]} y {marginal_point[1]} workers, a partir de los cuales el incremento en el número de workers con {best_worker_type} muestra beneficios decrecientes.")
    else:
        items.append(f"Se puede asumir que el punto marginal seria a partir de la configuracion mas eficiente en adelante.")

    lista_con_viñetas = "<br/>".join([f"&bull; {item}" for item in items])
    parrafo_con_viñetas = Paragraph(lista_con_viñetas, estilo_parrafo)
    elements.append(parrafo_con_viñetas)

    # Construir el PDF
    doc.build(elements)


if __name__ == '__main__':
    for worker in ['threads','process']:
        num_workers=1
        print("\n ",worker)
        while num_workers<=32:
            # dividim os las urls equitativamente segun el numero de trabajadores 
            parts =  int(len(urls)/num_workers)
            parts_urls = [urls[i:i + parts] for i in range(0, len(urls), parts)]
            # aplicamos la busqueda
            fetch_with_concurrency(worker,num_workers,parts_urls)
            num_workers*=2
    
    # Grafica para thread
    fig_thread, ax_thread = plt.subplots(figsize=(10, 4))
    ax_thread.plot(performance_report['threads']['workers'], performance_report['threads']['times'], marker='o', linestyle='-', color='b')
    ax_thread.set_title('Thread Execution Time')
    ax_thread.set_xlabel('Number of Workers')
    ax_thread.set_ylabel('Time (seconds)')
    ax_thread.grid(True)
    plt.tight_layout()
    fig_thread.savefig("grafico_thread.png")

    # Grafica para process
    fig_process, ax_process = plt.subplots(figsize=(10, 4))
    ax_process.plot(performance_report['process']['workers'], performance_report['process']['times'], marker='o', linestyle='-', color='r')
    ax_process.set_title('Process Execution Time')
    ax_process.set_xlabel('Number of Workers')
    ax_process.set_ylabel('Time (seconds)')
    ax_process.grid(True)
    plt.tight_layout()
    fig_process.savefig("grafico_process.png")

    performance_report["results"] = get_performance_report()
    print(performance_report["results"])
    
    # creamos el informe de ejecucion 
    crear_report()
    