import matplotlib.pyplot as plt 
import numpy as np

def s(x): # intervalo de 1 a 2
    return np.log(x) + x - 5


# grafica
x=np.arange(1,10,0.01)
plt.plot(x,s(x))
plt.grid()
plt.title("F(x) = ln(x) + x - 5 ")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()

print(" encontrar la raiz de  ")
print("      F(x)= ln(x) + x - 5   ")

# solicitamos a usuario el metodo que wuiere utilizar
print("\n escoja el metodo con cual evaluar ")
print(" 1 para Punto fijo ")
print(" 2 para Newton-Raphson ")
m=int(input(" dijite el valor el valor correspondiente:"))
# validamos que el usuario ingrese solo las opciones correspondientes 
while m<1 or m>2:
    print(" ingrese 1 o 2")
    m=int(input(" ingresa el metodo nuevamente: "))

Xi=int(input("\n Dijite el valor inicial de xi: "))

# declaramos el error esperado
E_esperado=0.005

# se guarda el valor anterior de xi+1 para 
# obtener el valor del error relativo
Xi1_anteriror=0

print("-"*35)
print("i   ","  xi  ","  xi+1  ","  er  ")
print("-"*35)

# delcaramos el contador de iteraciones
iteracion=1
while True:
    
    # dependiendo el metodo ingresado por el usuario se usara la formula correspondiente 
    if m==1:
        Xi1= -np.log(Xi) + 5 # punto fijo
    elif m==2:
        Xi1= Xi - ((np.log(Xi) + Xi - 5)/((1/Xi)+1)) # Newton-Raphson

    # obtenemos el error relativo teniendo en cuenta 
    # el el valor actual y anterior de xi+1
    E_relativo=abs((Xi1 - Xi )/Xi1)

    print(iteracion,"   ",round(Xi,4),"   ", round(Xi1,4),"   ", round(E_relativo,4))
    
    # xi+1 pasa a ser xi para evaluarlo en la proxima iteracion
    Xi=Xi1
    
    # verificampos que el error relativo sea menor al error esperado
    if E_relativo<E_esperado:
        break # si lo enterior ocurra se detendra el cilo 

    # vamos contando las iteraciones que ocurren 
    iteracion = iteracion + 1
print("-"*35)

print(" la raiz de la funcion es:",Xi)