# para crear gráficas
import matplotlib.pyplot as plt
# para trabajar con arrays y operaciones matemáticas
import numpy as np
# para generar un polinomio de lagrange
from scipy.interpolate import lagrange


#datos a utilizar 
    # variabe independiente x
fuerza_agarre_urnal = [12.266, 13.533, 14.866, 16.3, 16.666, 17.7, 18.033, 19.533, 20.166, 21.132, 21.382, 21.566, 22.233, 22.633, 22.9333, 24.8, 26.666, 26.866, 31.733, 32.433]

    # variable dependiente y 
fuerza_agarre_normal =[19.367, 17.033, 25.833, 27.5, 30.003, 26.467, 22.667, 30.133, 26.094, 27.467, 34.267, 46.167, 40.367, 31.533, 34.867, 36.2, 33.0, 34.267, 44.533, 42.067]

def polinomio_lagrange(x, y):

    # obtenemod el polinomio de lagrange a partir de los valores impares
    x_imp = [x[i] for i in range(len(x)) if i%2!=0]
    y_imp = [y[i] for i in range(len(y)) if i%2!=0]
    pol_lagrange = lagrange(x_imp, y_imp)

    
    # Graficar los datos y el polinomio de Lagrange 
    plt.plot(x_imp, y_imp, 'o', label='datos')
    plt.plot(x_imp, pol_lagrange(x_imp), label='polinomio de Lagrange')
    plt.xlabel('horas de entrada')
    plt.ylabel('horas de salida')
    plt.title("polinomio de Lagrange ")
    plt.legend()
    plt.show()
    """
    

    errores_relativos = []

    # usamos un ciclo for para ir evaluadno los polinomios por cada grado 
    for grado in range(1, len(x_impares)):

        # optenemos el polinomio de los datos en el grado correspondiente 
        polinomio = lagrange(x_imparesc, y_impares[:grado+1])
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

    """
    

polinomio_lagrange(fuerza_agarre_urnal, fuerza_agarre_normal)
