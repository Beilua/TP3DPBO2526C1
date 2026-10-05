# class to represent a guitar string
class GuitarString:
    # constructor
    def __init__(self, stringBrand, material, stringGauge):
        self.stringBrand = stringBrand
        self.material = material
        self.stringGauge = stringGauge

    # stringBrand getter and setter
    def getStringBrand(self):
        return self.stringBrand

    def setStringBrand(self, stringBrand):
        self.stringBrand = stringBrand

    # material getter and setter
    def getMaterial(self):
        return self.material

    def setMaterial(self, material):
        self.material = material

    # stringGauge getter and setter
    def getStringGauge(self):
        return self.stringGauge

    def setStringGauge(self, stringGauge):
        self.stringGauge = stringGauge
