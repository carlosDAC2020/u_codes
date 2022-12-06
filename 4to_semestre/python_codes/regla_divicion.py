
"""
en un rango de numeros elejisos por el usuario 
mostraremos por pantalla los numeros de dicho 
rango divicibles entre un numero x tambien 
ingresado por el usuario
"""
# ingreso del intervalo

num_A=int(input(" numero de incio del intervalo:"))

num_B=int(input(" numero de final del intervalo:"))

num_div=int(input("numero a evaluara divicibilidad: "))

print("-"*33)
print("|{:^10}|{:^10}|{:^10}|".format("numero","resto","divicible"))
print("-"*33)
while num_A <= num_B:
    resto=num_A%num_div
    if resto==0:
        div="si"
    else:
        div="No"
    # imprimimos resultados 
    print("|{:^10}|{:^10}|{:^10}|".format(num_A,resto,div))
    num_A+=1
print("-"*33)
