#include <string>
#include "Musician.cpp"

using namespace std;

// class to represent a singer inheriting from Musician class
class Singer : public virtual Musician {
    // private attributes
    private:
        string vocalRange;
        string tone;

    public:
        // constructor
        Singer(string name, int yearsOfExperience, string performanceType, string vocalRange, string tone)
            : Musician(name, yearsOfExperience, performanceType) {
            this->vocalRange = vocalRange;
            this->tone = tone;
        }

        // vocalRange getter and setter
        string getVocalRange() {
            return vocalRange;
        }

        void setVocalRange(string vocalRange) {
            this->vocalRange = vocalRange;
        }

        // tone getter and setter
        string getTone() {
            return tone;
        }

        void setTone(string tone) {
            this->tone = tone;
        }

        // destructor
        ~Singer() {
        }
};