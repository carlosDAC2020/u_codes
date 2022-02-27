
def ejercicio1():
    print ("ejercicio 1")
    print("   tenemos la siguiente proposicion compuesta ")
    print(" P= (p1 > p2) or (p3 >= p4) ")
    print("   donde:")
    print(" p1=(a+c)/b**2")
    print(" p2=a*c*b")
    print(" p3=(b*c+a)/(c**2)")
    print(" p4=a*b*(c**3)")
    
    # declamramos variables a utilizar
    a=0
    b=0
    c=0
    p= True
    
    print("-"*48)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("a","b","c","P"))
    print("-"*48)
    i=1
    while i<=5:
        a=i
        b=i+1
        c=i+2

        # variable auxiliares
        p1=round((a+c)/b**2,2)
        p2=round(a*c*b,2)
        p3=round((b*c+a)/(c**2),2)
        p4=round(a*b*(c**3),2)

        if  (p1 > p2) or (p3 >= p4):
            p=True
        else:
            p=False
        print("|{:^10}|{:^10}|{:^10}|  ".format(a,b,c),end="")
        print(p,"  |")
        i+=1
    print("-"*48)
   
ejercicio1()




def ejercicio2():

    print ("ejercicio 2")
    print("  tenemos la siguiente proposicion compuesta ")
    print(" P= p1=p2 ")
    print(" donde ")
    print(" p1=(q/b)+(c/d)")
    print(" p2=(a*d+b*c)/(b*d)")

 

    a=0
    b=0
    c=0
    d=0
    p= True
    
    print("-"*75)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^16}|{:^10}|  ".format("a","b","c","d","   p1==p2   ","P"))
    print("-"*75)
    for i in range(1,5):
        a=1
        b=i+1
        c=i+2
        d=i+3

        # variable auxiliares
        p1=round((a/b)+(c/d),2)
        p2=round((a*d+b*c)/(b*d),2)
 
        if   p1==p2 :
            p=True
        else:
            p=False
        print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^5} {:^5} {:^5}|  ".format(a,b,c,d,p1,"==",p2),end="")
        print(p,"  |")
    print("-"*75)
    pass
ejercicio2()
#------------------------------------------------------------------------------------------------------------
"""
ejrsicio 3
Transformar las siguientes sentencias 
con su equivalente a través de las leyes De Morgan
"""
#punto 3
def ejersicio3():
    print("ejrsicio 3")
    x = int(input("Digite un valor para x:"))

    print("al tener un valor de x evaliuamos la expresiones siguientes")
    print("A= x >=10 ∧ x <= 20 ")
    print("B= ¬( x >= 10) ∨ ¬(x<=20) ")

    print("\n evluamos para A")
    print(x,">=10 ∧ ",x,"<=20" )
    if not(x >=10 and x <= 20):
        print("cumple")
    else:
        print( " no cumple")3


    # aplicamos la ley D´morgan    
    print("\n evluamos para B")
    print("¬(",x,">=10) ∨ ¬(",x,"<=20) ")
    if not ( x >= 10) or not(x<=20):
        print("cumple")
    else:
        print( " no cumple")

    print(" podemos decir que A y B son proposiciones equivalentes por la ley D´morgan")

ejersicio3()

