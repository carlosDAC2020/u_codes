

# para trabajar con arrays y operaciones matemáticas
import numpy as np           
# para trabajar con dataframes y leer archivos csv     
import pandas as pd           
# para crear gráficas    
import matplotlib.pyplot as plt   
# para crear un modelo de regresión lineal
from sklearn.linear_model import LinearRegression  
 # para crear características polinómicas
from sklearn.preprocessing import PolynomialFeatures 
 # para calcular el error cuadrático medio
from sklearn.metrics import mean_squared_error      
# para generar un polinomio de lagrange
from scipy.interpolate import lagrange 

# NOTA 
# lenguaje Python 3.11.1
# las librerias utilizadas deben ser instaladas a traves de pip ya q no son nativas de pyython 

# lectura y clasioficacion de los datos ------------------------------------------------------
# Leer los datos de las horas de entrada y salida desde el archivo CSV
df = pd.read_csv('datos.csv', sep=';')
horas_entrada = df["hora de llegada"]
horas_salida = df["hora de salida "]


def regresion():

    # obtencion de los modelos de regrecion -----------------------------------------------------
    # Crear un objeto de regresión lineal y ajustar los datos de entrada y salida
    reg_lineal = LinearRegression()
    reg_lineal.fit(horas_entrada.values.reshape(-1, 1), horas_salida)

    # Crear un objeto de características polinómicas y transformar las horas de entrada
    poly = PolynomialFeatures(degree=2)
    horas_entrada_poly = poly.fit_transform(horas_entrada.values.reshape(-1, 1))

    # Crear un objeto de regresión polinómica y ajustar los datos de entrada y salida transformados
    reg_poly = LinearRegression()
    reg_poly.fit(horas_entrada_poly, horas_salida)


    # ANALISIS ----------------------------------------------------------------------------------------------
    # Calcular la desviación estándar total y el error estándar del estimado
    std_total = np.std(horas_salida)
    error_estimado = np.sqrt(mean_squared_error(horas_salida, reg_lineal.predict(horas_entrada.values.reshape(-1, 1))))

    # Calcular el coeficiente de correlación y el coeficiente de determinación
    coef_corr = np.corrcoef(horas_entrada, horas_salida)[0, 1]
    coef_det_lin = reg_lineal.score(horas_entrada.values.reshape(-1, 1), horas_salida)
    coef_det_poly = reg_poly.score(horas_entrada_poly, horas_salida)

    # crear una figura con dos subplots
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 6))

    # graficar la regresión lineal en el primer subplot
    ax1.scatter(horas_entrada, horas_salida, color='blue')
    ax1.plot(horas_entrada, reg_lineal.predict(horas_entrada.values.reshape(-1, 1)), color='red')
    ax1.set_xlabel('Hora de entrada')
    ax1.set_ylabel('Hora de salida')
    ax1.text(0.1, 0.9, ' y = {}x + {}'.format(round(reg_lineal.coef_[0], 2), round(reg_lineal.intercept_, 2)), transform=ax1.transAxes)
    ax1.set_title('Regresión lineal')


    # graficar la regresión polinómica en el segundo subplot
    ax2.scatter(horas_entrada, horas_salida, color='blue')
    ax2.plot(horas_entrada, reg_poly.predict(horas_entrada_poly), color='green')
    ax2.set_xlabel('Hora de entrada')
    ax2.set_ylabel('Hora de salida')
    ax2.set_title('Regresión polinómica')
    ax2.text(0.1, 0.9, ' y = {}x^2 + {}x + {}'.format(round(reg_poly.coef_.reshape(1, -1)[0][2], 2), round(reg_poly.coef_.reshape(1, -1)[0][1], 2), round(reg_poly.coef_.reshape(1, -1)[0][0], 2)), transform=ax2.transAxes)

    plt.show()

    # Imprimir los resultados
    print("Desviacion estandar total: {:.2f}".format(std_total))
    print("Error estandar del estimado: {:.2f}".format(error_estimado))
    print("Coeficiente de correlacion: {:.2f}".format(coef_corr))
    print("Coeficiente de determinacion (lineal): {:.2f}".format(coef_det_lin))
    print("Coeficiente de determinacion (polinomico): {:.2f}".format(coef_det_poly))


def interpolacion():
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


    print("\n Analisis")
    # obtenemos el grado con menor error relativo porcential promedio 
    grado = errores_relativos.index(min(errores_relativos)) + 1
    print("el grado de interpolacion adecuado del polinomio es el:",grado)
    # obtenemos el polinomio correspondiente 
    polinomio = lagrange(x_impares[:grado+1], y_impares[:grado+1])
    print(" p(x) = ",polinomio)
    
    # generamos graficas 
    fig, axs = plt.subplots(nrows=1, ncols=2, figsize=(10, 5))

    # Graficar los datos y el polinomio de Lagrange 
    axs[0].plot(x_impares, y_impares, 'o', label='datos')
    axs[0].plot(x_pares, polinomio(x_pares), label='polinomio de Lagrange')
    axs[0].set_xlabel('horas de entrada')
    axs[0].set_ylabel('horas de salida')
    axs[0].set_title("polinomio de Lagrange que mejor se ajusta a los datos")
    axs[0].legend()

    # Graficar los errores relativos promedio 
    axs[1].plot(range(1, len(x_pares)), errores_relativos, 'o-')
    axs[1].set_xlabel('Grado de polinomio')
    axs[1].set_ylabel('Error relativo porcentual promedio')
    axs[1].set_title("Promedios de ER vs grados de polinomio")

    plt.show()



if __name__=="__main__":
    print("punto 4.2")
    regresion()

    print("\n\n punto 4.3")
    interpolacion()