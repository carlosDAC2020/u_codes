
""" 
ejercicio 1
Compruebe mediante ejemplos que la expresión de la izquierda 
del operador relacional es equivalente a la expresión
de la derecha, aplique las leyes de equivalencia 
proposicionales para justificar la respuesta dada.

def ejercicio1():
    print ("ejercicio 1")
    print("     teniendo las siguientes ecyaciones")
    print(" p1=(a+c)/b**2")
    print(" p2=a*c*b")
    print(" p3=(b*c+a)/(c**2)")
    print(" p4=a*b*(c**3)")
    print("     que componen la siguiente proposicion compuesta ")
    print(" P= (p1 > p2) or (p3 >= p4) ")

    a=0
    b=0
    c=0
    p= True
    
    print("-"*90)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("a","b","c","p1","p2","p3","p4","P"))
    print("-"*90)
    for i in range(10,5,-1):
        a=i
        b=i-1
        c=i-2

        # variable auxiliares
        p1=round((a+c)/b**2,2)
        p2=round(a*c*b,2)
        p3=round((b*c+a)/(c**2),2)
        p4=round(a*b*(c**3),2)

        if  (p1 > p2) or (p3 >= p4):
            p=True
        else:
            p=False
        print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|  ".format(a,b,c,p1,p2,p3,p4),end="")
        print(p,"  |")
    print("-"*90)

ejercicio1()


"""
#------------------------------------------------------------------------------------------------------------

"""
ejersicio 2
Compruebe mediante ejemplos que la expresión
de la izquierda del operador relacional es
equivalente a la expresión de la derecha, 
aplique las leyes de equivalencia proposicionales 
para justificar la respuesta dada.


def ejercicio2():

    print ("ejercicio 2")
    print(" teniendo las proposiciones ")
    print(" p1=(q/b)+(c/d)")
    print(" p2=(a*d+b*c)/(b*d)")

    print("  que componen la siguiente proposicion compuesta ")
    print(" P= p1=p2 ")

    a=0
    b=0
    c=0
    d=0
    p= True
    
    print("-"*75)
    print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|  ".format("a","b","c","p1","p2","P"))
    print("-"*75)
    for i in range(10,5,-1):
        a=i
        b=i-1
        c=i-2
        d=i+3

        # variable auxiliares
        p1=round((a/b)+(c/d),2)
        p2=round((a*d+b*c)/(b*d),2)
 
        if   p1==p2 :
            p=True
        else:
            p=False
        print("|{:^10}|{:^10}|{:^10}|{:^10}|{:^10}|  ".format(a,b,c,p1,p2,),end="")
        print(p,"  |")
    print("-"*75)


    pass
ejercicio2()
"""
#------------------------------------------------------------------------------------------------------------
"""
ejrsicio 3
Transformar las siguientes sentencias c
on su equivalente a través de las leyes De Morgan
"""
def ejercicio1 (x:int) -> str:
    if not(x >= 10 and x <= 20): #    
        return 'Cumple'
    else:
        return 'No Cumple'

print ( ejercicio1 (9) )
print ( ejercicio1 (21) )
print ( ejercicio1 (19) )


