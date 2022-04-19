from random import randint

# variables auxiliares para sacar los promedios 
sum_positivos=0
cant_positivos=0

sum_negastivos=0
cant_negativos=0

for i in range(100):# asignamos los numeros usando un ciclo for 
    num=randint(-100,100)
    print("numero asigandfo:",num)

    if(num>0):
        sum_positivos+=num
        cant_positivos+=1
    else:
        sum_negastivos+=num
        cant_negativos+=1

# auxiliares para el promedio de todos los valores ingresados 
cant_total=cant_positivos+cant_negativos
sum_total=sum_positivos+sum_negastivos

print("PROMEDIOS DE NUMEROS INGRESADOS")
print(" numros ingresados:",round(sum_total/cant_total,1))
print(" numros ingresados positivos:",round(sum_positivos/cant_positivos,1))
print(" numros ingresados nogativos:",round(sum_negastivos/cant_negativos,1))