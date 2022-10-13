m=int(input(" ingresa un valor para m:"))
n=int(input(" ingresa un valor para n:"))

resultado=0
print("{:^10}{:^10}{:^10}".format("N","M","acumulado"))
while m>0:
    if m%2!=0:
        resultado+=n
        
    print("{:^10}{:^10}{:^10}".format(n,m,resultado))
    m=int(m/2)
    n=n*2

    
