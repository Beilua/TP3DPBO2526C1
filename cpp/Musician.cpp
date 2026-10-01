#ifndef MUSICIAN_CPP
#define MUSICIAN_CPP

#include <string>

using namespace std;

// class to represent a musician
class Musician {
    // private attributes
    private:
        string name;
        int yearsOfExperience;
        string performanceType;

    public:
        // constructor
        Musician(string name, int yearsOfExperience, string performanceType) {
            this->name = name;
            this->yearsOfExperience = yearsOfExperience;
            this->performanceType = performanceType;
        }

        // name getter and setter
        string getName() {
            return name;
        }

        void setName(string name) {
            this->name = name;
        }

        // yearsOfExperience getter and setter
        int getYearsOfExperience() {
            return yearsOfExperience;
        }

        void setYearsOfExperience(int yearsOfExperience) {
            this->yearsOfExperience = yearsOfExperience;
        }

        // performanceType getter and setter
        string getPerformanceType() {
            return performanceType;
        }

        void setPerformanceType(string performanceType) {
            this->performanceType = performanceType;
        }

        // destructor
        virtual ~Musician() {
        }
};

    #endif