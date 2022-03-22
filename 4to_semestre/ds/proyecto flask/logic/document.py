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

    libro= Document(id_book=1234, tilte="origin", num_pages=74, category="accion", authors="carlos")
    print(libro)
