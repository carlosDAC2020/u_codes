import os
import csv

# matriz de 8x270 
matriz=[]
paises=[]
codigo_paises=[]
anios=[]

with open('au.csv', newline='') as File:  
    reader = csv.reader(File)
    for row in reader:
       