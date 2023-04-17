# Minimos cuadrados
lx = []
ly = []
n = int(input("Ingrese el numero de datos n = "))
for i in range(n):
  lx.append(float(input(f"Ingrese el valor de x{i} = ")))
  ly.append(float(input(f"Ingrese el valor de y{i} = ")))

sy=sxy=sx2=sx=0.0
for i in range(n):
  sy = ly[i] + sy
  sx = lx[i] + sx
  sxy = lx[i]*ly[i] + sxy
  sx2 = lx[i]**2 + sx2

xm = sx/n
ym = sy/n
a1 = (n*sxy-sx*sy)/(n*sx2-sx*sx)
a0 = ym - a1*xm

print(f"Media x={xm}\n media de y={round(ym,6)}\n suma xy={sxy}\n suma x2={sx2}\n suma x={sx}\n suma y={sy}")
print(f"La regresion lineal es y={round(a0,6)}+{round(a1,6)}x")

## Metodo minimos cuadrados polinomial

lx = []
ly = []
n = int(input("Ingrese el numero de datos n = "))
for i in range(n):
  lx.append(float(input(f"Ingrese el valor de x en la posicion {i+1} = ")))
  ly.append(float(input(f"Ingrese el valor de y en la posicion {i+1} = ")))
  
sx=sx2=sy=sx3=sxy=sx4=sx2y=0.0
for i in range(n):
  sx  = lx[i] + sx
  sx2 = lx[i]**2 + sx2
  sy  = ly[i] + sy
  sx3 = lx[i]**3 + sx3
  sxy = lx[i]*ly[i] + sxy
  sx4 = lx[i]**4 + sx4
  sx2y= (lx[i]**2)*ly[i]+sx2y


import numpy as np
# Creamos una matriz 3x3 para el ejemplo
matriz_coeficientes = np.array([[n, sx, sx2], [sx, sx2, sx3], [sx2, sx3, sx4]])
matriz_a0 = np.array([[sy, sx, sx2], [sxy, sx2, sx3], [sx2y, sx3, sx4]])
matriz_a1 = np.array([[n, sy, sx2], [sx, sxy, sx3], [sx2, sx2y, sx4]])
matriz_a2 = np.array([[n, sx, sy], [sx, sx2, sxy], [sx2, sx3, sx2y]])
# Calculamos el determinante de la matriz
determinante_coeficientes = np.linalg.det(matriz_coeficientes)
determinante_a0 = np.linalg.det(matriz_a0)
determinante_a1 = np.linalg.det(matriz_a1)
determinante_a2 = np.linalg.det(matriz_a2)

a0 = determinante_a0 / determinante_coeficientes
a1 = determinante_a1 / determinante_coeficientes
a2 = determinante_a2 / determinante_coeficientes

print(f"La regresion polinomial grado 2 es f(x)={round(a0,5)}+{round(a1,5)}x+{round(a2,5)}x**2")
