
#//SE DEFINE LA FUNCION DE ENERGIA CINETICA
#EC=(1/2)*M*(v**2)

# modulos a utilizar
    # para asiganr rangos de valores a las variables
import numpy as np 
    # para generar las graficas 
import matplotlib.pyplot as plt 

# variables a utilizar 
m=0.003 # masa del objeto en gramos 
g=9.81 # constante de gravedad 

#funcion de energia potencial con respecto a la altura
def ep(h):
    return m*g*h

h=np.arange(0.01,0.8,0.1)# altura en centimetros 

plt.plot(h,ep(h))
plt.grid()
plt.xlabel("Altura (m)")
plt.ylabel("Energia potencial")
plt.title("Energia potencial vs altura.")
plt.legend()
plt.show()
   

#funcion de energia cinetica vs velocidad
def ec(v):
    return (1/2)*m*(v**2)

v=np.arange(0.01,0.8,0.1)# velocidad en m/s

plt.plot(v,ec(v))
plt.grid()
plt.xlabel("Velocidad (m/s)")
plt.ylabel("Energia cinetica")
plt.title("Energia cinetica vs velocidad.")
plt.legend()
plt.show()
   
  

"""
#funcion de corriente 
def h(t):
    return (28/3)*np.exp(-0.43*t) - (16/3)*np.exp(-4.56*t)

t=np.linspace(0,10,100)

plt.plot(t,h(t))
plt.show()
"""


"""
# funcion de voltaje
def h(t):
    return 20-((56/3)*np.exp(-0.43*t)) + ((8/3)*np.exp(-4.56*t))

t=np.linspace(0,100,20)

plt.plot(t,h(t))
plt.show()
"""


"""
# punro 4
# solicitamos la resistencia 
R=float(input(" ingrese el valor de la resistencia:"))
R=round(R,2)

alfa=round(R/2,2)
omega=1.41



if alfa>omega:
    print(alfa,">",omega)
        # funcion de voltaje
    def h(t):
        return 20-((56/3)*np.exp(-0.43*t)) + ((8/3)*np.exp(-4.56*t))

    t=np.linspace(0,100,20)

    plt.plot(t,h(t))
    plt.show()

    #funcion de corriente 
    def h(t):
        return (28/3)*np.exp(-0.43*t) - (16/3)*np.exp(-4.56*t)

    t=np.linspace(0,3,100)

    plt.plot(t,h(t))
    plt.show()

elif alfa==omega:
    print(alfa,"==",omega)
        # funcion de voltaje
    def h(t):
        return 20 + (-11.702+(5.35*t)*np.exp(-1.41*t))

    t=np.linspace(0,100,20)

    plt.plot(t,h(t))
    plt.show()

else:
    print(alfa,"<",omega)
        # funcion de voltaje
    def h(t):
        return 20+(-10*np.cos(1.318*t) + 11.38*np.sin(1.318*t))*np.exp(-0.5*t)

    t=np.linspace(0,100,20)

    plt.plot(t,h(t))
    plt.show()
"""

"""
# punto 3

# solicitamos la resistencia 
R=float(input(" ingrese el valor de la resistencia:"))
R=round(R,2)

alfa=round(R+6)
omega=10

if alfa>omega:
    print(" sobreamortiguado")
    print(alfa,">",omega)
        # funcion de corriente
    def h(t):
        return ((-0.278*np.exp(-4,2*t)) + (1.278 * np.exp(-23.8*t)))
    t=np.linspace(0,100,20)

    plt.plot(t,h(t))
    plt.show()

    

elif alfa==omega:
    print(" criticamente amortiguado")
    print(alfa,"==",omega)
        # funcion de corriente
    def h(t):
        return ((1+ 2*t) * np.exp(-8*t))

    t=np.linspace(0,100,20)

    plt.plot(t,h(t))
    plt.show()

else:
    print(" subamortiguado")
    print(alfa,"<",omega)
        # funcion de voltaje
    def h(t):
        return ((np.cos(4.359*t) + 0.6882*(np.sin(4.359*t))) * np.exp(-9*t))

    t=np.linspace(0,100,20)

    plt.plot(t,h(t))
    plt.show()
"""

