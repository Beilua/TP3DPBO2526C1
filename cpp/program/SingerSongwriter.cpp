#ifndef SINGERSONGWRITER_CPP // header guard
#define SINGERSONGWRITER_CPP

#include <string>
#include <vector>
#include "Singer.cpp"
#include "Guitarist.cpp"

using namespace std;

// class to represent a singer songwriter inheriting from Singer and Guitarist classes
class SingerSongwriter : public Singer, public Guitarist {
    // private attributes
    private:
        int songsWritten;
        string writingGenre;

    public:
        // empty constructor
        SingerSongwriter() {
        }

        // constructor with all attributes
        SingerSongwriter(string name, int yearsOfExperience, string performanceType,
                         string vocalRange, string tone, string position, 
                         string favoriteBrand, vector<Guitar> guitars, 
                         int songsWritten, string writingGenre)
            : Musician(name, yearsOfExperience, performanceType),
              Singer(name, yearsOfExperience, performanceType, vocalRange, tone),
              Guitarist(name, yearsOfExperience, performanceType, position, favoriteBrand, guitars) {
            this->songsWritten = songsWritten;
            this->writingGenre = writingGenre;
        }

        // songsWritten getter and setter
        int getSongsWritten() {
            return songsWritten;
        }

        void setSongsWritten(int songsWritten) {
            this->songsWritten = songsWritten;
        }

        // writingGenre getter and setter
        string getWritingGenre() {
            return writingGenre;
        }

        void setWritingGenre(string writingGenre) {
            this->writingGenre = writingGenre;
        }

        // destructor
        ~SingerSongwriter() {
        }
};

#endif
