import math

n = int(input("Ingrese el ultimo digito de su codigo: "))
if (n>2):
    Es = (0.5*pow(10,2-n))
    dec = 2-n
else:
    Es = (0.5*1e-3)
    dec = -3

xi = 0.5
xim1 = 1
values = []

vueltas=0
while ( xim1 <= 10 ):

    h = xim1 - xi
    Vv = math.sin(pow(xim1,2))
    
    fxi = math.sin(pow(xi,2))
    f1xi = 2*xi*math.cos( pow(xi,2) )
    f2xi = ( 2*math.cos( pow(xi,2) ) - 4*pow(xi,2)*math.sin(pow(xi,2)) ) / math.factorial(2)
    f3xi = ( -12*xi*math.sin(pow(xi,2)) - 8*pow(xi,3)*math.cos(pow(xi,2)) ) / math.factorial(3)
    Va = fxi + f1xi*h + f2xi*pow(h,2) + f3xi*pow(h,3)

    Er = abs((Vv-Va)/Vv)*100
    
    if (Er<Es):
        break

    values.append(xim1)
    
    xim1+=1*pow(10,-1)
    vueltas+=1

print("Vv:",Vv)
print("VA:",Va)
print(Er,"<",Es)
print("xim1:",xim1)
print(vueltas)