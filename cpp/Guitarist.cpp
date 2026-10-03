#ifndef GUITARIST_CPP // header guard
#define GUITARIST_CPP

#include <string>
#include <vector>
#include "Musician.cpp"
#include "Guitar.cpp"

using namespace std;

// class to represent a guitarist inheriting from Musician class
class Guitarist : public Musician {
    // private attributes
    private:
        string position;
        string favoriteBrand;
        vector<Guitar> guitars;

    public:
        // empty constructor
        Guitarist() {
        }

        // constructor with all attributes from both parent and child classes
        Guitarist(string name, int yearsOfExperience, string performanceType,
                    string position, string favoriteBrand, vector<Guitar> guitars)
            : Musician(name, yearsOfExperience, performanceType) {
            this->position = position;
            this->favoriteBrand = favoriteBrand;
            this->guitars = guitars;
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

        // destructor
        ~Guitarist() {
        }
};

#endif
