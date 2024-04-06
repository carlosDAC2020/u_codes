
# Regresion Lineal 

# ingreso de valores para la regrecion 
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Lectura de datos desde el archivo CSV
df = pd.read_csv('datos.csv', sep=';')
x = list(df["Temperatura"])
y = list(df["Velocidad"])


def media(datos): 
    return sum(datos)/len(datos)

# desviacion estandar de n valores
def desviacion_estandar(valores):
    # Calcular la suma de los cuadrados de las diferencias
    suma_cuadrados_diferencias = sum([(x - media(valores)) ** 2 for x in valores ])
    
    return (suma_cuadrados_diferencias / len(valores)) ** 0.5

def coeficiente_de_correlacion(x,y):

    sum_xy=sum([x[i]*y[i] for i in range(len(x))])

    # numerador de la formula
    num = (sum_xy/len(x))-(media(x)*media(y))
    # denominador de la formula 
    den = (desviacion_estandar(x)*desviacion_estandar(y))
    
    # Calcular el coeficiente de correlación
    return num / den 

# pendiente de la linea de regrecion
def pendiente(x, y):

    # Calcular el numerador
    num = sum([(xi - media(y)) * (yi - media(y)) for xi, yi in zip(x, y)])
    
    # Calcular el denominador
    den = sum([(xi - media(x)) ** 2 for xi in x])

    # Calcular la pendiente
    b = num / den

    return b

# interseccion de la loinea de regresion 
def interseccion(x, y):
    
    # obtenemos la pendiente
    b = pendiente(x, y)

    # obtenemos la intercepcion aplicando un despeje la formula de la linea de regresion
    a = media(y) - b * media(x)

    return a

# formula de la linea de regrecion
def regrecion_lineal(x_p):
    return interseccion(x, y) + (pendiente(x, y)*x_p) 

# resultados
print("Promedios")
print(" x:",media(x))
print(" y:",media(y))
print("Desviacion estandar")
print(" x:",desviacion_estandar(x))
print(" y:",desviacion_estandar(y))
print("Coeficiente de correlacion:",coeficiente_de_correlacion(x,y))
print(f"Formiua de regresion \n y= {interseccion(x, y)} + {pendiente(x, y)}x")

# Crear valores de x_p
x_p = np.linspace(min(x), max(x), 100)  # valores de -10 a 10, con 100 puntos en total

# Crear valores de y_p utilizando la función reg_poli
y_p = regrecion_lineal(x_p)

# Graficar la función
plt.figure(figsize=(8, 6))
plt.plot(x_p, y_p, label='Regresión Polinómica')
plt.scatter(x, y, color='red', label='Datos')
plt.xlabel('Temperatura')
plt.ylabel('Velocidad')
plt.title('Gráfico de la función de regresión polinómica con datos')
plt.grid(True)
plt.legend()
plt.show()