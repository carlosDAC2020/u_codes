import os
import csv

# matriz de 8x270 
matriz=[]
paises=[]
codigo_paises=[]
anios=[]

with open('data.csv', newline='') as File:  
    reader = csv.reader(File)
    for row in reader:
       paises.append(row[0])
       codigo_paises.append(row[1])
       anios.append(int(row[2]))

    # codigos y paises correspondientes 
    paises=set(paises)
    codigo_paises=set(codigo_paises)


    anios=set(anios)
    anios=list(anios)
    anios.sort()


