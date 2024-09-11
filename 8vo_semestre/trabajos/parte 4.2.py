# Andreina Cantillo Guerrero T00063657
# Hellen Margarita Morales Colon #T00069386

# para trabajar con dataframes y leer archivos csv
import pandas as pd
# para crear gráficas
import matplotlib.pyplot as plt
# para trabajar con arrays y operaciones matemáticas
import numpy as np

df =pd.read_csv('dataICA.csv', sep=';')
x =list(df["PM2.5"])
y =list(df["ICA"])

# funciones basicas --------------------------------------------------------

# media de n valores
def media(valores):
    suma=0
    for val in valores:
        suma+=val

    return suma/len(valores)

# desviacion estandar de n valores
def desv_estandar(valores):
    # Calcular la media de los valores
    md = media(valores)

    # Calcular la suma de los cuadrados de las diferencias
    suma_cuadrados_diferencias = 0
    for x in valores:
        suma_cuadrados_diferencias += (x - md) ** 2

    return (suma_cuadrados_diferencias / len(valores)) ** 0.5

# coeficiente de correlacion
def coef_correl(x,y):
    # Calcular la media de X e Y
    x_media = media(x)
    y_media = media(y)

    sum_xy=0

    for i in range(len(x)):
        sum_xy += x[i]*y[i]

    covarianza=(sum_xy/len(x))-(x_media*y_media)

    # Calcular el coeficiente de correlación
    return covarianza / (desv_estandar(x)*desv_estandar(y))

# metricas basicas
print("\n Promedios")
print(" x:",media(x))
print(" y:",media(y))
print("\n Desviacion estandar")
print(" x:",desv_estandar(x))
print(" y:",desv_estandar(y))
print("\n Coeficiente de correlacion:",coef_correl(x,y))

# funciones para evaluar el rendimiendo de los modelos de regresion ----------

# Coeficiente de determinacion
def coef_det(y_obs, y_pred):

    y_media = media(y_obs)

    num=0
    den=0

    for i in range(len(y_obs)):
        num += (y_pred[i]-y_media)**2
        den += (y_obs[i]-y_media)**2

    return  num/den

# error estandar del estimado
def er_std_estimado(y_obs, y_pred):
    # Calcular la suma de los cuadrados de las diferencias
    numerador=0
    for yi in y_obs:
        numerador +=(yi-media(y_pred))**2

    return (numerador / (len(y_obs) - 2)) ** 0.5

# Obtenemos el modelo de regresion lineal ------------------------------------

# pendiente de la linea de regresion
def pendiente(x, y):
    # Calcular la media de X e Y
    x_media = media(x)
    y_media = media(y)

    # Calcular el numerador
    numerador = 0
    for xi, yi in zip(x, y):
        numerador += (xi - x_media) * (yi - y_media)

    # Calcular el denominador
    denominador = 0
    for xi in x:
        denominador += (xi - x_media) ** 2

    # Calcular la pendiente
    b = numerador / denominador

    return b

# interseccion de la linea de regresion
def interseccion(x, y):
    # Calcular la media de X e Y
    x_media = media(x)
    y_media = media(y)

    # Calcular la pendiente
    b = pendiente(x, y)

    # Calcular la intersección
    a = y_media - b * x_media

    return a

# Calcular la pendiente y la intersección de la línea de regresión
b = pendiente(x, y)
a = interseccion(x, y)

# obtenemos la formula de la linea de regresion lineal
regresion_lineal = lambda x : a+(b*x)

# predecimos algunos valores de y con el modelo de regresion
y_predic_reg_lineal = [regresion_lineal(xi) for xi in x]

# Imprimir los resultados para la regresion lineal
print("\n Modelo de regresion lineal")
print(f" y = {a} + ({b})x")
print("Error estandar del estimado:",er_std_estimado(y,y_predic_reg_lineal))
print("Coeficiente de determinacion:",coef_det(y,y_predic_reg_lineal))

# obtenemos el modelo de regresion polinomial --------------------------------

# funcion para resolver un sistema de ec lineal usando el metodo de eliminacion gaussiana
def eliminacion_gaussiana(A, B):
    n = len(A)
    # Convertir la matriz A en triangular superior
    for i in range(n):
        for j in range(i+1, n):
            factor = A[j][i] / A[i][i]
            for k in range(i, n):
                A[j][k] -= factor * A[i][k]
            B[j] -= factor * B[i]

    # Sustitución hacia atrás para encontrar la solución
    X = [0] * n
    for i in range(n-1, -1, -1):
        X[i] = B[i] / A[i][i]
        for j in range(i-1, -1, -1):
            B[j] -= A[j][i] * X[i]

    # retornamos los resultados de las incognitas
    return X[0],X[1],X[2]

"""
    El modelo de regresion polinomica se representa :
             y = B0 + B1x + B2x^2
"""

# Declaramos las matrices que representara el sistema de ecuaciones linal a resolver para onbtener los coeficientes
matriz_incognitas=[[0 for _ in range(3)] for _ in range(3)]
for f in range(3):
    for c in range(3):
        if f==0 and c==0:
            matriz_incognitas[f][c]=len(x)
        else:
            matriz_incognitas[f][c]= sum([xi**(f+c) for xi in x])

matriz_constantes =[sum(y),
                    sum([x[i]*y[i] for i in range(len(x))]),
                    sum([(x[i]**2)*y[i] for i in range(len(x))])
                    ]

# imprimimos el sistema de ecuaciones lineal a resolver
print("\n Modelo de regresion lineal")
i=0
print(" sistema de ecuaciones lineales a resolver")
for f in  range(3):
    for c in range(3):
        print("{:^12}".format(f"{round(matriz_incognitas[f][c],2)}b{c}"),end=' ')
        if c<2:
            print("+",end=' ')
    print(" ={:^12}\n".format(round(matriz_constantes[i],2)))
    i+=1

# Resolver el sistema de ecuaciones lineales usando eliminación gaussiana
B0,B1,B2 = eliminacion_gaussiana(matriz_incognitas, matriz_constantes)

# obtenemos la formula de la linea de regresion polinomial
regresion_polinomial = lambda x :B0 + (B1*x) + (B2*(x**2))

# predecimos algunos valores de y con el modelo de regresion
y_predic_reg_polinomial = [regresion_polinomial(xi) for xi in x]

# Imprimir los resultados para la regresion polinomial
print(f"y= {B0} + ({B1})x + ({B2})x^2  ")
print("Error estandar del estimado:",er_std_estimado(y,y_predic_reg_polinomial))
print("Coeficiente de determinacion:",coef_det(y,y_predic_reg_polinomial))


# rango de valores a mostrar en la grafica
x_p = np.linspace(min(x), max(x), 100)

# prediccion de valores a mostrar en la grafica
y_lineal = regresion_lineal(x_p)
y_polinomial = regresion_polinomial(x_p)

# Graficar la función
plt.figure(figsize=(8, 6))
plt.plot(x_p, y_lineal, label=f'y = {round(a,2)} + {round(b,2)}x')
plt.plot(x_p, y_polinomial, label=f'y = {round(B0,2)} + {round(B1),2}x + ({round(B2,4)})x^2')
plt.scatter(x, y, color='blue', label='Datos')
plt.xlabel('Concentración PM2,5')
plt.ylabel('ICA')
plt.title('Calidad del Aire')
plt.grid(True)
plt.legend()
plt.show()
