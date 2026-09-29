from Guitarist import Guitarist
from Singer import Singer


# class to represent a singer songwriter inheriting from Singer and Guitarist classes
class SingerSongwriter(Singer, Guitarist):
    # private attributes
    def __init__(self):
        # empty constructor
        Singer.__init__(self)
        self.position = None
        self.favoriteBrand = None
        self.songsWritten = None
        self.writingGenre = None

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
