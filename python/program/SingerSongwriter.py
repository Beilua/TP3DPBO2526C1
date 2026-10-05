from Guitarist import Guitarist
from Singer import Singer


# class to represent a singer songwriter inheriting from Singer and Guitarist classes
class SingerSongwriter(Singer, Guitarist):
    # constructor
    def __init__(self, name, yearsOfExperience, performanceType, vocalRange, tone, position, favoriteBrand, guitars, songsWritten, writingGenre):
        Singer.__init__(self, name, yearsOfExperience, performanceType, vocalRange, tone)
        Guitarist.__init__(self, name, yearsOfExperience, performanceType, position, favoriteBrand, guitars)
        self.songsWritten = songsWritten
        self.writingGenre = writingGenre

    # songsWritten getter and setter
    def getSongsWritten(self):
        return self.songsWritten

    def setSongsWritten(self, songsWritten):
        self.songsWritten = songsWritten

    # writingGenre getter and setter
    def getWritingGenre(self):
        return self.writingGenre

    def setWritingGenre(self, writingGenre):
        self.writingGenre = writingGenre
