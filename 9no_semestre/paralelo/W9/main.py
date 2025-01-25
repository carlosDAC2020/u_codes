"""
Estudiante
- Carlos Daniel Agamez Palomino T00059006
"""
import multiprocessing
import random
import os
from colorama import Fore, Style, init

# Inicializar colorama
init(autoreset=True)

def deposit(balance, lock, process):
    """Función para realizar un depósito."""
    deposit_amount = random.uniform(1, 100)  # Generar un depósito aleatorio
    with lock:
        balance.value += deposit_amount
        print(f"Process:{process} - Deposit: {Fore.GREEN}${deposit_amount:.2f}{Style.RESET_ALL}    Balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")

def withdraw(balance, lock, process):
    """Función para realizar un retiro."""
    withdraw_amount = random.uniform(1, 300)  # Generar un retiro aleatorio
    with lock:
        if balance.value >= withdraw_amount:
            balance.value -= withdraw_amount
            print(f"Process:{process} - Withdraw: {Fore.RED}${withdraw_amount:.2f}{Style.RESET_ALL}    Balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")
        else:
            print(f"Process:{process} - Withdraw: {Fore.YELLOW}${withdraw_amount:.2f}{Style.RESET_ALL} declined    Balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")

def deposit_withdraw(balance, lock, process):
    """Función para realizar 10 transacciones aleatorias (depósitos o retiros)."""
    for _ in range(10):
        # Seleccionar aleatoriamente si hacer un depósito o retiro
        if random.choice([True, False]):
            deposit(balance, lock, process)
        else:
            withdraw(balance, lock, process)

if __name__ == "__main__":
    multiprocessing.set_start_method('spawn')
    num_cores = os.cpu_count()  # Obtener el número de núcleos de la CPU
    
    print(f"Number of cores: {num_cores}")

    # Crear un valor compartido para el balance
    balance = multiprocessing.Value('d', 100.0)  # 'd' es para float
    lock = multiprocessing.Lock()  # Crear un candado para sincronización

    print(f"Initial balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL} \n")

    # Crear múltiples procesos
    processes = []
    for i in range(num_cores):
        p = multiprocessing.Process(target=deposit_withdraw, args=(balance, lock, i+1))
        processes.append(p)
        p.start()

    # Esperar a que todos los procesos terminen
    for p in processes:
        p.join()

    # Imprimir balance final
    print(f"\nFinal balance: {Fore.BLUE}${balance.value:.2f}{Style.RESET_ALL}")