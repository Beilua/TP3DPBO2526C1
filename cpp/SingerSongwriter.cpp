#ifndef SINGERSONGWRITER_CPP // header guard
#define SINGERSONGWRITER_CPP

#include <string>
#include <vector>
#include "Singer.cpp"
#include "Guitar.cpp"

using namespace std;

// class to represent a singer songwriter inheriting from Singer class
// (includes guitarist attributes directly to avoid complex multiple inheritance)
class SingerSongwriter : public Singer {
    // private attributes
    private:
        string position;
        string favoriteBrand;
        vector<Guitar> guitars;
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
            : Singer(name, yearsOfExperience, performanceType, vocalRange, tone) {
            this->position = position;
            this->favoriteBrand = favoriteBrand;
            this->guitars = guitars;
            this->songsWritten = songsWritten;
            this->writingGenre = writingGenre;
        }

        // position getter and setter
        string getPosition() {
            return position;
        }

        void setPosition(string position) {
            this->position = position;
        }

        // favoriteBrand getter and setter
        string getFavoriteBrand() {
            return favoriteBrand;
        }

        void setFavoriteBrand(string favoriteBrand) {
            this->favoriteBrand = favoriteBrand;
        }

        // guitars getter and setter
        vector<Guitar> getGuitars() {
            return guitars;
        }

        void setGuitars(vector<Guitar> guitars) {
            this->guitars = guitars;
        }

        // method to add new guitar to existing list of guitars
        void addGuitar(Guitar guitar) {
            guitars.push_back(guitar);
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
