from cgi import print_form
from math import log

p=int(input(" n primo: "))
g=int(input(" raiz primitiva de p: "))
A=int(input(" clave publicaa:"))

def mod_p(p):
    aux=0
    for i in range(p):
        if i%p==0:
            aux+=1
    return aux
# ckave privada
a=log(g,A)*mod_p(p)

print(" clave privada: ")