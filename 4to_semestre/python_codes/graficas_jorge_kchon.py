
import numpy as np
import matplotlib.pyplot as plt


#funcion de corriente 
def h(t):
    return (28/3)*np.exp(-0.43*t) - (16/3)*np.exp(-4.56*t)

t=np.linspace(0,10,100)

plt.plot(t,h(t))
plt.show()



"""
# funcion de voltaje
def h(t):
    return 20-((56/3)*np.exp(-0.43*t)) + ((8/3)*np.exp(-4.56*t))

t=np.linspace(0,100,20)

plt.plot(t,h(t))
plt.show()
"""




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
