prom=3

desvEst=1

n=5

dur_baterias=[1.9,2.4,3.0,3.5,4.2]

aux=1/n(n-1)


sumx=0
sumx2=0
for i in dur_baterias:
    sumx+=i
    sumx2+=i**2

s=aux(n*sumx-sumx**2)**2

print(s)