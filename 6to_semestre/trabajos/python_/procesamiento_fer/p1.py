
import matplotlib.pyplot as plt 
import numpy as np 
import math
import pylab as pl


# punto 1 y 2 

# SECCION 1-------------------------------------------------------------------
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

# metodos de evaluacion
biseccion = lambda f, xl, xu: (xl+xu)/2
falsa_posicion = lambda f, xl, xu: xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))
#------------------------------------------------------------------------------
    
# SECCION 2 ------------------------------------------------------------------------------
def evaluador(fx,xl,xu, es, xv, mt, max_iter):

    f=fx["f(x)"]

    # grafico de error relativo y aproximado vs el numero de iteraciones 
    graf={
        "er":[],
        "ea":[],
        "iter":[]
    }

    # dependiendo el metoso pasado como parametro hacemos la variable igial a la formula del metodo correspondiente
    metodo = biseccion if mt=="biseccion" else falsa_posicion

    # valor auxilar anterior de x
    xrant=0
    # raiz de la funcion 
    raiz=0
    # numero de iteraciones
    i=1
    while i<max_iter:
        # aplicamos la formula del metodo correspondiente
        xr=metodo(f,xl,xu)
        
        # obtenemos el error relativo y lo vamos añadiendo a la lista de valores para graficarlo despues 
        er=abs(((xr-xrant)/xr)*100)
        graf["er"].append(er)
        # error aproxumado y agregamos a la la lista correspondiente para graficarlo despues 
        ea=abs(((xv-xr)/xv)*100)
        graf["ea"].append(ea)

        # vamos guardando xr en una variable enterior 
        xrant=xr

        if mt=="falsa posicion":
            if f(xl)*f(xu)<0:
                xu=xr
            elif f(xl)*f(xu)>0:
                xl=xr
            if er<es:
                raiz=xr
                break
        else:
            if f(xl)*f(xr)<0:
                xu=xr
            elif f(xl)*f(xr)>0:
                xl=xr
            if er<es:
                raiz=xr
                break

        # vamos sumnado 1  las iteraciones 
        i+=1
    if i==max_iter:
        print(" numero de iteracuones maximas excedido :(")
    else:
        print(" iteraciones = ",i)
        print(" E aproximado = ",ea)
        print(" la raiz de la ecuacion es:",raiz)

        # evluamos la eficiencia de cada metodo respecto al otro
        if i<fx["men iters"]:
            fx["men iters"] = i
            fx["mt_efficient"] = mt

        # graficamos el error relativo y aproximado con respecto a las iteraciones 
        graf["iter"]=[x for x in range(i)] # obtenemos la lista de iteraciones 

        fig, ax = plt.subplots()
        plt.grid()
        ax.set_title('Iteraciones VS Errores relativo y aproximado', loc = "left", fontdict = {'fontsize':14, 'fontweight':'bold', 'color':'tab:blue'})
        ax.plot(graf["iter"], graf["ea"], label = 'Error aproximado' , color = 'tab:blue')
        ax.plot(graf["iter"], graf["er"], label = 'Error relativo' , color = 'tab:green')
        ax.legend(loc = 'upper right')
        ax.grid(axis = 'y', color = 'gray', linestyle = 'dashed')
        ax.set_xlabel("Iteraciones")
        ax.set_ylabel("Error")
        plt.show()
#-----------------------------------------------------------------------------------------
        

# SECCION 3 ------------------------------------------------------------------------------

# graficamos las funciones a evluar 
x = np.linspace(-1, 5, 256, endpoint=True)
plt.plot(x, f1["f(x)"](x), color="blue", linewidth=1.0, linestyle="-", label=f"f1(x) = "+f1["ecu"])
plt.plot(x, f2["f(x)"](x), color="green", linewidth=1.0, linestyle="-", label="f2(x) = "+f2["ecu"])

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
# pregungtamos al usuario que metodo prefiere 
print(" Probaremos los metods de:")
print(" # biseccion")
print(" # falsa posisicion ")

# solicitamos el rango de la evaluacion 
print("\n ingrese los limites de evualuacion ")
xl=int(input(" ingresa el valor de xl : "))
xu=int(input(" ingresa el valor de xu : "))

# obtenemos el error esperado 
cs=int(input(" cifras significativas :"))
es = (0.5*(10**(2-3))) if cs<=2 else (0.5*(10**(2-cs)))
print(" error esperado :",es)

it_min=int(input(" iteraciones minimas para evaluacion : "))

# valor verdadero de la raiz de las funciones 
f1_xv=3.1013
f2_xv= 1.076

# haceos la evaluaciones con cada metodo


print(f"\n para f(x) = {f1['ecu']}")
f1["men iters"] = it_min
print("\n metodo de biseccion")
evaluador(f1 , xl, xu, es, f1_xv, "biseccion", it_min)
print("\n metodo de falsa posicion")
evaluador(f1 , xl, xu, es, f1_xv, "falsa posicion", it_min)
print(" para esta funcion el metodo mas eficiente fue el de ", f1["mt_efficient"]," con ",f1["men iters"], "iteraciones ")

print("-"*30)

print(f"\n para f(x) = {f2['ecu']}")
f2["men iters"] = it_min
print("\n metodo de biseccion")
evaluador(f2 , xl, xu, es, f2_xv, "biseccion", it_min)
print("\n metodo de falsa posicion")
evaluador(f2 , xl, xu, es, f2_xv, "falsa posicion", it_min)
print(" para esta funcion el metodo mas eficiente fue el de ", f2["mt_efficient"]," con ",f2["men iters"], "iteraciones ")


#---------------------------------------------------------------------------------------------------------

# punto 3

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


print("\n aplicando el metodo de falsa posicion modificado con las funciones obtenemos los siguientes resultados")

print("\n  para ",f1["ecu"],"-"*20)
pf_m(f1["f(x)"],xl,xu,es,it_min)


print("\n  para ",f2["ecu"],"-"*20)
pf_m(f2["f(x)"],xl,xu,es,it_min)