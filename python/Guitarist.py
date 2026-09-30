from Musician import Musician


# class to represent a guitarist inheriting from Musician class
class Guitarist(Musician):
    # constructor
    def __init__(self, name, yearsOfExperience, performanceType, position, favoriteBrand, guitars):
        Musician.__init__(self, name, yearsOfExperience, performanceType)
        self.position = position
        self.favoriteBrand = favoriteBrand
        self.guitars = list(guitars)

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

    # guitars getter and setter
    def getGuitars(self):
        return self.guitars

    def setGuitars(self, guitars):
        self.guitars = guitars

    def addGuitar(self, guitar):
        self.guitars.append(guitar)
