import matplotlib.pyplot as plt 
import numpy as np

f = lambda x: np.log(x) + x - 5

# grafica
x=np.arange(0,10,0.01)
plt.plot(x,f(x))
plt.grid()
plt.title("F(x) = ln(x) + x - 5 ")
plt.xlabel("X")
plt.ylabel("Y")
plt.show()
