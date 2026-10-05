#ifndef GUITAR_CPP // header guard
#define GUITAR_CPP

#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <stdexcept>
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
        // default gauges for electric and acoustic guitars
        inline static const map<string, vector<string>> defaultGauges = {
            {"Electric", {"0.010", "0.013", "0.017", "0.026", "0.036", "0.046"}},
            {"Acoustic", {"0.012", "0.016", "0.024", "0.032", "0.042", "0.053"}}
        };

        // empty constructor
        Guitar() {
        }

        // constructor with parameters
        Guitar(string brand, string type, string stringBrand, string material, vector<string> gauges = {}) {
            this->brand = brand;
            this->type = type;

            // use default gauges if none are provided
            if (gauges.empty()) {
                auto it = defaultGauges.find(type);
                if (it != defaultGauges.end()) {
                    gauges = it->second;
                }
            }
            if (gauges.empty()) {
                throw invalid_argument("A custom gauge set is required for this guitar type");
            }
            setStrings(makeStringData(stringBrand, material, gauges));
        }

        // method to make string data based on the provided string brand, material, and gauges
        vector<tuple<string, string, string>> makeStringData(string stringBrand, string material, vector<string> gauges) {
            vector<tuple<string, string, string>> stringData;
            for (int i = 0; i < (int)gauges.size(); i++) {
                stringData.push_back(make_tuple(stringBrand, material, gauges[i]));
            }
            return stringData;
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

        void setStrings(vector<tuple<string, string, string>> stringData) {
            // error handling if string is not 6
            if ((int)stringData.size() != 6) {
                throw invalid_argument("A guitar must have exactly 6 strings");
            }

            // error handling if string gauge is not unique
            set<string> seenGauges;
            for (int i = 0; i < (int)stringData.size(); i++) {
                seenGauges.insert(get<2>(stringData[i]));
            }
            if ((int)seenGauges.size() != 6) {
                throw invalid_argument("Each string must have a different gauge");
            }

            strings.clear();
            for (int i = 0; i < (int)stringData.size(); i++) {
                strings.push_back(GuitarString(get<0>(stringData[i]), get<1>(stringData[i]), get<2>(stringData[i])));
            }
        }

        // destructor
        ~Guitar() {
        }
};

#endif
