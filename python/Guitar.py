# class to represent a guitar
class Guitar:
    # private attributes
    def __init__(self):
        # empty constructor
        self.brand = None
        self.type = None

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
