# para trabajar con arrays y operaciones matemáticas
import numpy as np           
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
# para manejo de horas 
import datetime

# funcion para mostrar una tabla de los datos a utilizar
def tabla_de_datos(x,y,name_x,name_y):
    print("Datos a evaluar")
    print("-"*43)
    print("|{:^20}|{:^20}|".format(name_x,name_y))
    print("-"*43)
    for i in range(len(x)):
        print("|{:^20}|{:^20}|".format(x[i], y[i]))
    print("-"*43)

def problema_1():
    # justamos los datos que utilizaremosm 
    # Definimos los datos de la tabla en arrays separados
    horarios = np.array([7, 9, 11, 13, 15, 17])  # en horas
    q_promedio = np.array([13.75, 101.25, 218.75, 306.25, 303.75, 151.25])
    tabla_de_datos(horarios,q_promedio,"Horarios","Q promedio")

    print("\n PUNTO A ")
    # Ajustar un polinomio de grado 5(esto por que es la cantidad de elemntos menos 1 ) a los datos utilizando mínimos cuadrados
    polinomio = np.polyfit(horarios, q_promedio, deg=5)

    # Crear un objeto de polinomio a partir de los coeficientes obtenidos
    # con esta funcion ya se podra predecir un valor de promedio de circulacion 
    q_pol = np.poly1d(polinomio)
    print("Fórmula del polinomio: ")
    print(" Q = ",q_pol)
    
    print("\n PUNTO B ")
    # Estimación del promedio de personas en la oficina a las 10:00 a.m.
    Q_est_10 = q_pol(10)
    print(" El promedio de personas que circulan en la oficina de 10:00 a.m. a 11:00 a.m. es de:", round(Q_est_10,2))

    # Estimación del promedio de personas en la oficina a las 3:00 p.m.
    Q_est_15 = q_pol(15)
    print(" El promedio de personas que circulan en la oficina de 3:00 p.m. a 4:00 p.m. es de:", round(Q_est_15,2))

    print("\n PUNTO C ")
    # obtenemos la hora con mayor promedio de circulacion 
    # inicializamos valores para ir 
    hora_prom_maximo = 7
    prom_circulacion_maximo = q_pol(7)
    for i in range(len(horarios)-1):
        hora = horarios[i]
        # vamos evaluando cada hora para ver en que punto esta el promedio de mayor circulacion
        while hora < horarios[i+1]:
            
            # vamos comparando los valores evaluados y si se cumple la siguiente condicion los valores obtenidos se guardan en variables auxiliares
            if prom_circulacion_maximo < q_pol(hora):
                prom_circulacion_maximo = q_pol(hora)
                hora_prom_maximo = hora

            # vamos sumando 0.1 a las hora de evaluacion para simular los minutos 
            hora+=0.01

            # validamos el salto de hora 
            if hora >= horarios[i]+0.61 and hora <  horarios[i]+0.62 :
                hora = horarios[i]+1
        n=0
    
    # pasamos la hora encontrada a un formato adecuado 
    hora = datetime.time(int(hora_prom_maximo), int((hora_prom_maximo % 1) * 60))
    print(" la hora en la que el promedio de circulacion es ",hora.strftime("%I:%M %p")," con un promedio de ", round(prom_circulacion_maximo,2)," de circulacion")
   

    # Graficar el polinomio obtenido
    x = np.linspace(7, 17, 100)
    y = q_pol(x)

    plt.plot(horarios, q_promedio, 'o', label='Datos')
    plt.plot(x, y, label='Polinomio de interpolación')
    plt.axvline(x=10, color='b', linestyle='--', label='Circulacion de 10:00 a.m. a 11:00 a.m')
    plt.axvline(x=15, color='g', linestyle='--', label='Circulacion de 3:00 p.m. a 4:00 p.m. ')
    plt.axvline(x=hora_prom_maximo, color='r', linestyle='--', label='Hora de mayor circulacion.')
    plt.xlabel('Horario (h)')
    plt.ylabel('Q Promedio (personas)')
    plt.title('Interpolación de valores de Q')
    plt.legend()
    plt.show()



def problema_2():


    # Definir los datos de la tabla en arrays separados
    fuerza = np.array([10, 20, 30, 40, 50, 60, 70, 80]) * 1e4  # Convertir a unidades de N
    elongacion = np.array([0.1, 0.17, 0.27, 0.35, 0.39, 0.42, 0.43, 0.44])
    # mostramos los datos 
    tabla_de_datos(fuerza,elongacion,"Fuerza","Elongacion")

    print("PUNTO A")
    # Seleccionar solo los primeros 4 elementos de los arrays los cuales son los que cumplen con el conportamiendo de la ley de Hook
    fuerza_Hook = fuerza[:4].reshape(-1, 1)
    elongacion_Hook = elongacion[:4]

    # Crear un objeto de regresión lineal y ajustar los datos seleccionados
    reg_lineal = LinearRegression()
    reg_lineal.fit(fuerza_Hook, elongacion_Hook)

    # Mostrar los coeficientes de la regresión lineal
    print(" se obtuvo la siguiente regrecion lienal ")
    print(' y = {}x + {}'.format(reg_lineal.coef_[0], reg_lineal.intercept_))
    print("Coeficiente k del resorte:", reg_lineal.coef_[0])

    print("\n PUNTO B")
    # selecionamos los datos que no se comportan repecto a al ley de Kook
    #fuerza_no_Hook = fuerza[3:8].reshape(-1, 1)
    fuerza_no_Hook = fuerza[3:8].reshape(-1, 1)

    elongacion_no_Hook = elongacion[3:8]
    # Crear un objeto de características polinómicas y transformar la fuerza
    poly = PolynomialFeatures(degree=2)
    fuerza_poly = poly.fit_transform(fuerza_no_Hook.reshape(-1, 1))

    # Crear un objeto de regresión polinómica y ajustar los datos de entrada y salida transformados
    reg_poly = LinearRegression()
    reg_poly.fit(fuerza_poly, elongacion_no_Hook)

    # Obtener los coeficientes del modelo
    print(" se obtuvo la siguiente regrecion polinomial de segundo grado ")
    print(' y = {}x^2 + {}x + {}'.format(reg_poly.coef_[2], reg_poly.coef_[1], reg_poly.intercept_))

    # Crear una gráfica de dispersión de los datos y la recta de regresión lineal
    plt.plot(fuerza, elongacion, 'o', label='Datos')
    plt.plot(fuerza_Hook, reg_lineal.predict(fuerza_Hook), '-', color='green', label='Comportamiento ideal')
    plt.plot(fuerza_no_Hook, reg_poly.predict(fuerza_poly), '--', color='orange', label='Comportamiento no ideal')
    plt.axvline(x=40*1e4, color='r', linestyle='--', label='')
    plt.title("Fuerza vs elongación")
    plt.xlabel("Fuerza (N)")
    plt.ylabel("Elongación (m)")
    plt.legend()
    plt.show()



def problema_3():
    """
    ingresamps los datos suministrados en el enunciado en listas 
    una para los tiempos (en horas) y otra para las temperaturas (en grados Celsius).
    """
    t = [0, 0.4, 0.8, 1.2, 1.6, 2]
    T = [0.55, 0.424688, -0.643984, -1.388816, 7.398512, 48.95]
    # mostramos los datos 
    tabla_de_datos(t,T,"tiempo (Horas)", "temperatura (°C)")

    print("\n PUNTO A")
    """
    obtenemos el polinomio con ayuda de las funciones de numpy np.polyfit y
    np.poly1d, a demas de mostrar la formula obtenida 
    """
    polinomio = np.polyfit(t, T, deg=5)
 
    T_pol = np.poly1d(polinomio)
    print("Fórmula del polinomio: ")
    print("T = ",T_pol)


    print("\n PUNTO 8")
    """
    Para estimar la temperatura interna (T) para un tiempo de 45 minutos (0.75 horas) y para un tiempo de 75 minutos (1.25 horas), podemos simplemente evaluar el polinomio de interpolación en estos tiempos:
    """
    T_45 = T_pol(0.75) 
    T_75 = T_pol(1.25) 
    
    print("Para t = 45 minutos, T = {:.2f}°C".format(T_45))
    print("Para t = 75 minutos, T = {:.2f}°C".format(T_75))

    print("\n PUNGTO C")
    """
    Usando el polinomio encongtrado para estimar la cantiad de tiempo en que el reactor estuvo 
    con unan temperatura por fuera del limite valido de control en este cilo 
    """
    cont_min = 0 # este contador obtendra la cantidad de minutos en que la temepratura estuvo por fiera del rango 
    rango_minut = {} # diccionario en que guardamos los minutos especificos en los que la temperatura no estuvo en el rango
    for i in range(len(t)-1):
        tiempo = t[i]
        while tiempo < t[i+1]:
            # obtenemos la temepratura en ese tiempo especifico 
            # y validamos sim esta ono en el rango
            temp = T_pol(tiempo)
            if temp <= 0:
                rango_minut[tiempo] = temp 
                cont_min+=1
            
            # sumamos un minutos al tiempo evaluado
            tiempo+=0.01
    
    print(" la cantida de tiempo que ls temperatura estuvo fuera de limite de control fue de ",cont_min," minutos")


    # grafica que muestra el comportamiento de los datos y el polinomio encontrado 
    plt.plot(t, T, 'o', label='Datos')
    x = np.linspace(0, 2, 100)
    y = T_pol(x)
    plt.plot(x, y, label='Polinomio de interpolación')
    plt.axvline(x=0.75, color='b', linestyle='--', label=f'Temperatura en 45 minutos :{round(T_45,2)}°C')
    plt.axvline(x=1.25, color='g', linestyle='--', label=f'Temperatura en 75 minutos :{round(T_75,2)}°C')

        # mostramos el rango de tiempo en que la temperatura no esta en el limite valido 
    times = list(rango_minut.keys())
    plt.axvline(x=times[0], color='r', linestyle='--', label='Rango de temperatura no valida')
    for i in range(0,len(times), 5):
        plt.axvline(x=times[i], color='r', linestyle='--')
    plt.title("Ciclo del bio-reactor")
    plt.ylabel('Temperatura (°C)')
    plt.xlabel('Tiempo (Horas) ')
    plt.legend()
    plt.show()


if __name__=="__main__":

    print("\n Problema 1 ","-"*50)
    problema_1()

    print("\n Problema 2 ","-"*50)
    problema_2()

    print("\n Problema 3 ","-"*50)
    problema_3()