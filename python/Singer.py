from Musician import Musician


# class to represent a singer inheriting from Musician class
class Singer(Musician):
    # constructor
    def __init__(self, name, yearsOfExperience, performanceType, vocalRange, tone):
        Musician.__init__(self, name, yearsOfExperience, performanceType)
        self.vocalRange = vocalRange
        self.tone = tone

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
