# Carlos Daniel Agamez T00059006
# lenguaje de programacion : Python 3.9.5
# Nrc : 1457
import matplotlib.pyplot as plt 
import numpy as np 

# funcion de la cual obtendremos sus raices 
def f(x):
    return (2.7182**(-x))-x

# derivada de la funcion f(x) declarada anteriormente  
def df(x): # esta sera utilizada en el metodo de Newton-Raphson
    return (-2.7182**(-x))-1


#---------METODOS A EVALUAR----------
def punto_fijo(xi):
    return 2.7182**(-xi)

def  Newton_Raphson(xi):
    return xi - ( f(xi) / df(xi) )
#-----------------------------------

"""
esta funcion metod() ejecuta el proceso de evaluacion del metodo
que ingrese el usuario en la funcion principal
dicho metodo a demas del valor de xi inical son pasados como parametro a la 
funcion meto()
"""
def metod(func,xi):
    # error esperado 
    es=0.00005
    # variable que ira almacenado los valores anteriores de las evauaciones 
    xi1_ant=0
    # contadora de iteraciones 
    i=1
    print("-"*45)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("i","xi","xi1","er"))
    print("-"*45)
    while True:
        # evaluamos xi con el metodod correspondiente 
        xi1 = func(xi)
        # obtenemos el error relativo
        er=abs((xi1-xi1_ant)/xi1)
        # vamos imprimiendo los resultados de la evaluacion
        print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format(i,round(xi,4), round(xi1,4), round(er,4)))
        # guardamos el valor enterior 
        xi1_ant=xi1
        # vamos asignando lso valores obtenidos en xi1 a xi
        xi=xi1
        if er<es:
            break
        # vamos contando las iteraciones 
        i+=1
    print("-"*45)

    print(" dspues de ",i," iteraciones")
    print("obtenemos que la raiz de la funcion es:",round(xi,4))

# funcion principal 
def run():
    # graficamos la funcion 
    x=np.arange(0,1,0.01)
    plt.plot(x,f(x))
    plt.grid()
    plt.title("F(x)= e**(-x) - x")
    plt.xlabel("Y")
    plt.ylabel("X")
    plt.show()

    while True:
        print(" eu metodo desea usar para encontrar la raiz de la funcion ")
        print("      F(x)= e^(-x) - x   ")
        print(" 1 Punto fijo ")
        print(" 2 Newton-Raphson ")

        m=int(input(" escoja el metodo (1/2):"))
        xi=float(input(" ingrese un valor de xi para probar el metodo:"))

        if(m==1):
            print("\n Metodo Punto fijo ")
            metod(punto_fijo,xi)
        else:
            print("\n Metodo Newton-Raphson ")
            metod(Newton_Raphson,xi)

        print("desea probar otra vez el progtrama ?")
        print(" 1 para si")
        print(" 2 para no")
        q=int(input(" ingrese su opcion:"))
        if q==2:
            break


if __name__=="__main__":
    run()