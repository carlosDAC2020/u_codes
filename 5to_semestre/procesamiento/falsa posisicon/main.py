"""
    METODOS DE BISECCION Y FALSA POSICION 
Maria Angeles Gil Arrieta T00061111
Carlos Daniel Agamez Palomino T00059006
curso: 1457
lenguaje de programacion : Python 3.9.5
"""

import matplotlib.pyplot as plt # libreria no nativa de python para el uso de graficas
import numpy as np # libreria no nativa para asignar rango de valores a la grafica
from datetime import datetime # libreria nativa de python para el manejo de fechas 
"""
usamos un decorador para ver cuando tiempo toma 
la ejecucion de las funciones en las que aplicamos 
el metodo cde biseccion y falsa posiscion solo 
para probar cual es mas eficiente 

def execution_time(func):
    def wrapper(*args, **kwargs):
        initial_time = datetime.now()
        func(*args, **kwargs)
        final_time = datetime.now()
        time_elapsed = final_time - initial_time
        print(f'Pasaron {time_elapsed.total_seconds()} segundos de la ejecucion de la funcion ')
        return time_elapsed.total_seconds()
    return wrapper
"""

""" funcin con la que calculamos la velocidad del paracaidista """
def f(c):
    return ((668.06)/c)*(1-2.7182**(-((c/68.1)*10)))-40


" funcion de metodo de la biceccion "
#@execution_time
def biseccion(xl,xu, es, xv):
    # valor auxilar anterior de x
    xrant=0
    # raiz de la funcion 
    raiz=0
    # numero de iteraciones
    i=1
    while True:
        # aplicamos la formula de la biseccion
        xr=(xl+xu)/2
        
        # obtenemos el error relativo
        er=abs(((xv-xr)/xv)*100)

        ez=abs(((xr-xrant)/xr)*100)

        xrant=xr

        if f(xl)*f(xu)<0:
            xu=xr
        elif f(xl)*f(xu)>0:
            xl=xr
        if ez<es:
            raiz=xr
            break

        i+=1
        
    print("\n\n Metodo de la biseccion")
    print(" iteraciones ",i)
    print("xl=",xl)
    print("xu=",xu)
    print("f(xl)=",f(xl))
    print("f(xu)=",f(xu))

    print("xr=",xr)

    print("\n errores")
    print("Er=",er)
    print("Ea=",ez)

    print(" la raiz de la ecuacion es:",raiz)
    



" funcion del metodo de la falsa posision "
#@execution_time
def falsa_posicion(xl, xu, es, xv): 
    # valor auxilar anterior de x
    xrant=0
    # raiz de la funcion 
    raiz=0
    # numero de iteraciones
    i=1
    while True:
        
        xr=xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))
    
        er=abs(((xv-xr)/xv)*100)
    
        ez=abs(((xr-xrant)/xr)*100)
        
        xrant=xr

        if f(xl)*f(xu)<0:
            xu=xr
        elif f(xl)*f(xu)>0:
            xl=xr
        if er<es:
            raiz=xr
            break
        

        i+=1
        
    print("\n\n iteraciones ",i)
    print("xl=",xl)
    print("xu=",xu)
    print("f(xl)=",f(xl))
    print("f(xu)=",f(xu))


    print("\n errores")
    print("Er=",er)
    print("Ea=",ez)
    
    print(" la raiz de la ecuacion es:",raiz)
    


" funciuon pricipal que arranca el programa " 
def run():    
    # grafica
    c=np.arange(1,100,1)
    plt.plot(c,f(c))
    plt.grid()
    plt.title("Velocidad del paracaidista")
    plt.xlabel("velocidad del viento ")
    plt.ylabel("Velocidad del paracaidista")
    plt.show()

    # pregungtamos al usuario que metodo prefiere 
    print(" Probaremos los metods de:")
    print(" # biseccion")
    print(" # falsa posisicion ")
    
    # solicitamos el rango de la evaluacion 
    print("\n ingrese los limites de evualuacion ")
    xl=int(input(" ingresa el valor de xl:"))
    xu=int(input(" ingresa el valor de xu:"))

    # error esperado
    es=0.5 
    # valor verdadero
    xv=14.801

    # llamamos a las funciones de los dos metodos
    biseccion(xl,xu,es,xv)
    falsa_posicion(xl,xu,es,xv)
   

if __name__=="__main__":
    run()
