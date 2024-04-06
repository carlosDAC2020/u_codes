# para trabajar con dataframes y leer archivos csv     
import pandas as pd    
# para crear gráficas    
import matplotlib.pyplot as plt   

import numpy as np

df = pd.read_csv('datos.csv', sep=';')

print("Datos utilizados \n",df,"\n")
x = list(df["Temperatura"])
y = list(df["Velocidad"])


""" 
    buscamos la funcion y^= B0 + B1x + B2x^2 que representa 
    una regresion polinomial de grado 2

    buscamos primero los coeficientes B0, B1 Y B2 los cuales conforman
    la ecuacion general polinomica de segundo grado
                Y^= B0 + B1x + B2x^2
    resolviendo el siguiente sistema de ecuaciones 

        nB0     +  sum(x)B1  + sum(x^2)B2 = sum(y)
     sum(x)B0   + sum(x^2)B1 + sum(x^3)B2 = sum(x*y)
    sum(x^2)B0  + sum(x^3)B1 + sum(x^4)B2 = sum((y^2)*y)
     
    pasamos a obtener las sumatorias señaladas en el sistema anterior 
"""
n = len(x)
sum_x = sum(x)
sum_x_elv_2 = sum([xi**2 for xi in x])
sum_x_elv_3 = sum([xi**3 for xi in x])
sum_x_elv_4 = sum([xi**4 for xi in x])
sum_y = sum(y)
sum_xy = sum([x[i]*y[i] for i in range(len(x))])
sum_x2_y = sum([(x[i]**2)*y[i] for i in range(len(x))])

"""
    acomodamos los valores obtenidos anteriormente 
    en las mayrices correspondientes
"""
matrizA=[
        [n           , sum_x       , sum_x_elv_2],
        [sum_x       , sum_x_elv_2 , sum_x_elv_3],
        [sum_x_elv_2 , sum_x_elv_3 , sum_x_elv_4]
    ]

matrizB=[
    sum_y,
    sum_xy,
    sum_x2_y,
    ]

"""
    imprimimos la matriz obtenida 
"""
print("sistema de ecuacion lineal expresado en forma de matriz:")
i=0
for fila in matrizA:
    for valor in fila:
        print("{:^12}".format(round(valor,2)),end=' ')
    print("|{:^12}\n".format(round(matrizB[i],2)))
    i+=1

"""
    teniendo las matrices listas aplicamos el metodod de Cramer para resolver el sistema de ecuaciones 
"""
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
    obtenemos el determinate de la matriz A
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
print(f"B0=")
for fila in matriz_aux_B0:
    for valor in fila:
        print("{:^12}".format(round(valor,2)),end=' ')
    print()
B0=determinante(matriz_aux_B0)/det_matrizA
print(" ","-"*(36),"=",B0)
print("{:^36}".format(round(det_matrizA,2)))


matriz_aux_B1 =[
        [n           , sum_y    , sum_x_elv_2],
        [sum_x       , sum_xy   , sum_x_elv_3],
        [sum_x_elv_2 , sum_x2_y , sum_x_elv_4]
    ]
print(f"B1=")
for fila in matriz_aux_B1:
    for valor in fila:
        print("{:^12}".format(round(valor,2)),end=' ')
    print()
B1=determinante(matriz_aux_B1)/det_matrizA
print(" ","-"*(36),"=",B1)
print("{:^36}".format(round(det_matrizA,2)))


matriz_aux_B2 =[
        [n           , sum_x       , sum_y],
        [sum_x       , sum_x_elv_2 , sum_xy],
        [sum_x_elv_2 , sum_x_elv_3 , sum_x2_y]
    ]
print(f"B2=")
for fila in matriz_aux_B2:
    for valor in fila:
        print("{:^12}".format(round(valor,2)),end=' ')
    print()
B2=determinante(matriz_aux_B2)/det_matrizA
print(" ","-"*(36),"=",B2)
print("{:^36}".format(round(det_matrizA,2)))

"""
    resultados
"""
print(" se tiene entocnes que la regrecion polinomial de grado 2 que mejor se ajusta a nuestras variables es :")
print(f"Y^= {B0} + {B1}x + {B2}x^2")

reg_poli = lambda x_p :B0 + (B1*x_p) + (B2*(x_p**2))


# Crear valores de x_p
x_p = np.linspace(min(x), max(x), 100)  # valores de -10 a 10, con 100 puntos en total

# Crear valores de y_p utilizando la función reg_poli
y_p = reg_poli(x_p)

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



