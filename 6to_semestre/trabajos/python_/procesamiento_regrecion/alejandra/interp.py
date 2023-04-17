# para trabajar con arrays y operaciones matemáticas
import numpy as np
# para trabajar con dataframes y leer archivos csv
import pandas as pd
# para crear gráficas
import matplotlib.pyplot as plt
# para generar un polinomio de lagrange
from scipy.interpolate import lagrange

# leer los datos de las horas de entrada y salida desde el archivo CSV
df = pd.read_csv('datos.csv', sep=';')
print("Datos \n ",df)
horas_entrada = df["hora de llegada"]
horas_salida = df["hora de salida "]

#seleccionamos los datos en posisciones impares e impares para calcular y evaluar el polinomio de lagrange
x_impares = horas_entrada.values[::2]
y_impares = horas_salida.values[::2]

x_pares = horas_entrada.values[1::2]
y_pares = horas_salida.values[1::2]


# evaluacion del poliniomio de lagrange por cada grado y obtencion del promedio del error relativo porcential por cada grado del polinomio 

# lista que guardara los promedios de los errores relativos por cada gardo 
errores_relativos = []

# usamos un ciclo for para ir evaluadno los polinomios por cada grado 
for grado in range(1, len(x_impares)):

    # optenemos el polinomio de los datos en el grado correspondiente 
    polinomio = lagrange(x_impares[:grado+1], y_impares[:grado+1])
    print("\n\n Polinomio de Lagrange grado",grado,"\n p(x)=", polinomio)

    # lista en la que guardamos los errores relativos obtenidos en cada grado
    errores_relativos_grado = []

    # evaluamos en el polinomio encontramos los valores en posiciones pares ademas de obtener el error relativo porcentaula de cada resultado 
    print("\n evaluacion de valores en posiciones pares ")
    print("-"*86)
    print("|{:^20}|{:^20}|{:^20}|{:^20}|".format("x_pares","p(x_pares)","y medidod","Error relativo %"))
    print("-"*86)
    for i in range(len(x_pares)):
        # valor en posicion par a evaluar
        x_par = x_pares[i]

        # valor de y obtenido del polinomio de lagrange del grado correspondiente
        y_intrp = polinomio(x_par) 

        # valor de y medido previamente
        y_medido = y_pares[i]

        # error relativo porcentual 
        e_r_porcent = abs(( (y_medido - y_intrp) / y_medido )*100)
        print("|{:^20}|{:^20}|{:^20}|{:^20}|".format(x_par, round(y_intrp,2), y_medido, round(e_r_porcent,2)))

        # vamos guardando el error relativo en la lista 
        errores_relativos_grado.append(e_r_porcent)

    print("-"*86)
    
    # obtenemos el promedio de los errores relativos de cada grado y los guradamos en una lista 
    errores_relativos.append(np.mean(errores_relativos_grado))
    print("promedio de errores:",np.mean(errores_relativos_grado))

# graficar los errores relativos porcentuales promedio para cada grado de polinomio
plt.plot(range(1, len(x_pares)), errores_relativos, 'o-')
plt.xlabel('Grado de polinomio')
plt.ylabel('Error relativo porcentual promedio')
plt.show()


print("\n Analisis")
# obtenemos el grado con menor error relativo porcential promedio 
grado = errores_relativos.index(min(errores_relativos)) + 1
print("el grado de interpolacion adecuado del polinomio es el:",grado)
# obtenemos el polinomio correspondiente 
polinomio = lagrange(x_impares[:grado+1], y_impares[:grado+1])
print(" p(x) = ",polinomio)

# graficar los datos y el polinomio de Lagrange
plt.plot(x_impares, y_impares, 'o', label='datos')
plt.plot(x_pares, polinomio(x_pares), label='polinomio de Lagrange')
plt.xlabel('horas de entrada')
plt.ylabel('horas de salida')
plt.legend()
plt.show()
