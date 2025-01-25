
"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""
from reportlab.lib.pagesizes import A4
from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Table, TableStyle, Image
from reportlab.lib import colors
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from io import BytesIO
import matplotlib.pyplot as plt
from reportlab.lib.units import inch
import multiprocessing
import random
import os
import time
from colorama import Fore, Style, init

# Inicializar colorama
init(autoreset=True)

def deposit(balance, lock, process):
    """Función para realizar un depósito."""
    deposit_amount = random.uniform(1, 100)
    with lock:
        balance.value += deposit_amount
        print(f"Process:{process} - Deposit: {Fore.GREEN}${deposit_amount:.2f}{Style.RESET_ALL}    Balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")

def withdraw(balance, lock, process):
    """Función para realizar un retiro."""
    withdraw_amount = random.uniform(1, 300)
    with lock:
        if balance.value >= withdraw_amount:
            balance.value -= withdraw_amount
            print(f"Process:{process} - Withdraw: {Fore.RED}${withdraw_amount:.2f}{Style.RESET_ALL}    Balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")
        else:
            print(f"Process:{process} - Withdraw: {Fore.YELLOW}${withdraw_amount:.2f}{Style.RESET_ALL} declined    Balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")

def deposit_withdraw(balance, lock, process, transactions, transaction_count):
    """Función para realizar transacciones aleatorias (depósitos o retiros)."""
    for _ in range(transactions):
        if random.choice([True, False]):
            deposit(balance, lock, process)
        else:
            withdraw(balance, lock, process)
        transaction_count[process - 1] += 1

def generate_report(report, results):
    """Función para generar el informe en PDF"""
    doc = SimpleDocTemplate("informe_ejecucion.pdf", pagesize=A4)
    elements = []

    # Estilos
    styles = getSampleStyleSheet()
    title_style = styles['Title']
    body_style = styles['BodyText']
    subtitle_style = ParagraphStyle('Subtitle', parent=styles['Heading2'], spaceAfter=14, textColor=colors.black)

    # Título
    elements.append(Paragraph("Informe de Ejecución: Transacciones Paralelas", title_style))
    elements.append(Spacer(1, 12))

    # Descripción
    description = ("Este informe describe el proceso y los resultados de la ejecución de un script "
                   "que simula un sistema de transacciones utilizando múltiples procesos. Se miden "
                   "el tiempo de ejecución y las transacciones por segundo para diferentes configuraciones de procesos.")
    elements.append(Paragraph(description, body_style))
    elements.append(Spacer(1, 12))

    # Metodología
    methodology = ("El script realiza depósitos y retiros en paralelo utilizando diferentes configuraciones "
                   "de procesos (1, número de núcleos, 2x núcleos, 4x núcleos). Se mide el tiempo total de "
                   "ejecución y las transacciones por segundo para cada configuración.")
    elements.append(Paragraph("Metodología", subtitle_style))
    elements.append(Paragraph(methodology, body_style))
    elements.append(Spacer(1, 12))

    # Tiempo de ejecución secuencial
    num_cores = report["cores"]
    elements.append(Paragraph(f"La ejecución se realizó en una máquina con {num_cores} núcleos.", body_style))
    elements.append(Spacer(1, 12))

    # Cantidad de transacciones
    elements.append(Paragraph(f"El total de transacciones ejecutadas es de {total_transactions} sin importar la cantidad de procesos y estas se dividin equitativamnete entre los procesos.", body_style))
    elements.append(Spacer(1, 12))

    # Análisis de Resultados
    elements.append(Paragraph("Análisis de Resultados", subtitle_style))
    elements.append(Paragraph("A continuación, se presentan los tiempos de ejecución y las transacciones por segundo para cada configuración de procesos.", body_style))
    elements.append(Spacer(1, 12))

    # Tabla de resultados
    data = [["Número de Procesos", "Tiempo de Ejecución (s)", "Transacciones por Segundo"]]
    execution_times = []

    for result in results:
        num_processes = result['num_processes']
        time_execution = result['total_time']
        tps = total_transactions / time_execution
        data.append([str(num_processes), f"{time_execution:.4f}", f"{tps:.2f}"])
        execution_times.append((num_processes, time_execution))

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

    # Gráfico de Tiempo de Ejecución vs Número de Procesos
    workers, exec_times = zip(*execution_times)
    plt.plot(workers, exec_times, marker='o')
    plt.title("Tiempo de Ejecución vs Número de Procesos")
    plt.xlabel("Número de Procesos")
    plt.ylabel("Tiempo de Ejecución (s)")
    plt.legend()
    plt.grid(True)
    buf = BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)
    plt.close()

    # Insertar imagen en PDF
    elements.append(Image(buf, width=400, height=300))
    elements.append(Spacer(1, 12))

    # Conclusión
    elements.append(Paragraph("Conclusión", subtitle_style))
    conclusion = ("Más procesos no siempre implican mejor rendimiento: Los resultados muestran que, en este caso, "
                  "usar más de 4 procesos no es eficiente. A partir de un cierto número de procesos, la sobrecarga "
                  "de gestión y sincronización supera los beneficios de paralelización.<br/>"
                  "Contención por recursos: Al haber un recurso compartido (el balance) y utilizarse un candado, "
                  "se introduce contención y tiempos de espera entre los procesos, lo que afecta negativamente el rendimiento.<br/>"
                  "Sobrecarga de procesos: Crear y gestionar muchos procesos tiene un costo adicional que, cuando se excede "
                  "un límite razonable, puede empeorar los tiempos de ejecución.")
    elements.append(Paragraph(conclusion, body_style))

    # Generar el PDF
    doc.build(elements)

if __name__ == "__main__":
    multiprocessing.set_start_method('spawn')
    num_cores = os.cpu_count()
    total_transactions = 1000
    results = []

    for factor in [1, 2, 4, 8]:
        num_processes = num_cores * factor
        transactions_per_process = int(total_transactions / num_processes)
        balance = multiprocessing.Value('d', 100.0)
        lock = multiprocessing.Lock()
        transaction_count = multiprocessing.Array('i', num_processes)
        print(f"\nEjecutando con {num_processes} procesos - Cada proceso realizará {transactions_per_process} transacciones")
        print(f"balance inicial: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL} \n")

        processes = []
        start_time = time.time()

        for i in range(num_processes):
            p = multiprocessing.Process(target=deposit_withdraw, args=(balance, lock, i + 1, transactions_per_process, transaction_count))
            processes.append(p)
            p.start()

        for p in processes:
            p.join()

        end_time = time.time()
        total_time = end_time - start_time
        results.append({"num_processes": num_processes, "final_balance": balance.value, "total_time": total_time})
        print(f"Balance final: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL} - Tiempo total: {total_time:.2f} s")

    # Generar el reporte PDF
    report = {f"{result['num_processes']} procesos": result['total_time'] for result in results}
    report["secuencial"] = results[0]['total_time']
    report["cores"] = num_cores
    generate_report(report, results)
