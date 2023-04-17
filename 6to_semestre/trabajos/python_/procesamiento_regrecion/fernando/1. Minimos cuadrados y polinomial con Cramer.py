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

##Regresion polinomial por Minimos cuadrados
px = []
py = []
n = int(input("Ingrese el numero de datos n = "))
for i in range(n):
  px.append(float(input(f"Ingrese el valor de x{i} = ")))
  py.append(float(input(f"Ingrese el valor de y{i} = ")))

sx=sx2=sy=sx3=sxy=sx4=sx2y=0.0
for i in range(n):
  sx   = px[i] + sx
  sx2  = px[i]**2 + sx2
  sy   = py[i] + sy
  sx3  = px[i]**3 + sx3
  sxy  = px[i]*py[i] + sxy
  sx4  = px[i]**4 + sx4
  sx2y = (px[i]**2)*py[i] + sx2y

determinante = n*(sx2*sx4-sx3**2)-sx*(sx*sx4-sx3*sx2)+sx2*(sx*sx3-sx2**2)

determinante_a0 =  sy*(sx2*sx4-sx3**2)-sx*(sxy*sx4-sx3*sx2y)+sx2*(sxy*sx3-sx2y*sx2)

determinante_a1 = n*(sxy*sx4-sx3*sx2y)-sy*(sx*sx4-sx3*sx2)+sx2*(sx*sx2y-sxy*sx2)

determinante_a2 = n*(sx2*sx2y-sxy*sx3)-sx*(sx*sx2y-sxy*sx2)+sy*(sx*sx3-sx2**2)

a0 = determinante_a0/determinante
a1 = determinante_a1/determinante
a2 = determinante_a2/determinante

print(f"La regresion polinomial grado 2 es y = {a0}+{a1}x+{a2}x**2")

