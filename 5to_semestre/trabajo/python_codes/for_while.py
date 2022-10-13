"
n1=int(input("n1:"))
while n1>999  or n1<100:
    n1=int(input("n1 solo debe ter 3 cifras :"))

n2=int(input("n2:"))
while n2>999  or n2<100:
    n2=int(input("n2 solo debe ter 3 cifras :"))

n1=str(n1)
n2=str(n2)

rn1_1=0
rn1_2=0
rn1_3=0

i=1
for n in n1:
    for l in n2:
        if n==l:
            if i==1:
                rn1_1+=1
            elif i==2:
                rn1_2+=1
            else:
                rn1_3+=1
    i+=1

print(" para n1")
print(n1[0]," se repite",rn1_1)
print(n1[1]," se repite",rn1_2)
print(n1[2]," se repite",rn1_3)

#-----------------------------------------

rn1_1=0
rn1_2=0
rn1_3=0

i=1
for l in n2:
    for n in n1:
        if n==l:
            if i==1:
                rn1_1+=1
            elif i==2:
                rn1_2+=1
            else:
                rn1_3+=1
    i+=1

print("\n para n2")
print(n2[0]," se repite",rn1_1)
print(n2[1]," se repite",rn1_2)
print(n2[2]," se repite",rn1_3)

"""


n=int(input(" ingrese un numero:"))


print(" tabla de multiplcar del ",n)
for i in range(1,11):
    print(n,"x",i,"=",n*i)
"""