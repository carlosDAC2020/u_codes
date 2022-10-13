import matplotlib.pyplot as plt 
import numpy as np 

def m(x): # intervalo de 0 a 2
    return 2*2.7182**(-x) - (4*x) # 2e^(-x) -4x

def dm(x): # derivada de la funcion 
    return -2*2.7182**(-x) - 4

# grafica
x=np.arange(0,10,0.01)
plt.plot(x,m(x))
plt.grid()
plt.title("F(x)= 2e^(-x) - 4x")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()



print(" eu metodo desea usar para encontrar la raiz de la funcion ")
print("      F(x)= 2e^(-x) - 4x   ")
print(" 1 Punto fijo ")
print(" 2 Newton-Raphson ")

metodo=int(input(" escoja el metodo con cual evaluar (1/2): "))
xi=int(input("Ingrese el valor inicial de xi: "))

# error esperado
es=0.05

# se guarda el valor anterior de xi+1 para 
# obtener el valor del error relativo
xi1_ant=0

print("-"*45)
print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("i","xi","xi1","er"))
print("-"*45)

# delcaramos el contador de iteraciones
i=1
while True:
    
    # dependiendo el metodo ingresado por el usuario se usara la formula correspondiente 
    if metodo==1:
        xi1=(2*2.7182**(-xi) )/4 # punto fijo
    else:
        xi1= xi -((m(xi))/(dm(xi))) # Newton-Raphson

    # obtenemos el error relativo teniendo en cuenta 
    # el el valor actual y anterior de xi+1
    er=abs((xi1-xi1_ant)/xi1)

    print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format(i,round(xi,6), round(xi1,6), round(er,6)))
    
    # vamos combirtiendo el valoor actual de xi+1 en el valor xi+1 anterior
    # para usarlo en el la iteracion siguiente
    xi1_ant=xi1
    
    # xi+1 pasa a ser xi para evaluarlo en la proxima iteracion
    xi=xi1
    
    # verificampos que el error relativo sea menor al error esperado
    if er<es:
        break # si lo enterior ocurra se detendra el cilo 

    # vamos contando las iteraciones que ocurren 
    i+=1
print("-"*45)

print(" despues de ",i)
print("obtenemos que la raiz de la funcion es:",round(xi,4))