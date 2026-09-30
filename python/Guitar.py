# class to represent a guitar
from GuitarString import GuitarString


class Guitar:
    # constructor
    def __init__(self, brand, guitarType, stringBrand, material, gauges=None):
        self.brand = brand
        self.type = guitarType
        if gauges is None:
            gauges = self.defaultGauges.get(guitarType)
        if gauges is None:
            raise ValueError("A custom gauge set is required for this guitar type")
        self.setStrings(self.makeStringData(stringBrand, material, gauges))

    def makeStringData(self, stringBrand, material, gauges):
        return [(stringBrand, material, gauge) for gauge in gauges]
    
    defaultGauges = {
        "Electric": ("0.010", "0.013", "0.017", "0.026", "0.036", "0.046"),
        "Acoustic": ("0.012", "0.016", "0.024", "0.032", "0.042", "0.053")
    }

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

    def setStrings(self, stringData):
        if len(stringData) != 6:
            raise ValueError("A guitar must have exactly 6 strings")

        gauges = [stringInfo[2] for stringInfo in stringData]
        if len(set(gauges)) != 6:
            raise ValueError("Each string must have a different gauge")

        self.strings = [GuitarString(*stringInfo) for stringInfo in stringData]
