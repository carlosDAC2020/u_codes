from math import pi


class figura:
	def _init_(self):
		pass

	def calcular_area(self):
		pass


	class Circulo():
		def _init_(self, diametro, color):
			self.diametro = diametro
			self.color = color
		
		def calcular_area(self):
			return round(pi * self.diametro, 2)


	class Triangulo():
		def _init_(self, altura, base, color):
			self.altura = altura
			self.base = base
			self.color = color
			
		def calcular_area(self):
			return round((self.base * self.altura) / 2, 2)


	class Rectangulo():
		def _init_(self, altura, base, color):
			self.altura = altura
			self.base = base
			self.color = color

		def calcular_area(self):
			return round(self.base * self.altura, 2)
	

def run():
	circulo = figura.Circulo(4, "verde")
	cuadrado = figura.Rectangulo(2, 3, "azul")
	triangulo = figura.Triangulo(5, 4, "rojo")

	print(" --- Resultados --- \nÁrea del círculo:", circulo.calcular_area(), "\nÁrea del cuadrado:", cuadrado.calcular_area(), "\nÁrea del triángulo:", triangulo.calcular_area())


if __name__=="__main__":
	run()