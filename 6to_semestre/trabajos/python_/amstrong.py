
num= input("ingresa un numerO:")

sum=0
for n in num:
    sum+=int(n)**len(num)

if sum == int(num):
    print("es amstrong")