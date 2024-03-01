import matplotlib.pyplot as plt 
import numpy as np 
import pylab as pl
from random import randint

# funcion a validar
f = lambda x: 2*(2.7182**(-x)) - (4*x)  
df = lambda x: -2*(2.7182**(-x)) - 4

# metodod de Newton-Raphson
Newton_Raphson =  lambda x,f,df: x -((f(x))/(df(x)))
# metodo de la secante 
Secante = lambda x1, x2, f: x2 - (( f(x2)*(x1-x2) ) / ( f(x1) - f(x2) ))

def evaluator_open_metod(metod, xi, es, name_metod, f, df, x2=0 ):

    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    print("-"*44)
    print("|{:^18}|{:^10}|{:^12}| ".format("iteracion","xr","es"))
    print("-"*44)
    while True:
        # evaluamos xi con el metodod correspondiente 
        if name_metod=="NR": # cuando se evalua el metodo de Newton-Raphson 
            xi1 = metod(xi,f,df)
        else:                   # cuando se evalua el metodo de la secante 
            xi1= metod(xi, x2, f)
            
        # obtenemos el error relativo
        er=abs((xi1-xi1_ant)/xi1)

        # vamos imprimiendo los resultados
        print("|{:^18}|{:^10}|{:^12}| ".format(round(i,5), round(xi1,5), round(er,5)))
        # guardamos el valor enterior 
        xi1_ant=xi1

        # al evaluarse el metodo Newton-Raphson se hara la siguiente asignacion
        if name_metod=="NR":
            xi=xi1
        else: # esto se ejecutara solamente al evaluar el metodo de la secante 
            xi=x2
            x2=xi1
        # interrupcion de la evaluacion 
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    print("-"*44)
    print(" La raiz de la funcion es aproximandamente:",xi1)



def run():
    print(" Evaluaremos las funciones:")
    print(" f1(x) = ln(x) + x - 5")
    

    print("\nn usando los metodos de ")
    print(" # Newton-Raphson ")
    print(" # Secante")

    # grafica de las funciones 
    X = np.linspace(-1, 5, 256, endpoint=True)
    C, S = np.cos(X), np.sin(X)

    plt.plot(X, f(X), color="blue", linewidth=1.0, linestyle="-", label="f1(x) = ln(x) + x - 5")
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

    
    print("\n intervalo de evaluacion de las funciones ")
    li = int(input(" ingresa limite inferior:"))
    ls = int(input("inghresa limite superior:"))
    while ls<li:
        print(" limite superior no puede ser mayor al inferior!")
        ls = int(input("inghresa limite superior:"))

    # asignamos el valor inicial para la evaluacion del metodo con Newton-Raphson tomando un valor en el rango del limite inferior y superior
    Xi=randint(li, ls)

    # solicitamos ala usuario la cantidad de cifras significativas para el error esperado
    print("\n # error esperado ")
    n=int(input(" ingrese la cantidad se cifras significativas para el error esperado:"))
    if n<=2:
        n=3
    es=(0.5*(10**(2-n))) # calculamos el error esperado con base a las cifras significativas ingresadas 
    print(" error esperado:",es)
    
    # evaluacion del metodod de  Newton-Raphson 
    print("\n Metodod de Newton-Raphson ")
    evaluator_open_metod(Newton_Raphson, Xi, es, "NR", f, df)

    # evaluacion del metodod de la Secante 
    print("\n Metodod de Secante  ")
    evaluator_open_metod(Secante, li, es, "SC", f, df, ls)

        
if __name__=="__main__":
    run()