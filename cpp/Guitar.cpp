#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "GuitarString.cpp"

using namespace std;

// class to represent a guitar
class Guitar {
    // private attributes
    private:
        string brand;
        string type;
        vector<GuitarString> strings;

        vector<string> getDefaultGauges(string guitarType) {
            if (guitarType == "Electric") {
                return {"0.010", "0.013", "0.017", "0.026", "0.036", "0.046"};
            }

            if (guitarType == "Acoustic") {
                return {"0.012", "0.016", "0.024", "0.032", "0.042", "0.053"};
            }

            return {};
        }

    public:
        // constructor
        Guitar(string brand, string guitarType, string stringBrand, string material) {
            this->brand = brand;
            this->type = guitarType;
            vector<string> gauges = getDefaultGauges(guitarType);
            if (gauges.empty()) {
                throw invalid_argument("A custom gauge set is required for this guitar type");
            }
            setStrings(makeStringData(stringBrand, material, gauges));
        }

        // constructor with custom gauges
        Guitar(string brand, string guitarType, string stringBrand, string material, vector<string> gauges) {
            this->brand = brand;
            this->type = guitarType;
            setStrings(makeStringData(stringBrand, material, gauges));
        }

        vector<GuitarString> makeStringData(string stringBrand, string material, vector<string> gauges) {
            vector<GuitarString> stringData;
            for (string gauge : gauges) {
                stringData.push_back(GuitarString(stringBrand, material, gauge));
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

        void setStrings(vector<GuitarString> stringData) {
            if (stringData.size() != 6) {
                throw invalid_argument("A guitar must have exactly 6 strings");
            }

            vector<string> gauges;
            for (GuitarString stringInfo : stringData) {
                gauges.push_back(stringInfo.getStringGauge());
            }

            sort(gauges.begin(), gauges.end());
            if (adjacent_find(gauges.begin(), gauges.end()) != gauges.end()) {
                throw invalid_argument("Each string must have a different gauge");
            }

            this->strings = stringData;
        }

        // destructor
        ~Guitar() {
        }
};