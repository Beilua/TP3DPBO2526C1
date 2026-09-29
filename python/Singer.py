from Musician import Musician


# class to represent a singer inheriting from Musician class
class Singer(Musician):
    # private attributes
    def __init__(self):
        # empty constructor
        super().__init__()
        self.vocalRange = None
        self.tone = None

    # vocalRange getter and setter
    def getVocalRange(self):
        return self.vocalRange

    def setVocalRange(self, vocalRange):
        self.vocalRange = vocalRange

    # tone getter and setter
    def getTone(self):
        return self.tone

    def setTone(self, tone):
        self.tone = tone
