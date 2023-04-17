

import matplotlib.pyplot as plt 
import numpy as np 
import pylab as pl
from random import uniform
from math import sqrt

"""
declaramos las funciones evaluar y a partisr de estas obtenemos:
    # exprecion de la funcion 
    # derivadas 
    # exprecion para el metodo de punto fijo 
"""
# punto 3.2.1 -------------------------------------------------------------------------
def f_p3_2_1(a,D=None): # funcion
    if D==None:
        D=55 #30
    A = 89*np.sin(np.radians(11.5))
    B = 89*np.cos(np.radians(11.5))
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D) 

    return (A*np.sin(np.radians(a))*np.cos(np.radians(a))) + (B*(np.sin(np.radians(a)))**2) - (C*np.cos(np.radians(a))) - (E*np.sin(np.radians(a)))
    # f(a) = Asen(a)cos(a) + Bsen^2(a) - Ccos(a) - Esen(a)

def df_p3_2_1(a, D=None): # derivada 
    if D==None:
        D=55
    A = 89*np.sin(np.radians(11.5))
    B = 89*np.cos(np.radians(11.5))
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D)


    return (A*np.cos(np.radians(a))*np.sin(np.radians(a))) + ((2*B)*((np.sin(np.radians(a)))**2)*(np.cos(np.radians(a)))) - (C*np.sin(np.radians(a))) - (E*(np.cos(np.radians(a)))*(np.sin(np.radians(a))))

    # f'(a) = 𝑨𝒄𝒐𝒔(𝜶)𝒔𝒆𝒏(𝜶) + 2𝑩𝒔𝒆𝒏^2(𝜶)𝒄𝒐𝒔(𝜶) - 𝑪𝒔𝒊𝒏(𝜶) - 𝑬𝒄𝒐𝒔(𝜶)𝒔𝒆𝒏(𝜶)


def p3_2_1_punto_fijo(a, D=None): # forma de punto fijo 
    if D==None:
        D=55
    A = 89*np.sin(np.radians(11.5))
    B = 89*np.cos(np.radians(11.5))
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D)

    num = C * np.cos(np.radians(a)) + E * np.sin(np.radians(a))
    den = A * np.cos(np.radians(a)) + B * np.sin(np.radians(a))**2
    return num / den
    # 𝑔(𝜶) = [𝐶cos(𝜶) + 𝐸sen(𝜶)] / [𝐴cos(𝜶) + 𝐵sen^2(𝜶)]

# punto 3.2.2 -------------------------------------------------------------------------
f_p3_2_2 = lambda h : 12.4 - (10*((0.5*np.pi) - np.arcsin(h) - h*((1-h**2)**0.5))) # funcion 
df_p3_2_2 = lambda h : 20 * sqrt(1-h**2) # derivada
p3_2_2_punto_fijo = lambda h: np.sin(0.5*np.pi - (12.4 - h)/10 - h*np.sqrt(1 - h**2)) # forma del punto dijo 


# registro mde las funciones disponibles a evalur 
funciones=[
    # registro de la funcion punto 3.2.2
    {
        "funcion":"f(a) = Asen(a)cos(a) + Bsen^2(a) - Ccos(a) - Esen(a) ",
        "f(x)": f_p3_2_1,
        "f'(x)": df_p3_2_1,
        "m_punto_fijo": p3_2_1_punto_fijo,
    },
    # registro de la funcion punto 3.2.2
    {
        "funcion":"f(h) = 12.4 - 10[0.5pi - arcsen(h) - h(1 - h^2)^1/2]",
        "f(x)": f_p3_2_2,
        "f'(x)": df_p3_2_2,
        "m_punto_fijo": p3_2_2_punto_fijo
    }
]

#---------------------------------------------------------------------------------------------------------------

# metodod de Newton-Raphson
Newton_Raphson =  lambda x,f,df: x -((f(x))/(df(x)))
# metodo de la secante 
Secante = lambda x1, x2, f: x2 - (( f(x2)*(x1-x2) ) / ( f(x1) - f(x2) ))
# Biseccion
def biseccion(xl,xu, es, f):
    
    # contador de iteraciones 
    i=1
    # variable que ira almacenado los valores anteriores de las evauaciones 
    xrant=0

    # realizamos la evaulacion de la funcion por medio del metodo correspondiente
    print("-"*34)
    print("|{:^10}|{:^10}|{:^10}|".format("iter", "raiz apr", "ER"))
    print("-"*34)
    while True:

        # aplicamos la formula de la biseccion
        xr=(xl+xu)/2
        
        # obtenemos el error relativo
        er=abs(((xr-xrant)/xr)*100)

        # vamos imrimiendo los resultados 
        print("|{:^10}|{:^10}|{:^10}|".format(i, round(xr,5), round(er,5)))

        xrant=xr

        if f(xl)*f(xr)<0:
            xu=xr
        elif f(xl)*f(xr)>0:
            xl=xr
        if er<es:
            raiz=xr
            break

        i+=1
    print("-"*34)
    print(" raiz : ",xr)
    

#---------------------------------------------------------------------------------------------------------------


def evaluator_open_metod(metod, xi, es, name_metod, f=0, df=0, x2=0 ):

    """
    funcion que evalua el metodo conrrespondiente ya sea:
        # punto fijo 
        # Newton-Raphson 
        # secante

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
    # realizamos la evaulacion de la funcion por medio del metodo correspondiente
    print("-"*34)
    print("|{:^10}|{:^10}|{:^10}|".format("iter", "raiz apr", "ER"))
    print("-"*34)
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
        # vamos imprimiendo los resultados de la evaluacion 
        print("|{:^10}|{:^10}|{:^10}|".format(i, round(xi1,5), round(er,5)))
        # guardamos el valor enterior 
        xi1_ant=xi1
        # al evaluarse el metodo de punto fijo y Newton-Raphson se hara la siguiente asignacion
        if name_metod=="PF" or name_metod=="NR":
            xi=xi1
        else: # esto se ejecutara solamente al evaluar el metodo de la secante 
            xi=x2
            x2=xi1
        # criterio de parada de la evaulacion 
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    print("-"*34)
    print(" raiz : ",xi1)



# grafica 
def grafica(f,ecu):
    # grafica de las funciones 
    X = np.linspace(-10, 50, 256, endpoint=True)

    plt.plot(X, f(X), color="green", linewidth=1.0, linestyle="-", label=ecu)
    pl.legend(loc='upper right')

    plt.title("Funcion a Evaluar")
    plt.xlabel("X")
    plt.ylabel("Y")

    ax = pl.gca()  # gca stands for 'get current axis'
    ax.spines['right'].set_color('none')
    ax.spines['top'].set_color('none')
    ax.xaxis.set_ticks_position('bottom')
    ax.spines['bottom'].set_position(('data',0))
    ax.yaxis.set_ticks_position('left')
    ax.spines['left'].set_position(('data',0))

    plt.show()

if __name__=="__main__":

    print(" Parcial procesamiento numerico \n")
    
    print(" Escoga el punto a evaluar a evaluar :")
    print(" 1-> 3.2.1")
    print(" 2-> 3.2.2")
    func_op = int(input("----->"))
    while func_op<1 or func_op>2:
        print(" avlor ingresado no valido!!\n dijite su opcion otra ves ")
        func_op = int(input("----->"))
    func_op = func_op - 1

    # mostramos la grafica de la funcion selecionada 
    grafica(funciones[func_op]["f(x)"], funciones[func_op]["funcion"])

    print("\n que metodos desea usar para evaluar ?")
    print(" 1-> punto fijo ")
    print(" 2-> Newton-Raphson ")
    print(" 3-> Secante")
    print(" 4-> Biseccion")
    method_op = int(input("----->"))
    while method_op<1 or method_op>4:
        print(" avlor ingresado no valido!!\n dijite su opcion otra ves ")
        method_op = int(input("----->"))


    print("\n intervalo de evaluacion de las funciones ")
    li = int(input(" ingresa limite inferior:"))
    ls = int(input("inghresa limite superior:"))
    while ls<li:
        print(" limite superior no puede ser mayor al inferior!")
        ls = int(input("inghresa limite superior:"))

    # valor inical para evaluar los metodos abiertos 
    Xi=uniform(li, ls)

    # solicitamos ala usuario la cantidad de cifras significativas para el error esperado
    print("\n # error esperado ")
    n=int(input(" ingrese la cantidad se cifras significativas para Es:"))
    if n<=2:
        n=3
    es=(0.5*(10**(2-n))) # calculamos el error esperado con base a las cifras significativas ingresadas 
    print(" error esperado:",es)
    i=1


    # evitamos que se generen errores futuros por las caracteristicas de las funciones utilizadas 
    if li==0 or Xi==0 or Xi==1:
        if li==0:
            li+=0.1
        elif Xi==0:
            Xi+=0.1 
 
    
    print("\n evaluammos la funcion ",funciones[func_op]["funcion"])
    # cuando el metodo es habierto 
    if method_op<4:
        if method_op==1:
            # evaluacion del metodod de punto fijo 
            print(" punto fijo ")
            evaluator_open_metod(funciones[func_op]["m_punto_fijo"],Xi,es, "PF")
        elif method_op==2:
            # evaluacion del metodod de  Newton-Raphson 
            print(" Newton_Raphson")
            evaluator_open_metod(Newton_Raphson, Xi, es, "NR", funciones[func_op]["f(x)"], funciones[func_op]["f'(x)"])
        else:
            # evaluacion del metodod de la Secante 
            print(" Secante")
            evaluator_open_metod(Secante, li, es, "SC", funciones[func_op]["f(x)"], funciones[func_op]["f'(x)"], ls)
    # en caso se evalue con el metodode Biseccion 
    else: 
        print(" Biseccion")
        biseccion(li, ls, es, funciones[func_op]["f(x)"])
    
    
    

