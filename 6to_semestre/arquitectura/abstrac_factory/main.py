from abc import ABC, abstractmethod

# Creamos la clase abstracta Caracterizacion, que servirá como base para todas las subclases
class Caracterizacion(ABC):

    def __init__(self, describ="ninguna"):
        self.describ = describ

    @abstractmethod
    def descripcion(self):
        pass

# Creamos las subclases de Caracterizacion
class Poder(Caracterizacion):
    def descripcion(self):
        return "Poderes:",self.describ

class Habilidad(Caracterizacion):
    def descripcion(self):
        return "habilidades excepcionales :",self.describ

class Debilidad(Caracterizacion):
    def descripcion(self):
        return "Debilidades:",self.describ

class Arma(Caracterizacion):
    def descripcion(self):
        return "Armas:",self.describ

class Personalidad(Caracterizacion):
    def descripcion(self):
        return "Personalidad:",self.describ

# Creamos la clase abstracta Personajes, que también servirá como base para todas las subclases
class Personaje(ABC):
    def __init__(self, nombre, liga="ninguna", enemigo="ninguno"):
        self.nombre = nombre
        self.liga = liga
        self.enemigo = enemigo
        self.caracteristicas = []

    def add_caracteristica(self, caracteristica):
        self.caracteristicas.append(caracteristica)

    def descripcion(self):
        return f"Soy {self.nombre}, un {self.__class__.__name__}"

    @abstractmethod
    def habilidad_especial(self):
        pass

# Creamos las subclases de Personajes
class Humano(Personaje):
    def habilidad_especial(self):
        return "Habilidad especial: Ninguna"

class SuperHumano(Personaje):
    def habilidad_especial(self):
        return "Habilidad especial: Superfuerza"

class Artificial(Personaje):
    def habilidad_especial(self):
        return "Habilidad especial: Inteligencia artificial avanzada"

class Alien(Personaje):
    def habilidad_especial(self):
        return "Habilidad especial: Teletransportación"

# Creamos la clase IFicha, que será la interfaz que usaremos para crear personajes
class IFicha(ABC):
    @abstractmethod
    def add(self, caracterizacion):
        pass

    @abstractmethod
    def liga(self, nombre_liga):
        pass

    @abstractmethod
    def enemigo(self, nombre_enemigo):
        pass

# Creamos la clase Ficha, que implementa la interfaz IFicha y nos permite crear personajes
class Ficha(IFicha):
    def __init__(self, personaje):
        self.personaje = personaje

    def add(self, caracterizacion):
        self.personaje.add_caracteristica(caracterizacion)

    def liga(self, nombre_liga):
        self.personaje.liga = nombre_liga

    def enemigo(self, nombre_enemigo):
        self.personaje.enemigo = nombre_enemigo

# Ejemplo de uso
if __name__ == "__main__":
    # Creamos un personaje usando la Ficha y la clase Aliens
    alien_ficha = Ficha(Alien("E.T."))
    alien_ficha.add(Poder("telequinesis"))
    alien_ficha.add(Personalidad("enojon"))
    alien_ficha.liga("Alianza Intergaláctica")
    alien_ficha.enemigo("Fuerzas de la Oscuridad")
    alien = alien_ficha.personaje

    # Imprimimos la descripción del personaje
    print(alien.nombre)
    print(alien.__class__.__name__)
    cart = [c.descripcion() for c in alien.caracteristicas]
    for des in cart:
        print(des)
    print(alien.__class__.habilidad_especial(alien))
    print(alien.liga)
    print(alien.enemigo)

     # Creamos un personaje usando la Ficha y la clase humano
    human_ficha = Ficha(Humano("carlos"))
    human_ficha.add(Poder("inteligencia"))
    human_ficha.add(Personalidad("timido"))
    human_ficha.liga("Avengers ")
    human_ficha.enemigo("raser")
    human = human_ficha.personaje

    print()
    print(human.nombre)
    print(human.__class__.__name__)
    cart = [c.descripcion() for c in human.caracteristicas]
    for des in cart:
        print(des)
    print(human.__class__.habilidad_especial(human))
    print(human.liga)
    print(human.enemigo)
