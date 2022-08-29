
import numpy as np
import matplotlib.pyplot as plt 

def f(c):
    return ((668.06)/c)*(1-2.7182**(-((c/68.1)*10)))-40


# grafica
c=np.arange(1,100,1)
plt.plot(c,f(c))
plt.legend()
plt.show()

i=1 # numero de iteraciones
xl=int(input(" ingresa el valor de xl:"))
xu=int(input(" ingresa el valor de xu:"))

es=0.5

xv=14.801

xrant=0

raiz=0

while i<=3:
    
    print("--------------------")

    print(" iteracion ",i)
    print("xl=",xl)
    print("xu=",xu)
    print("f(xl)=",f(xl))
    print("f(xu)=",f(xu))

    xr=xu-((f(xu)*(xl-xu))/(f(xl)-f(xu)))

    print("xr=",xr)

    print("\n errores")
    er=abs(((xv-xr)/xv)*100)
    print("Er=",er)
    ez=abs(((xr-xrant)/xr)*100)
    print("Ea=",ez)

    xrant=xr

    if f(xl)*f(xu)<0:
        xu=xr
    elif f(xl)*f(xu)>0:
        xl=xr
    if er<es:
        raiz=xr
        #break

    i+=1

print(" la raiz de la ecuacion es:",raiz)





"""
from datetime import datetime
import numpy as np
import matplotlib.pyplot as plt 
import os


def execution_time(func):
    def wrapper(*args, **kwargs):
        initial_time = datetime.now()
        func(*args, **kwargs)
        final_time = datetime.now()
        time_elapsed = final_time - initial_time
        print(f'Pasaron {time_elapsed.total_seconds()} segundos de la ejecucion de la funcion ')
        return time_elapsed.total_seconds()
    return wrapper

@execution_time
def x():
    for _ in range(9000000):
        pass

#----------------------------------------------------------------------
def f(c):
    return ((668.06)/c)*(1-2.7182**(-((c/68.1)*10)))-40


# solicitamos el rango de la evaluacion 
xl=int(input(" ingresa el valor de xl:"))
xu=int(input(" ingresa el valor de xu:"))

# error esperado
es=0.5 
# valor verdadero
xv=14.801
# valor auxilar anterior de x
xrant=0
# raiz de la funcion 
raiz=0
# numero de iteraciones
i=1
while True:
    
    print("\n  iteracion ",i)
    print("xl=",xl)
    print("xu=",xu)
    print("f(xl)=",f(xl))
    print("f(xu)=",f(xu))

    xr=(xl+xu)/2
    print("xr=",xr)

    print("\n errores")
    er=abs(((xv-xr)/xv)*100)
    print("Er=",er)
    ez=abs(((xr-xrant)/xr)*100)
    print("Ea=",ez)

    xrant=xr

    if f(xl)*f(xu)<0:
        xu=xr
    elif f(xl)*f(xu)>0:
        xl=xr
    if ez<es:
        raiz=xr
        break

    i+=1
    # vamos limpiando la consola
    # os.system("cls")

print(" la raiz de la ecuacion es:",raiz)
"""
