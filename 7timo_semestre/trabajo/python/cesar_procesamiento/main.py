""" 
NOTA

- la slibrerias utilizadas no son nativas de python ny deben ser instaladas
usando el comando:
        pip install numpy matplotlib
compatibles de la vercion python 3.6 en adelante 
si no se instakan estas librerias el programa no correra

- para probar las funciones que corresponden a cada punto descomentar 
la invocacion de la funcion 
"""
import numpy as np
import matplotlib.pyplot as plt

# metodod de Newton-Raphson
Newton_Raphson =  lambda x,f,df: x -((f(x))/(df(x)))
# metodo de la secante 
Secante = lambda x1, x2, f: x2 - (( f(x2)*(x1-x2) ) / ( f(x1) - f(x2) ))
def evaluator_open_metod(metod, xi, es, name_metod, f=0, df=0, x2=0 ):
    """
    funcion que evalua el metodo conrrespondiente ya sea:
        # punto fijo 
        # secante
        # Newton-Raphson

    esata funcion recive algunos parametros necesarios para la evaluacion segundo el metodo
    en cuestion las esenciales seran :
         ---------- obligatorios en los 3 ---------------------------------- 
        metod: funcion que contendra la formula del metodo correspondiente segun la funcion
        xi: valor inical de evaluacion
        es: error esperado
        name_metodo: especifica el metodo usado en el moneto de ejecucion de la funcion
        
        ---------- obligatorios en Newton-Raphson ---------------------------
        f : formula general de la funcion a evaluar
        df : formula de la derivada de la funcion a evaluar

        --------- obligatorios en en secante --------------------------------
        x2 : segundo valor inicial para evaluar la funcion usando el metodode la secante

        NOTA
        en caso de que un parametro no sea obligatorio para alguno de las metodos 
        ingrese un 0 en su lugar, 
        para los metodos no obligatorios se les dara un valor predeterminado de 0

    """

    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    print("-"*45)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|".format("iteracion","xi","xi1","er"))
    print("-"*45)
    while True:
        # evaluamos xi con el metodod correspondiente 
        if name_metod=="PF": # cuando se evalua el metodod de punto fijo 
            xi1 = metod(xi)
        elif name_metod=="NR": # cuando se evalua el metodo de Newton-Raphson 
            xi1 = metod(xi,f,df)
        else:                   # cuando se evalua el metodo de la secante 
            xi1= metod(xi, x2, f)
            
        # obtenemos el error relativo
        er=abs((xi1-xi1_ant)/xi1)

        print("|{:^10}|{:^10}|{:^10}|{:^10}|".format(i,round(xi,4),round(xi1,4),round(er,4)))
        # guardamos el valor enterior 
        xi1_ant=xi1

        # al evaluarse el metodo de punto fijo y Newton-Raphson se hara la siguiente asignacion
        if name_metod=="PF" or name_metod=="NR":
            xi=xi1
        else: # esto se ejecutara solamente al evaluar el metodo de la secante 
            xi=x2
            x2=xi1
        
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    print("-"*45)
    
    raiz = xi
     
    return raiz

# Biseccion
def biseccion(xl,xu, es, f):
     
    # contador de iteraciones 
    i=1
    # variable que ira almacenado los valores anteriores de las evauaciones 
    xrant=0
    print("-"*55)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|".format("iteracion","xl","xu","xr","er"))
    print("-"*55)
    while True:

        # aplicamos la formula de la biseccion
        xr=(xl+xu)/2
        
        # obtenemos el error relativo
        er=abs(((xr-xrant)/xr)*100)

        print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|".format(i,round(xl,4),round(xu,4),round(xr,4),round(er,4)))
        
        xrant=xr

        if f(xl)*f(xr)<0:
            xu=xr
        elif f(xl)*f(xr)>0:
            xl=xr
        if er<es:
            raiz=xr
            break

        i+=1
    print("-"*55)

    return raiz

def falsa_posicion(xl, xu, es, f, xv=None, itermax=None): 
    # raiz de la funcion 
    raiz=0
    # x anterior 
    xrant=0
    # numero de iteraciones
    i=1
    print("-"*55)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|".format("iteracion","xl","xu","xr","er"))
    print("-"*55)
    while True:
        
        xr=xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))
    
        # obtenemos el error relativo
        if xv!=None:
            er=abs(((xv-xr)/xv)*100)
        else:
            er=abs(((xr-xrant)/xr)*100)
        
        print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|".format(i,round(xl,4),round(xu,4),round(xr,4),round(er,4)))
        
        xrant=xr

        if f(xl)*f(xu)<0:
            xu=xr
        elif f(xl)*f(xu)>0:
            xl=xr
        if er<es:
            raiz=xr
            break
        if i==itermax:
            raiz=xr
            break

        i+=1
    print("-"*55)

    return raiz 
  

def graficar_funcion(funcion_matematica, rango_x=(-10, 10), puntos=1000):
    """
    Grafica una función matemática.

    Args:
        funcion_matematica (lambda): La función matemática como una lambda function.
        rango_x (tuple): El rango de valores de x para la gráfica (inicio, fin).
        puntos (int): La cantidad de puntos a generar para la gráfica.
    """
    x = np.linspace(rango_x[0], rango_x[1], puntos)
    y = [funcion_matematica(x_i) for x_i in x]

    plt.figure(figsize=(8, 6))
    plt.plot(x, y, label="Función")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title("Gráfica de la Función Matemática")
    plt.grid(True)
    plt.legend()
    plt.show()



"""                     Capitulo 5                                      """

"""-- ejersicio 5.5 ----------------------------------------------------------------
Localice la primera raíz no trivial de sen x = x^2, donde x está en
radianes. Use una técnica gráfica y bisección con un intervalo inicial
de 0.5 a 1. Haga el cálculo hasta que ea sea menor que es = 2%. 
Realice también una prueba de error sustituyendo la respuesta final en la
ecuación original.
"""

def p_5_5():
    # funcion a evaluar 
    f= lambda x: np.sin(x) - (x**2)
    xl=0.5
    xu=1
    es=0.02
    graficar_funcion(f, rango_x=(-5, 5), puntos=1000)
    raiz=biseccion(xl,xu,es,f)
    print("la raiz es :",raiz)

#p_5_5()


"""-- ejersicio 5.9 -----------------------------------------------------------------
Encuentre la raíz positiva más pequeña de la función (x está en
radianes) x^2 * |cos(sqrt(1))| = 5 usando el método de la falsa posición. Para
localizar el intervalo en donde se encuentra la raíz, grafique primero
esta función para valores de x entre 0 y 5. Realice el cálculo hasta
que ea sea menor que es = 1%. Compruebe su respuesta final sustituyéndola en la función original. 
"""
def p_5_9():
    f= lambda x: (x**2) * abs(np.cos(np.sqrt(x))) -5
    xl=0
    xu=5
    es=0.01
    graficar_funcion(f, rango_x=(-5, 5), puntos=1000)
    raiz=falsa_posicion(xl, xu, es,f)
    print("la raiz es :",raiz)

#p_5_9()

"""-- ejersicio 5.17 -----------------------------------------------------------------
Suponga el lector que está diseñando un tanque esférico (véase la figura P5.17) 
para almacenar agua para un poblado pequeño en un país en desarrollo. 
El volumen de líquido que puede contener se calcula con
 v = (π*h^2)*((|3R-h|)/(3))

donde 
    V = volumen [m^3]
    h = profundidad del agua en el tanque [m]y
    R = radio del tanque [m].

Si R = 3 m, ¿a qué profundidad debe llenarse el tanque de modo que 
contenga 30 m^3? Haga tres iteraciones con el método de la falsa posición 
a fin de obtener la respuesta. Determine el error relativo aproximado 
después de cada iteración. Utilice valores iniciales de 0
y R.
"""

def p_17():
    f= lambda x:  (np.pi * x**2) * (abs((3*3)-x)/(3)) - 30 
    xl=0
    xu=3
    es=0.5
    graficar_funcion(f, rango_x=(-5, 5), puntos=1000)
    raiz=falsa_posicion(xl, xu, es,f)
    print("la raiz es :",raiz)
    

#p_17()

"""-- ejersicio 5.19 -----------------------------------------------------------------
De acuerdo con el principio de Arquímedes, la fuerza de flotación 
es igual al peso de fluido desplazado por la porción sumergida
de un objeto. Use la bisección para determinar la altura h de la porción que queda encima del agua. Utilice los siguientes valores para su cálculo: 
r = 1 m, 
ps = densidad de la esfera = 200 kg/m^3
pw = densidad del agua = 1000 kg/m^3
Observe que el volumen de la porción de la esfera por encima
del agua se puede calcular mediante

V = ( (πh^2) / (3) ) * (3r - h)
"""
def p_17():
    f= lambda x:  ((np.pi * x**2)/3) * (3*3 - x)
    xl=0
    xu=3
    es=0.5
    graficar_funcion(f, rango_x=(-5, 5), puntos=1000)
    raiz=falsa_posicion(xl, xu, es,f)
    print("la raiz es :",raiz)
    

#p_17() no completada 

"""                 capitulo 6                      """

"""-- ejersicio 6.1 -----------------------------------------------------------------
Utilice la iteración simple de punto fijo para localizar la raíz de
    F(x) = sen(sqrt(x)) - x
"""
def p_6_1():
    f = lambda x: -np.sin(np.sqrt(abs(x)))
    xi = 1
    es = 0.01
    graficar_funcion(f, rango_x=(-50, 50), puntos=1000)
    raiz=evaluator_open_metod(f,xi,es, "PF")
    print("la raiz es :",raiz)
    

#p_6_1() con completada 

"""-- ejersicio 6.2 -----------------------------------------------------------------
Determine la raíz real más grande de
    f(x) = 2x^3 - 11.7x^2 + 17.7x - 5
a) En forma gráfica.
b) Con el método de iteración simple de punto fijo (tres iteraciones,
x0 = 3). Nota: Asegúrese de haber desarrollado una solución que
converja a la raíz.
"""
def p_6_2():
    f = lambda x: (-2*x**3 + 11.7*x**2 + 5)/17.7
    xi = 3
    es = 0.01
    graficar_funcion(f, rango_x=(-50, 50), puntos=1000)
    raiz=evaluator_open_metod(f,xi,es, "PF")
    print("la raiz es :",raiz)

#p_6_2()

"""-- ejersicio 6.9 -----------------------------------------------------------------
Determine la raíz real más grande de 
    f(x) = x^3 - 6x^2 + 11x - 6.1
a) En forma gráfica.
b) Con el uso del método de Newton-Raphson (tres iteraciones, xi = 3.5).
c) Con el método de la secante (tres iteraciones, xi + 1 = 2.5 y xi = 3.5).
"""
def p_6_9():
    f = lambda x: x**3 - 6*x**2 + 11*x - 6.1
    df = lambda x: 3*x**2 - 12*x + 11
    
    graficar_funcion(f, rango_x=(-50, 50), puntos=1000)

    print("punto A \n usando Newton-Raphson")
    xi = 3.5
    es = 0.05
    raiz=evaluator_open_metod(Newton_Raphson,xi,es, "NR",f, df)
    print("la raiz es :",raiz)

    print("punto B \n usando secante")
    xi = 3.5
    x2 = 2.5
    es = 0.05
    raiz=evaluator_open_metod(Secante, xi, es, "SEC", f, df, x2)
    print("la raiz es :",raiz)

#p_6_9()
