# para trabajar con dataframes y leer archivos csv     
import pandas as pd    
# para crear gráficas    
import matplotlib.pyplot as plt   
import numpy as np

df = pd.read_csv('datos.csv', sep=';')

print("Datos utilizados \n",df,"\n")
x = list(df["Temperatura"])
y = list(df["Velocidad"])

# media o promedio 
def media(datos): 
    return sum(datos)/len(datos)

# desviacion estandar de n valores
def desviacion_estandar(valores):
    # Calcular la suma de los cuadrados de las diferencias
    suma_cuadrados_diferencias = sum([(x - media(valores)) ** 2 for x in valores ])
    
    return (suma_cuadrados_diferencias / len(valores)) ** 0.5

# coeficiente de correlacion 
def coeficiente_de_correlacion(x,y):

    sum_xy=sum([x[i]*y[i] for i in range(len(x))])

    # numerador de la formula
    num = (sum_xy/len(x))-(media(x)*media(y))
    # denominador de la formula 
    den = (desviacion_estandar(x)*desviacion_estandar(y))
    
    # Calcular el coeficiente de correlación
    return num / den 

""" para la regrecion lineal ----------------------------------------------"""
# pendiente de la linea de regrecion
def pendiente(x, y):

    # Calcular el numerador
    num = sum([(xi - media(y)) * (yi - media(y)) for xi, yi in zip(x, y)])
    
    # Calcular el denominador
    den = sum([(xi - media(x)) ** 2 for xi in x])

    # Calcular la pendiente
    b = num / den

    return b
b = pendiente(x, y)
    
# interseccion de la loinea de regresion 
def interseccion(x, y):
    
    # obtenemos la pendiente
    b = pendiente(x, y)

    # obtenemos la intercepcion aplicando un despeje la formula de la linea de regresion
    a = media(y) - b * media(x)

    return a
a = interseccion(x, y)

# formula de la linea de regrecion
def regresion_lineal(x_p):
    return a + (b*x_p) 

""" para la regrecion polinomica de grado 2 -------------------------------"""

def reg_polinomial_g2(x,y):
    """ 
    buscamos la funcion y^= B0 + B1x + B2x^2 que representa 
    una regresion polinomial de grado 2 encontrando los coeficientes B0, B1 Y B2 los cuales conforman la ecuacion general polinomica de segundo grado
                Y^= B0 + B1x + B2x^2
    resolviendo el siguiente sistema de ecuaciones usando el metodo de CRamer 
        nB0     +  sum(x)B1  + sum(x^2)B2 = sum(y)
     sum(x)B0   + sum(x^2)B1 + sum(x^3)B2 = sum(x*y)
    sum(x^2)B0  + sum(x^3)B1 + sum(x^4)B2 = sum((y^2)*y)
    """
    # obtencion de sumatorias 
    n = len(x)
    sum_x = sum(x)
    sum_x_elv_2 = sum([xi**2 for xi in x])
    sum_x_elv_3 = sum([xi**3 for xi in x])
    sum_x_elv_4 = sum([xi**4 for xi in x])
    sum_y = sum(y)
    sum_xy = sum([x[i]*y[i] for i in range(len(x))])
    sum_x2_y = sum([(x[i]**2)*y[i] for i in range(len(x))])

    """
        organizacion de las matrices
    """
    matrizA=[
            [n           , sum_x       , sum_x_elv_2],
            [sum_x       , sum_x_elv_2 , sum_x_elv_3],
            [sum_x_elv_2 , sum_x_elv_3 , sum_x_elv_4]
        ]
 
    # declaramos una funcion que nos ayude a obtener el determinate de una matriz
    def determinante(matriz):
        # Caso base: si la matriz es 1x1, el determinante es el único elemento de la matriz
        if len(matriz) == 1:
            return matriz[0][0]
        
        # Inicializar el determinante
        det = 0
        
        # Iterar sobre la primera fila de la matriz
        for i in range(len(matriz)):
            # Calcular el signo (+/-) del término actual
            signo = (-1) ** i
            
            # Calcular el cofactor de la matriz
            cofactor = []
            for j in range(1, len(matriz)):
                fila = []
                for k in range(len(matriz)):
                    if k != i:
                        fila.append(matriz[j][k])
                cofactor.append(fila)
            
            # Calcular el determinante recursivamente
            det += signo * matriz[0][i] * determinante(cofactor)
        
        return det

    """
        obtenemos el determinate de la matriz 
    """
    det_matrizA = determinante(matrizA)
    """
        obtenemos coeficiente B0, B1 y B2
    """
    matriz_aux_B0 =[
            [sum_y    , sum_x       , sum_x_elv_2],
            [sum_xy   , sum_x_elv_2 , sum_x_elv_3],
            [sum_x2_y , sum_x_elv_3 , sum_x_elv_4]
        ]
    B0=determinante(matriz_aux_B0)/det_matrizA

    matriz_aux_B1 =[
            [n           , sum_y    , sum_x_elv_2],
            [sum_x       , sum_xy   , sum_x_elv_3],
            [sum_x_elv_2 , sum_x2_y , sum_x_elv_4]
        ]
    B1=determinante(matriz_aux_B1)/det_matrizA
    
    matriz_aux_B2 =[
            [n           , sum_x       , sum_y],
            [sum_x       , sum_x_elv_2 , sum_xy],
            [sum_x_elv_2 , sum_x_elv_3 , sum_x2_y]
        ]
    B2=determinante(matriz_aux_B2)/det_matrizA
    
    # imprimimos la formula del polinomio 
    print(f"Y^= {B0} + {B1}x + {B2}x^2")

    # retornamos los coeficientes 
    return B0,B1,B2

""" Metricas de rendimiento de los modelos de regresion -----------------"""
# coeficiente de determinacion
def coeficiente_determinacion(y_obs, y_pred):
    
    num=sum([(y_pred[i]-media(y))**2 for i in range(len(y))])
    den=sum([(y_obs[i]-media(y))**2 for i in range(len(y))])

    return  num/den

# error estandar del estimado
def error_estandar_estimado(y_obs, y_pred):
    # Calcular la suma de los cuadrados de las diferencias
    num=sum([(yi-media(y_pred))**2 for yi in y_obs])
    
    return (num / (len(y_obs) - 2)) ** 0.5

""" Resultados ----------------------------------------------------------"""

# Imprimir los resultados
print("desviacion estandar de x:",desviacion_estandar(x))
print("desviacion estandar de y:",desviacion_estandar(y))

print("Coeficiente de correlacion:",coeficiente_de_correlacion(x,y))

print("\n Regrresiones ")
print(f"\n    lineal \n y= {interseccion(x, y)} + {pendiente(x, y)}x")
# predicciones de la fincion de regresion lineal
y_predicciones_reg_lineal = [regresion_lineal(xi) for xi in x]
print("Error estandar del estimado:",error_estandar_estimado(y,y_predicciones_reg_lineal))
print("Coeficiente de determinacion :",coeficiente_determinacion(y,y_predicciones_reg_lineal))

print("\n    polinomial ")
b0,b1,b2 = reg_polinomial_g2(x,y)
reg_poli_g2 = lambda x_p : b0 + (b1*x_p) + (b2*(x_p**2))
# predicciones del modelo de regresion polinomial 
y_predicciones_reg_polinomial = [reg_poli_g2(xi) for xi in x]
print("Error estándar del estimado:", error_estandar_estimado(y, y_predicciones_reg_polinomial))
print("Coeficiente de determinación:", coeficiente_determinacion(y, y_predicciones_reg_polinomial))


# Creamos rango de valores de x a probar en la grafica
x_p = np.linspace(min(x), max(x), 100) 

# Crear valores predecidos de y utilizando los modelos de regresion 
y_lineal = regresion_lineal(x_p)
y_polinomial = reg_poli_g2(x_p)

# Graficar la función
plt.figure(figsize=(8, 6))
plt.plot(x_p, y_lineal, label=f'y = {round(a,2)} + {round(b,2)}x')
plt.plot(x_p, y_polinomial, label=f'y= {round(b0,2)} + {round(b1),2}x + ({round(b2,4)})x^2')
plt.scatter(x, y, color='red', label='Datos')
plt.xlabel('Temperatura')
plt.ylabel('Velocidad')
plt.title('Calidad del Aire')
plt.grid(True)
plt.legend()
plt.show()
