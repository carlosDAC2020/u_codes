# punto 1
# llenar una lista con n numeros pares del 2 qal 100

n = int(input("ingrese el valor de n:"))
l1 = [0 for i in range(n)]
tam=0
i=1
while tam<n:
    if i%2==0:
        l1[tam]=i
        tam+=1
    i+=1
print(l1)

# punto 2
# Dada la siguiente tupla de 125 números enteros aleatorios entre 1 y 20:

tupla=(11,11,2,9,5,9,4,8,18,8,10,5,14,19,10,9,16,17,5,8,6,5,19,20,2,10,16,5,2,13
,7,13,18,5,14,15,8,15,5,8,16,14,16,3,1,3,8,2,19,17,8,5,13,15,2,17,4,6,8,20,15,10
,11,14,5,19,8,14,5,16,18,12,9,18,10,4,8,5,4,18,16,7,8,16,8,2,16,17,7,2,6,7,17,1,
14,3,13,8,17,11,11,2,9,5,9,4,8,18,8,10,5,14,19,10,9,16,17,5,8,6,5,19,20,8,6)

# Realice un algoritmo en Python que calcule:
# 1. La cantidad de números pares y la cantidad de números impares
cant_n_par=0
cant_n_impar=0
for i in tupla:
    if i%2==0:
        cant_n_par+=1
    else:
        cant_n_impar+=1
print("\n evaluamos la siguiente tupla \n",tupla)
print("cantidad de numeros pares:",cant_n_par)
print("cantidad de numeros impares:",cant_n_impar)
# 2. El porcentaje de números pares y el porcentaje de números impares
print("porcentaje de numeros pares:",(cant_n_par/125)*100,"%")
print("porcentaje de numeros impares:",(cant_n_impar/125)*100,"%")
# 3. El promedio de números pares y promedio de números impares
sum_pares=0
sum_impares=0
for i in tupla:
    if i%2==0:
        sum_pares+=i
    else:
        sum_impares+=i
print("promedio de numeros pares:",sum_pares/cant_n_par)
print("promedio de numeros impares:",sum_impares/cant_n_impar)
# 4. El mayor número par y el mayor número impar
may_num_par=0
may_num_impar=0
for i in tupla:
    if i%2==0 and i>may_num_par:
        may_num_par=i
    elif i%2!=0 and i>may_num_impar:
        may_num_impar=i
print(" mayor numero par:",may_num_par)
print(" mayor numero impar:",may_num_impar)

# 5. El menor número par y el menor número impar
men_num_par=9999
men_num_impar=999
for i in tupla:
    if i%2==0 and i<men_num_par:
        men_num_par=i
    elif i%2!=0 and i<men_num_impar:
        men_num_impar=i
print(" menor numero par:",men_num_par)
print(" menor numero impar:",men_num_impar)

# punto 3
# A partir de la tupla del segundo punto, obtener una lista con los números pares y mostrar el número
# par que tiene mayor número de repeticiones. De igual forma con los números impares.

num_par_may_rep=-9
cant_rep_par=0
num_impar_may_rep=-9
cant_rep_impar=0

for i in range(1,21):
    cant_rep=0
    for num in tupla:
        if i==num:
            cant_rep+=1
    
    if i%2==0 and cant_rep>cant_rep_par:
        num_par_may_rep=i
        cant_rep_par=cant_rep
    
    elif i%2!=0 and cant_rep>cant_rep_impar:
        num_impar_may_rep=i
        cant_rep_impar=cant_rep
print("el numero par con mayor numero de repeticiones es ",num_par_may_rep," con ",cant_rep_par," repeticiones")
print("el numero impar con mayor numero de repeticiones es ",num_impar_may_rep," con ",cant_rep_impar," repeticiones")