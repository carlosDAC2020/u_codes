
# ingreso de cantidad de valores
cant=int(input(" cantidad de valores a ingresar."))

l_val=[] # lista donde seran guardados los valores

#ingreso de numeros 
print(" ingreso de valores")
for i in range(cant):
    val=int(input("--> "))
    l_val.append(val)

r_val=l_val
# varuables auxiliares
v1=l_val[1] # almacena el menor elemento de la lista
v2=l_val[1] # almacena el mayor elemento de la lista

# hayamos los extremos de la cuenta
for i in range(cant):
    # hayamos el elemento menor
    if v1>l_val[i]:
        v1= l_val[i]
    
    # hayamos el elemento nayor
    if v2<l_val[i]:
        v2=l_val[i]


# proceso para encontrae los numero restantes de la cuenta
while v1<=v2:    
    l_val.append(v1)
    v1+=1

l_val=set(l_val)

l_val=list(l_val)

# ordenamos la lista ya con todos los elementos del rango del conteo
for i in range(len(l_val)-1,0,-1):
    for y in range(i):
        if l_val[y] > l_val[y+1]:
            aux=l_val[y]
            l_val[y]=l_val[y+1]
            l_val[y+1]


print("\n conteo")
for i in range(len(l_val)):
    print(l_val[i],end=" ")



