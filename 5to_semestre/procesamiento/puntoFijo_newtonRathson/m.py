print(" eu metodo desea usar para encontrar la raiz de la funcion ")
print("      F(x)= e^(-x) - x   ")
print(" 1 Punto fijo ")
print(" 2 Newton-Raphson ")

metodo=int(input(" escoja el metodo (1/2):"))
xi=float(input(" ingrese un valor de xi para probar el metodo:"))

if(metodo==1):
    print("\n Metodo Punto fijo ")
else:
    print("\n Metodo Newton-Raphson ")

 
error_esperado=0.0005

xi1_anteriro=0
 
i=1
print("-"*35)
print("i   ","  xi  ","  xi+1  ","  er  ")
print("-"*35)
while True:
    # evaluamos xi con el metodod correspondiente 
    if metodo==1:
        xi1= 2.7182**(-xi)
    else:
        xi1= xi - ( ((2.7182**(-xi))-xi) / ((-2.7182**(-xi))-1) )
    # obtenemos el error relativo
    error_relativo=abs((xi1-xi1_anteriro)/xi1)
    # vamos imprimiendo los resultados de la evaluacion
    print(i,"   ",round(xi,4),"   ", round(xi1,4),"   ", round(error_relativo,4))
    # guardamos el valor enterior 
    xi1_anteriro=xi1
    # vamos asignando lso valores obtenidos en xi1 a xi
    xi=xi1

    if error_relativo<error_esperado:
        break
    # vamos contando las iteraciones 
    i+=1
print("-"*35)

print("la raiz de la funcion es:",round(xi,4))