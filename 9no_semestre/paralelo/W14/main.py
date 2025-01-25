
"""

Estudiante
- Carlos Daniel Agamez Palomino T00059006

RETO 
El desafío consiste en implementar un sistema de procesamiento de transferencias bancarias simuladas entre varias cuentas. La meta es asegurar que las transacciones se realicen de manera eficiente y segura mediante concurrencia, de modo que múltiples operaciones puedan ser gestionadas en paralelo sin comprometer la consistencia de los datos.

Metodología Implementada: Productor-Consumidor

Para resolver este reto, se aplica el modelo productor-consumidor que permite gestionar la concurrencia entre hilos de manera efectiva. En este sistema:

    - El productor genera transferencias y las coloca en una cola compartida.
    - Los consumidores toman transferencias de la cola y las procesan de forma paralela.

Este modelo asegura eficiencia y seguridad en varios aspectos:

    - Separación de Tareas: La generación y procesamiento de transferencias son funciones independientes, permitiendo un flujo continuo de trabajo.
    - Procesamiento en Paralelo: Múltiples consumidores pueden procesar transferencias a la vez, reduciendo el tiempo de ejecución.
    - Consistencia de Datos: Cada consumidor utiliza bloqueos específicos para acceder a las cuentas, evitando conflictos y garantizando saldos correctos.
    - Escalabilidad: La cantidad de hilos consumidores puede ajustarse según el volumen de transacciones, permitiendo al sistema manejar mayor carga de trabajo de manera adaptable.

Este enfoque mantiene la estabilidad, eficiencia y seguridad del sistema, asegurando que las transferencias bancarias se procesen correctamente sin inconsistencias en los saldos de las cuentas.
"""


import threading
import random
import queue
from colorama import Fore, Style, init
import time

# Inicializar colorama para colores en la consola
init(autoreset=True)


class Transfer:
    """
    Clase que representa una transferencia entre dos cuentas.

    Attributes:
        amount (float): Monto de la transferencia.
        account_from (int): Índice de la cuenta desde la que se transfiere.
        account_to (int): Índice de la cuenta a la que se transfiere.
    """

    def __init__(self, amount, account_from, account_to):
        self.amount = amount
        self.account_from = account_from
        self.account_to = account_to


def producer(transfer_queue, num_transfers, accounts):
    """
    Crea transacciones aleatorias y las coloca en la cola.

    Args:
        transfer_queue (queue.Queue): Cola donde se colocan las transferencias generadas.
        num_transfers (int): Número total de transferencias a crear.
        accounts (list): Lista de cuentas disponibles para las transferencias.
    """
    for _ in range(num_transfers):
        account_from, account_to = random.sample(range(len(accounts)), 2)
        transfer_amount = round(random.uniform(1, 100), 2)
        transfer = Transfer(transfer_amount, account_from, account_to)
        transfer_queue.put(transfer)
        print(f"\nProducer created transfer: ${transfer_amount} from Account {account_from} to Account {account_to}")


def consumer(transfer_queue, accounts, histories, locks, thread_id):
    """
    Toma transferencias de la cola y las procesa.

    Args:
        transfer_queue (queue.Queue): Cola de transferencias.
        accounts (list): Lista de saldos de cuentas.
        histories (list): Lista de listas que registra la historia de transacciones de cada cuenta.
        locks (list): Lista de bloqueos para sincronizar el acceso a cada cuenta.
        thread_id (int): Identificador del hilo consumidor.
    """
    while True:
        try:
            transfer = transfer_queue.get(timeout=1)
        except queue.Empty:
            break  # Salir si la cola está vacía y no hay más transferencias

        first, second = sorted([transfer.account_from, transfer.account_to])
        with locks[first], locks[second]:
            if accounts[transfer.account_from] >= transfer.amount:
                accounts[transfer.account_from] = round(accounts[transfer.account_from] - transfer.amount, 2)
                accounts[transfer.account_to] = round(accounts[transfer.account_to] + transfer.amount, 2)

                histories[transfer.account_from].append(-transfer.amount)
                histories[transfer.account_to].append(transfer.amount)

                print(f"\nConsumer {thread_id} processed transfer: {Fore.GREEN}${transfer.amount}{Style.RESET_ALL} "
                      f"from Account {transfer.account_from} to Account {transfer.account_to} "
                      f"Balances: {Fore.BLUE}{accounts}{Style.RESET_ALL}")
            else:
                print(f"\nConsumer {thread_id} declined transfer of ${transfer.amount} due to insufficient funds "
                      f"in Account {transfer.account_from}")

        transfer_queue.task_done()


if __name__ == "__main__":
    # Configuración inicial
    num_accounts = int(input("Enter the number of accounts (2-10): "))
    num_threads = int(input("Enter the number of consumers (2-20): "))
    num_transfers = int(input("Enter the number of transfers : "))

    # saldo incial 
    balance_initial = 100
    # Saldos iniciales y bloqueo para cada cuenta
    accounts = [balance_initial for _ in range(num_accounts)]
    histories = [[] for _ in range(num_accounts)]
    locks = [threading.Lock() for _ in range(num_accounts)]
    
    # Cola para las transferencias
    transfer_queue = queue.Queue()

    print(f"\nInitial balances: {Fore.BLUE}{accounts}{Style.RESET_ALL}\n")

    # Crear hilo productor
    producer_thread = threading.Thread(target=producer, args=(transfer_queue, num_transfers, accounts))
    producer_thread.start()

    # Crear hilos consumidores
    consumer_threads = []
    for i in range(num_threads):
        t = threading.Thread(target=consumer, args=(transfer_queue, accounts, histories, locks, i + 1))
        consumer_threads.append(t)
        t.start()

    # Esperar a que el productor termine
    producer_thread.join()

    # Esperar a que todos los consumidores terminen
    transfer_queue.join()
    for t in consumer_threads:
        t.join()

    # Verificar consistencia
    for i, account in enumerate(accounts):
        print(f"\nAccount {i} Initial balance: $100.00 Final balance: ${account:.2f}")
        print(f"\nAccount {i} history:")
        for history in histories[i]:
            print(f"{history:+.2f}")

        # Revisar consistencia entre el balance final y el historial
        if round(100 + sum(histories[i]), 2) != account:
            print(f"\n\nERROR: Account {i} final balance is not consistent with initial balance and transaction history")
        else:
            print(f"\nAccount {i} final balance is consistent with initial balance and transaction history")
