from io import open

datos=open("python_codes/a.txt","r")

num=datos.readlines()
datos.close()

print(num[0])

x=list(num[0])
print(x,)
x.remove("\n")
print(x)
aux=[]
for i in range(len(x)):
    aux.append(x[i])
    if x[i+1]==",":
        break
print(aux)  
aux=int(aux)
print(aux)
"""
for dato in num:
    d=list(dato)
    d.remove("n")
    d.remove("")
    aux=float(dato)
    ingresos.append(aux)

suma_datos=sum(ingresos)
tamanio=len(ingresos)
print("tamaño",tamanio)
print("promedio",suma_datos/tamanio)
print("fin")

"""

