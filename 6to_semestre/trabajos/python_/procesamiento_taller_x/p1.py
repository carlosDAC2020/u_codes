import numpy as np 
import math
import matplotlib.pyplot as plt 



def f_p3_2_1(a,D=None): # funcion
    if D==None:
        D=55
    A = 89*np.sin(np.radians(11.5)) # bien 
    print(A)
    B = 89*np.cos(np.radians(11.5))
    print(B)
    C = (49 + 0.5*D)*np.sin(np.radians(11.5)) - (0.5*D)*np.tan(np.radians(11.5)) 
    print(C)
    E = (49 + 0.5*D)*np.cos(np.radians(11.5)) - (0.5*D) 
    print(E)

    return (A*np.sin(np.radians(a))*np.cos(np.radians(a))) + (B*(np.sin(np.radians(a)))**2) - (C*np.cos(np.radians(a))) - (E*np.sin(np.radians(a)))

    # Asen(a)cos(a) + Bsen^2(a) - Ccos(a) - Esen(a)

f_p3_2_1(1)