#include <string>

using namespace std;

// class to represent a guitar string
class GuitarString {
    // private attributes
    private:
        string stringBrand;
        string material;
        string stringGauge;

    public:
        // constructor
        GuitarString(string stringBrand, string material, string stringGauge) {
            this->stringBrand = stringBrand;
            this->material = material;
            this->stringGauge = stringGauge;
        }

        // stringBrand getter and setter
        string getStringBrand() {
            return stringBrand;
        }

        void setStringBrand(string stringBrand) {
            this->stringBrand = stringBrand;
        }

        // material getter and setter
        string getMaterial() {
            return material;
        }

        void setMaterial(string material) {
            this->material = material;
        }

        // stringGauge getter and setter
        string getStringGauge() {
            return stringGauge;
        }

        void setStringGauge(string stringGauge) {
            this->stringGauge = stringGauge;
        }

        // destructor
        ~GuitarString() {
        }
};