import numpy as np 
import math

f1 = { # a esta funcion se aplica mejor la biseccion
    "f(x)" : lambda x : x**3 - 3*x**2 - 1, 
    "ecu" : "x^3 - 3x^2 - 1",
    "men iters":0,
    "mt_efficient":""
} 
f2 = { #  esta funcion se le aplica mejor la falsa posicion
    "f(x)" : lambda x: np.exp(x) - x - 2, 
    "ecu" : "e^x - x - 2",
    "men iters":0,
    "mt_efficient":""
} 


"""
realiza un programa en python que tenga en cuanta lo siguinente para el metodo de falsa posicion modificado
1- 1Graficar.
2- Seleccionar dos valores, uno a la izquierda (a) y otro a la derecha (b).  
3- Evaluar f(a).  
4- Evaluar f(b).  
5- Realizar la primera iteración para obtener X1 mediante la formula:   
    xi = ((a*f(b)) - (b*(f(a)))) / (f(b) - f(a))
6- Evaluar los signos de f(a) y f(X1) y cambiar el valor de a o b, respecto a sus signos.  
7- Cuando se repite un valor de a o b seguido, se toma la mitad del valor de f(a) o f(b). 
8- Hacer la siguiente iteración repitiendo el paso 3, 4 y 5 con sus valores nuevos.  
9- Calcular el error absoluto con la formula:   
    𝑒𝑎𝑏𝑠 = |xi − xi − 1| 
10- Hacer todas las iteraciones que sean necesarias hasta que la respuesta sea menor a la es.
"""

falsa_posicion = lambda f, xl, xu: xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))
f_p_mod = lambda f, a, b: ((a*f(b)) - (b*(f(a)))) / (f(b) - f(a))

def aflsa_posicion_mod(fx, a, b):

    # asignamos la funcion a evalura 
    f=fx["f(x)"]

    fa = f(a)
    fb = f(b)
    
    # iterador
    i=1

    # realizamos evaluacion 
    while True:
        xi = f_p_mod(f, a, b)






# Definimos la tolerancia y el número máximo de iteraciones
es = 1e-6
iteraciones_max = 1000

def pf_m(f,a,b, es, iter_max):

    # Evaluamos f(a) y f(b)
    fa = f(a)
    fb = f(b)

    # Inicializamos el contador de iteraciones
    iteracion = 1

    # valor xi anterior
    xi_ant=0

    # Inicializamos el error absoluto
    error_abs = float("inf")

    # Mientras no se alcance la es y no se hayan hecho demasiadas iteraciones
    while error_abs > es and iteracion <= iter_max:

        # Calculamos la siguiente aproximación
        xi = ((a*f(b)) - (b*f(a))) / (f(b) - f(a))
        
        # Evaluamos f(xi)
        fxi = f(xi)
        
        # Evaluamos los signos de f(a) y f(xi)
        signo_fa = math.copysign(1, fa)
        signo_fxi = math.copysign(1, fxi)
        
        # Si f(xi) tiene el mismo signo que f(a), actualizamos el valor de a
        if signo_fxi == signo_fa:
            a = xi
            fa = fxi
        
        # Si f(xi) tiene el mismo signo que f(b), actualizamos el valor de b
        else:
            b = xi
            fb = fxi
        
        # Calculamos el error absoluto
        error_abs = abs(((xi-xi_ant)/xi))

        # guardamos el xi actual en el anterior 
        xi_ant = xi
        
        # Actualizamos el contador de iteraciones
        iteracion += 1

        # mensaje de confirmacion cuando se superan las iteracoiones maximas
        if iteracion > iter_max:
            print(" iteraciones maximas superadas :(")
        
    # Imprimimos los resultados de esta iteración
    print("Iteración :", iteracion)
    print("Error absoluto :", error_abs)
    print("raiz : ", xi)
    
    


print("\n ingrese los limites de evualuacion ")
a=int(input(" ingresa el valor de xl : "))
b=int(input(" ingresa el valor de xu : "))


cs=int(input(" cifras significativas :"))
es = (0.5*(10**(2-3))) if cs<=2 else (0.5*(10**(2-cs)))
print(" error esperado :",es,"\n")


print(f1["ecu"],"-"*20)
pf_m(f1["f(x)"],a,b,es,100)


print(f2["ecu"],"-"*20)
pf_m(f2["f(x)"],a,b,es,100)