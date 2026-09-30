# class to represent a guitar
class Guitar:
    # constructor
    def __init__(self, brand, type, strings):
        self.brand = brand
        self.type = type
        self.strings = list(strings)

    # brand getter and setter
    def getBrand(self):
        return self.brand

    def setBrand(self, brand):
        self.brand = brand

    # type getter and setter
    def getType(self):
        return self.type

    def setType(self, type):
        self.type = type

    # strings getter and setter
    def getStrings(self):
        return self.strings

    def setStrings(self, strings):
        self.strings = strings
