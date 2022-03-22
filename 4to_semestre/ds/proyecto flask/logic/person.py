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






if __name__ == '__main__':

    edwin = Person(id_person=73577376, name="Edwin", last_name="Puertas")
    print(edwin)

