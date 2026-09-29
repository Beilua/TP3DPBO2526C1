# class to represent a musician
class Musician:
    # private attributes
    def __init__(self):
        # empty constructor
        self.name = None
        self.yearsOfExperience = None
        self.performanceType = None

    # name getter and setter
    def getName(self):
        return self.name

    def setName(self, name):
        self.name = name

    # yearsOfExperience getter and setter
    def getYearsOfExperience(self):
        return self.yearsOfExperience

    def setYearsOfExperience(self, yearsOfExperience):
        self.yearsOfExperience = yearsOfExperience

    # performanceType getter and setter
    def getPerformanceType(self):
        return self.performanceType

    def setPerformanceType(self, performanceType):
        self.performanceType = performanceType
