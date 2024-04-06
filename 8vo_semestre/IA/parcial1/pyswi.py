"""
from pyswip import Prolog

# Inicializa el motor Prolog
prolog = Prolog()

# Carga el archivo Prolog
prolog.consult('agenda.pl')

# Consulta la lista de anfitriones disponibles
anfitriones_disponibles = list(prolog.query("anfitrion(X)"))

# Imprime la lista de anfitriones disponibles
print("Anfitriones disponibles:")
for anfitrion in anfitriones_disponibles:
    print(anfitrion['X'])
"""

from pyDatalog import pyDatalog
# Definición de predicados
def usuario(u):
    return True

def anfitrion(a):
    return True

def fecha(d, m, a):
    return True

def hora(h, mi):
    return True

def canal(c, u):
    return True

# Reglas
def hay_cita_programada(u, a, d, m, a_, h, mi):
    return usuario(u) and anfitrion(a) and fecha(d, m, a_) and hora(h, mi)

# Funciones auxiliares
def validar_jornada(horas):
    duracion_total = sum(h * 60 + mi for h, mi in horas)
    return duracion_total <= 5 * 60

def validar_duracion_cita(horas):
    return all(h * 60 + mi <= 50 for h, mi in horas)

# Función para ingresar los datos del usuario
def ingresar_datos():
    u = input("Ingrese su nombre de usuario: ")

    print("Seleccione el nombre del anfitrión:")
    print("1. Cristina")
    print("2. Andres")
    print("3. Esteban")
    print("4. Miriam")
    while True:
        opcion = int(input("Ingrese el número correspondiente al nombre del anfitrión: "))
        if 1 <= opcion <= 2:
            break
        else:
            print("Por favor, ingrese un valor válido para el día.")

    a = {
        1: "Cristina",
        2: "Andres"
    }[opcion]

    while True:
        d = int(input("Ingrese el día de la fecha de la cita: "))
        if 1<= d <= 31:
            break
        else:
            print("Por favor, ingrese un valor válido para el día: ")
    while True:
        m = int(input("Ingrese el mes de la fecha de la cita: "))
        if 1<= m<=12:
            break
        else:
            print("Por favor, ingrese un valor válido para el mes: ")

    a_ = int(input("Ingrese el año de la fecha de la cita: "))

    while True:
        h = int(input("Ingrese la hora de la cita(0-24)hr: "))
        if 0<= h<=24:
            break
        else:
            print("Por favor, ingrese un valor válido para la hora: ")

    while True:
        mi = int(input("Ingrese los minutos de la cita(0-59)hr:  "))
        if 0<= mi<=59:
            break
        else:
            print("Por favor, ingrese un valor válido: ")
    return u, a, d, m, a_, h, mi

# Casos de prueba
def run_tests():
    # Caso 1: Se programa una cita para un usuario con un anfitrión en una fecha y hora válidas.
    print("\nIngrese los datos para el caso 1:")
    u, a, d, m, a_, h, mi = ingresar_datos()
    test_1 = hay_cita_programada(u, a, d, m, a_, h, mi)
    print("Caso 1:", test_1)

    # Caso 2: Se verifica que una jornada no exceda la duración máxima permitida.
    print("\nIngrese los datos para el caso 2:")
    horas = [(int(input("Ingrese la hora: ")), int(input("Ingrese los minutos: "))) for _ in range(2)]
    test_2 = validar_jornada(horas)
    print("Caso 2:", test_2)

    # Caso 3: Se verifica que una cita tenga una duración válida.
    print("\nIngrese los datos para el caso 3:")
    horas = [(int(input("Ingrese la hora: ")), int(input("Ingrese los minutos: "))) for _ in range(6)]
    test_3 = validar_duracion_cita(horas)
    print("Caso 3:", test_3)

run_tests()