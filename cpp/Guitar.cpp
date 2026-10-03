#ifndef GUITAR_CPP // header guard
#define GUITAR_CPP

#include <string>
#include <vector>
#include "GuitarString.cpp"

using namespace std;

// class to represent a guitar
class Guitar {
    // private attributes
    private:
        string brand;
        string type;
        vector<GuitarString> strings;

    public:
        // empty constructor
        Guitar() {
        }

        // constructor with parameters
        Guitar(string brand, string type, string stringBrand, string material) {
            this->brand = brand;
            this->type = type;

            // default gauges for electric and acoustic guitars
            vector<string> gauges;
            if (type == "Electric") {
                gauges = {"0.010", "0.013", "0.017", "0.026", "0.036", "0.046"};
            } else if (type == "Acoustic") {
                gauges = {"0.012", "0.016", "0.024", "0.032", "0.042", "0.053"};
            }

            // create guitar strings
            for (int i = 0; i < 6; i++) {
                strings.push_back(GuitarString(stringBrand, material, gauges[i]));
            }
        }

        // brand getter and setter
        string getBrand() {
            return brand;
        }

        void setBrand(string brand) {
            this->brand = brand;
        }

        // type getter and setter
        string getType() {
            return type;
        }

        void setType(string type) {
            this->type = type;
        }

        // strings getter and setter
        vector<GuitarString> getStrings() {
            return strings;
        }

        void setStrings(vector<GuitarString> strings) {
            this->strings = strings;
        }

        // destructor
        ~Guitar() {
        }
};

#endif
