from Musician import Musician


# class to represent a guitarist inheriting from Musician class
class Guitarist(Musician):
    # private attributes
    def __init__(self):
        # empty constructor
        super().__init__()
        self.position = None
        self.favoriteBrand = None

    # position getter and setter
    def getPosition(self):
        return self.position

    def setPosition(self, position):
        self.position = position

    # favoriteBrand getter and setter
    def getFavoriteBrand(self):
        return self.favoriteBrand

    def setFavoriteBrand(self, favoriteBrand):
        self.favoriteBrand = favoriteBrand
