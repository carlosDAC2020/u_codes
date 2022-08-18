def factorial(num): # hayar el factorial de un numero
    fact=1
    while num>1:
        fact*=num
        num-=1
    return fact

def run():
    x=int(input("valor del exponente de euler :"))
    n=int(input(" cifras significativas:"))

    es= (0.5*(10**(2-n)))

    exa=1+x
    m=1
    while True:
        ex= exa-(x**m)/factorial(m)

        print(ex)

        ea= 100*((ex-exa)/ex)

        if abs(ea)<es:
            break
        m+=1

    

if __name__=="__main__":
    run()