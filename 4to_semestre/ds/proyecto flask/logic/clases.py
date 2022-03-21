class Person(object):
    """54
    Class used to represent an Person
    """

    def __init__(self, id_person: int, name: str = 'Name', last_name: str = "LastName"):
        """ Person constructor object.

        :param id_person: id of person.
        :type id_person: int
        :param name: name of person.
        :type name: str
        :param last_name: last name of person.
        :type last_name: str
        :returns: Person object
        :rtype: object
        """
        self._id_person = id_person
        self._name = name
        self._last_name = last_name

    @property
    def id_person(self) -> int:
        """ Returns id person of the person.
          :returns: id of person.
          :rtype: int
        """
        return self._id_person

    @id_person.setter
    def id_person(self, id_person: int):
        """ The id of the person.
        :param id_person: id of person.
        :type: int
        """
        self._id_person = id_person

    @property
    def name(self) -> str:
        """ Returns the name of the person.
          :returns: name of person.
          :rtype: str
        """
        return self._name

    @name.setter
    def name(self, name: str):
        """ The name of the person.
        :param name: name of person.
        :type: str
        """
        self._name = name

    @property
    def last_name(self) -> str:
        """ Returns the last name of the person.
          :returns: last name of person.
          :rtype: str
        """
        return self._last_name

    @last_name.setter
    def last_name(self, last_name: str):
        """ The last name of the person.
        :param last_name: last name of person.
        :type: str
        """
        self._last_name = last_name

    def __str__(self):
        """ Returns str of person.
          :returns: sting person
          :rtype: str
        """
        return '({0}, {1}, {2})'.format(self.id_person, self.name, self.last_name)



class Document(object):

    def __init__(self, id_book: int, tilte: str, num_pages: int, category:str, authors:str):
        """ 
        constriuctor de la clase document
        inicializa un objeto Document

        declara los atributos de cla clase 
        atributos
        _id_book=int
        _tilte=str
        _num_pages=int
        _category=str
        _authors=str
        """
        self._id_book=id_book
        self._tilte=tilte
        self._num_pages=num_pages
        self._category=category
        self._authors=authors

    # id_book metods---------------------
    @property
    def id_book(self) -> int:
        """ 
        retorna el valor del atributo _id_book
        """
        return self._id_book

    @id_book.setter
    def id_book(self, id_book: int):
        """ 
        asigana un valor pasado por parametro
        al atrributo _id_book
        """
        self._id_book = id_book

    # tilte metods------------------------
    @property
    def title(self) -> str:
        """ 
        retorna el valor del atributo _title
        """
        return self._tilte

    @title.setter
    def tilte(self, tiltle: str):
        """ 
        asigana un valor pasado por parametro
        al atrributo _title
        """
        self._tilte = tiltle

    # num_pages metods---------------------
    @property
    def num_pages(self) -> int:
        """ 
        retorna el valor del atributo _num_pages
        """
        return self._num_pages

    @num_pages.setter
    def num_pages(self, num_pages: str):
        """
        asigana un valor pasado por parametro
        al atrributo _num_pages
        """
        self._num_pages = num_pages
    
    # category metods---------------------
    @property
    def category(self) -> int:
        """ 
        retorna el valor del atributo _category
        """
        return self._category

    @category.setter
    def category(self, category: str):
        """
        asigana un valor pasado por parametro
        al atrributo _category
        """
        self._category = category

    # authors metods-----------------------
    @property
    def authors(self) -> int:
        """ 
        retorna el valor del atributo _authors
        """
        return self._authors

    @authors.setter
    def authors(self, authors: str):
        """
        asigana un valor pasado por parametro
        al atrributo _authors
        """
        self._authors = authors

    def __str__(self):
        """ 
        retorna un str con los valores 
        de los atributos del objeto en cuestion 
        """
        return '({0}, {1}, {2}, {3}, {4})'.format(self._id_book, self._tilte, self._num_pages, self._category, self._authors)



if __name__ == '__main__':

    edwin = Person(id_person=73577376, name="Edwin", last_name="Puertas")
    print(edwin)

    libro= Document(id_book=1234, tilte="origin", num_pages=74, category="accion", authors="carlos")
    print(libro)
