from math import log
import random

def p1():
    p = float(input(" cantidad invertida inicial :"))
    r = float(input(" tasa de interes anual :"))
    n = float(input(" nimero de veces que se compone el interes:"))
    t = float(input(" numero de años de la inversion:"))

    y = p*(log((1+r)/n))/(-n*t)

    print(" el valor de la invercion a largo plazo es :", y)

def p2():
    
    # Definir el número de simulaciones y el número de bolas rojas y verdes en la urna
    num_simulaciones = 100000
    num_rojas = 10
    num_verdes = 5

    # Contador de extracciones con al menos una bola roja
    contador_rojas = 0

    # Simulación de extracción de 3 bolas sin reemplazo
    for i in range(num_simulaciones):
        urna = ['roja'] * num_rojas + ['verde'] * num_verdes
        extracciones = random.sample(urna, 3)
        if 'roja' in extracciones:
            contador_rojas += 1

    # Calcular la probabilidad estimada de obtener al menos una bola roja
    probabilidad_roja = contador_rojas / num_simulaciones
    print("La probabilidad de obtener al menos una bola roja es:", probabilidad_roja)

