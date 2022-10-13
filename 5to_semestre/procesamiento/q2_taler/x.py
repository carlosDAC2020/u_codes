from cProfile import label
from contextlib import AbstractAsyncContextManager
from re import A
import matplotlib.pyplot as plt 
import numpy as np 
import pylab as pl

"""
f1 = lambda x: np.log(x) + x - 5
df1 = lambda x: (1/x) + 1
f1_punto_fijo = lambda x: -np.log(x) + 5 

# funcion 2
f2 = lambda x: 2*(2.7182**(-x)) - (4*x)  
df2 = lambda x: -2*(2.7182**(-x)) - 4
f2_punto_fijo = lambda x: (2*2.7182**(-x) )/4

# funcion 3
f3 = lambda x: (2.7182**(-x)) - x 
df3 = lambda x: -(2.7182**(-x)) - 1
f3_punto_fijo = lambda x: 2.7182**(-x)


# grafica de las funciones 
X = np.linspace(-1, 5, 256, endpoint=True)
C, S = np.cos(X), np.sin(X)

plt.plot(X, f1(X), color="blue", linewidth=1.0, linestyle="-", label="f1(x) = ln(x) + x - 5")
plt.plot(X, f2(X), color="green", linewidth=1.0, linestyle="-", label="f2(x) = 2e^-x - 4x")
plt.plot(X, f3(X), color="red", linewidth=1.0, linestyle="-", label="f3(x) = e^-x - x")
pl.legend(loc='upper right')

plt.title("Funciones a Evaluar")
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

"""


"""
x=np.linspace(-5,5,1, endpoint=True)
plt.plot(x,f1(x))
plt.plot(x,f2(x))
plt.plot(x,f3(x))
plt.grid()
plt.title("Funciones a evaluar")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()
"""


"""
fig, ax = plt.subplots()
dias = ['L', 'M', 'X', 'J', 'V', 'S', 'D']
temperaturas = {'Madrid':[28.5, 30.5, 31, 30, 28, 27.5, 30.5], 'Barcelona':[24.5, 25.5, 26.5, 25, 26.5, 24.5, 25]}
ax.plot(dias, temperaturas['Madrid'], color = 'tab:purple')
ax.plot(dias, temperaturas['Barcelona'], color = 'tab:green')
plt.show()
"""

fx=lambda x: (2.7182**(-x)) - x 

Secante = lambda x1, x2, f: x2 - (( f(x2)*(x1-x2) ) / ( f(x1) - f(x2) ))

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
    # craemos este diccionario y lista auxiliar para irguaradando los resultado de la evaluacion del metodo 
    list_er=[]
    dict_aux={
        "iter":0,
        "errores_r":[],
        "raiz":0.0
    }
    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    print("-"*56)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("i","x1","x2","xn","er"))
    print("-"*56)
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
        print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|  ".format(i,xi,x2,xi1,er))
        # vamos guardando los errores obtenidos en una lista auxiliar
        list_er.append(er)
        # guardamos el valor enterior 
        xi1_ant=xi1

        # esto se ejecutara solamente al evaluar el metodo de la secante 
        if name_metod=="SC":
            xi=x2
            x2=xi1
        else:
            # vamos asignando lso valores obtenidos en xi1 a xi
            xi=xi1
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    

    # guardamos los resultados de la evaluacion en el diccionario auxiliar
    dict_aux["iter"]=i
    dict_aux["errores_r"]=list_er
    dict_aux["raiz"]=xi

    print(" dspues de ",i," iteraciones")
    print("obtenemos que la raiz de la funcion es:",round(xi,4))

    # retornamos el registro de la evaluacion 
    return dict_aux


def list_length_correction(l1, l2, l3):
     """
    toma como parametros 3 listas de difernte tamaño 
    las da la misma longitud teniendo en cuenta la lista de mayor longitud
    y les asigana a los indices sin valor el numero 8
    """
     ltder={
        len(l1):l1,
        len(l2):l2,
        len(l3):l3,
    }

     len_list=[len(l1), len(l2), len(l3)]
     len_list.sort()
    
     for i in range(len_list[2]):
        if i>len_list[0]-1:
            ltder[len_list[0]].append(0)
        if i>len_list[1]-1:
            ltder[len_list[1]].append(0)
    
     l1 = ltder[len_list[0]]
     l1 = ltder[len_list[1]]
     l1 = ltder[len_list[2]]

def proms_errores_r(l1, l2, l3, tam):
    return [ ( l1[i] + l2[i] + l3[i] ) /3 for i in range(tam)]


def correcion_tamaño_listas(lists):
     # igualamos las lkstas pasadas como parametros al mismo tamaño y agregamos ceros en las posiciones nuevas 
    
     aux_men_may_lists=[len(l) for l in lists ]
     aux_men_may_lists.sort()
    
     for l in lists:
        while len(l) < aux_men_may_lists[-1]:
            l.append(0)
        print(l)

a=[1,3,5,4,3,5,6,76]
b=[2,3,5,6,7]
c=[2,3,4,6,5,6,6,6,4,4,5,6,]

x=[a,b,c]
for l in x:
    print(l)
correcion_tamaño_listas(x)

for l in x:
    print(l)