#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Singer.cpp"
#include "Guitarist.cpp"
#include "SingerSongwriter.cpp"
#include "Guitar.cpp"

using namespace std;

// function declarations
void printMusicians(vector<Musician*>& musicians, double delay);
void printGuitars(vector<Guitar>& guitars, double delay);
void sleepDelay(double seconds);

int main() {
    // create an array of objects for singers
    vector<Singer> singers = {
        Singer("Hayley Williams", 21, "Band", "Soprano", "Bright"),
        Singer("Gerard Way", 24, "Band", "Tenor", "Warm"),
        Singer("Conor Mason", 13, "Band", "Tenor", "Bright"),
    };

    // create an array of objects for guitarists
    vector<Guitarist> guitarists = {
        Guitarist("Taylor York", 18, "Band", "Lead", "Fender", {}),
        Guitarist("Ray Toro", 24, "Band", "Lead", "Gibson", {}),
        Guitarist("Toru Yamashita", 20, "Band", "Rhythm", "PRS", {}),
    };

    // create an array of objects for singer songwriters
    vector<SingerSongwriter> singerSongwriters = {
        SingerSongwriter("Luke Hemmings", 14, "Live", "Tenor", "Warm", "Rhythm", "Gibson", {}, 120, "Pop"),
        SingerSongwriter("Michael Clifford", 14, "Studio", "Tenor", "Bright", "Lead", "Fender", {}, 90, "Pop"),
        SingerSongwriter("Gaon", 4, "Live", "Tenor", "Bright", "Rhythm", "Ibanez", {}, 25, "Rock"),
    };

    // create an array of objects for guitars
    vector<Guitar> guitars = {
        Guitar("Fender", "Electric", "D'Addario", "Steel"),
        Guitar("Gibson", "Acoustic", "Ernie Ball", "Steel"),
        Guitar("PRS", "Electric", "Elixir", "Steel"),
        Guitar("Gibson", "Acoustic", "Martin", "Steel"),
        Guitar("Fender", "Electric", "D'Addario", "Steel"),
        Guitar("Ibanez", "Acoustic", "Ernie Ball", "Steel"),
    };

    // add guitars to the list of guitars in guitarists
    guitarists[0].addGuitar(guitars[0]);
    guitarists[1].addGuitar(guitars[1]);
    guitarists[2].addGuitar(guitars[2]);

    // add guitars to the list of guitars in singer songwriters
    singerSongwriters[0].addGuitar(guitars[3]);
    singerSongwriters[1].addGuitar(guitars[4]);
    singerSongwriters[2].addGuitar(guitars[5]);

    // combine the children and grandchildren to musicians list
    vector<Musician*> musicians;
    for (int i = 0; i < (int)singers.size(); i++) {
        musicians.push_back(&singers[i]);
    }
    for (int i = 0; i < (int)guitarists.size(); i++) {
        musicians.push_back(&guitarists[i]);
    }
    for (int i = 0; i < (int)singerSongwriters.size(); i++) {
        musicians.push_back(&singerSongwriters[i]);
    }

    // print welcome message
    cout << "                     _      _                   " << '\n';
    cout << " _ __ ___  _   _ ___(_) ___(_) __ _ _ __  ____  " << '\n';
    cout << "| '_ ` _ \\| | | |_  / |/ __| |/ _` | '_ \\|_  /  " << '\n';
    cout << "| | | | | | |_| |/ /| | (__| | (_| | | | |/ / _ " << '\n';
    cout << "|_| |_| |_\\__,_ /___|_|\\___|_|\\__,_|_| |_/___(_)" << '\n';

    double delay = 1.0;
    sleepDelay(delay);
    cout << "\nFetching data";
    sleepDelay(delay);
    cout << " . ";
    sleepDelay(delay);
    cout << " . ";
    sleepDelay(delay);
    cout << " . \n" << '\n';
    sleepDelay(delay);

    // print guitars data
    printGuitars(guitars, delay);
    // print musicians data
    printMusicians(musicians, delay);

    cout << "Loading ";
    sleepDelay(delay);
    cout << " . ";
    sleepDelay(delay);
    cout << " . ";
    sleepDelay(delay);
    cout << " . \n" << '\n';
    sleepDelay(delay);

    cout << "New data found!" << '\n';
    sleepDelay(delay);
    cout << "Adding new data";
    sleepDelay(delay);
    cout << " . ";
    sleepDelay(delay);
    cout << " . ";
    sleepDelay(delay);
    cout << " . \n" << '\n';

    // simulate adding new data statically
    singerSongwriters.push_back(SingerSongwriter("Taka Moriuchi", 20, "Live", "Tenor", "Bright", "Rhythm", "Gibson", {}, 80, "Rock"));
    guitars.push_back(Guitar("Gibson", "Electric", "D'Addario", "Steel"));
    singerSongwriters.back().addGuitar(guitars.back());
    guitars.push_back(Guitar("Gibson", "Acoustic", "Elixir", "Steel"));
    singerSongwriters.back().addGuitar(guitars.back());

    // rebuild the musicians list
    musicians.clear();
    for (int i = 0; i < (int)singers.size(); i++) {
        musicians.push_back(&singers[i]);
    }
    for (int i = 0; i < (int)guitarists.size(); i++) {
        musicians.push_back(&guitarists[i]);
    }
    for (int i = 0; i < (int)singerSongwriters.size(); i++) {
        musicians.push_back(&singerSongwriters[i]);
    }

    // print guitars data after adding new data
    printGuitars(guitars, delay);
    // print musicians data after adding new data
    printMusicians(musicians, delay);

    cout << "Exiting program." << '\n';
    sleepDelay(delay);

    return 0;
}

// function to simulate delay
void sleepDelay(double seconds) {
    cout << flush;
    this_thread::sleep_for(chrono::duration<double>(seconds));
}

// function to print musicians data
void printMusicians(vector<Musician*>& musicians, double delay) {
    cout << "============================================" << '\n';
    cout << "             __     __               __ " << '\n';
    cout << "  |\\/| |  | /__` | /  ` |  /\\  |\\ | /__`" << '\n';
    cout << "  |  | \\__/ .__/ | \\__, | /~~\\ | \\| .__/" << '\n';
    cout << "\n============================================" << '\n';
    sleepDelay(delay);

    // variable to keep track of current class
    string currentClass = "";
    int number = 1;

    for (int i = 0; i < (int)musicians.size(); i++) {
        Musician* musician = musicians[i];

        // get the class of the current musician
        string musicianClass = "Unknown";
        if (dynamic_cast<SingerSongwriter*>(musician)) {
            musicianClass = "SingerSongwriter";
        } else if (dynamic_cast<Singer*>(musician)) {
            musicianClass = "Singer";
        } else if (dynamic_cast<Guitarist*>(musician)) {
            musicianClass = "Guitarist";
        }

        // if the class of the current musician is different from the previous musician
        // print the class name as a title and reset the number
        if (musicianClass != currentClass) {
            currentClass = musicianClass;
            number = 1;
            cout << "\n" << musicianClass << ":" << '\n';
        }
        sleepDelay(delay);

        // print each data
        cout << number << ". Name: " << musician->getName() << '\n';
        cout << "   Years of Experience: " << musician->getYearsOfExperience() << '\n';
        cout << "   Performance Type: " << musician->getPerformanceType() << '\n';

        // if musician is singer songwriter, print additional data
        SingerSongwriter* ss = dynamic_cast<SingerSongwriter*>(musician);
        if (ss != NULL) {
            cout << "   Vocal Range: " << ss->getVocalRange() << '\n';
            cout << "   Tone: " << ss->getTone() << '\n';
            cout << "   Position: " << ss->getPosition() << '\n';
            cout << "   Favorite Guitar Brand: " << ss->getFavoriteBrand() << '\n';
            cout << "   Guitars:" << '\n';
            // print guitars list
            vector<Guitar> guitars = ss->getGuitars();
            for (int j = 0; j < (int)guitars.size(); j++) {
                cout << "      - " << guitars[j].getBrand() << " " << guitars[j].getType() << '\n';
            }
            cout << "   Songs Written: " << ss->getSongsWritten() << '\n';
            cout << "   Writing Genre: " << ss->getWritingGenre() << '\n';
        }
        // if musician is singer, print additional data
        else {
            Singer* singer = dynamic_cast<Singer*>(musician);
            if (singer != NULL) {
                cout << "   Vocal Range: " << singer->getVocalRange() << '\n';
                cout << "   Tone: " << singer->getTone() << '\n';
            }
            // if musician is guitarist, print additional data
            else {
                Guitarist* guitarist = dynamic_cast<Guitarist*>(musician);
                if (guitarist != NULL) {
                    cout << "   Position: " << guitarist->getPosition() << '\n';
                    cout << "   Favorite Guitar Brand: " << guitarist->getFavoriteBrand() << '\n';
                    cout << "   Guitars:" << '\n';
                    // print guitars list
                    vector<Guitar> guitars = guitarist->getGuitars();
                    for (int j = 0; j < (int)guitars.size(); j++) {
                        cout << "      - " << guitars[j].getBrand() << " " << guitars[j].getType() << '\n';
                    }
                }
            }
        }

        cout << '\n';
        number++;
        sleepDelay(delay);
    }
}

// function to print guitars data
void printGuitars(vector<Guitar>& guitars, double delay) {
    cout << "=====================================" << '\n';
    cout << "   __         ___       __   __ " << '\n';
    cout << "  / _` |  | |  |   /\\  |__) /__`" << '\n';
    cout << "  \\__> \\__/ |  |  /~~\\ |  \\ .__/" << '\n';
    cout << "\n=====================================\n" << '\n';
    sleepDelay(delay);

    int number = 1;
    // print each data
    for (int i = 0; i < (int)guitars.size(); i++) {
        cout << number << ". Brand: " << guitars[i].getBrand() << '\n';
        cout << "   Type: " << guitars[i].getType() << '\n';
        cout << "   Strings:" << '\n';
        // print guitar strings
        vector<GuitarString> strings = guitars[i].getStrings();
        for (int j = 0; j < (int)strings.size(); j++) {
            cout << "      - Brand: " << strings[j].getStringBrand() 
                << ", Material: " << strings[j].getMaterial() 
                << ", Gauge: " << strings[j].getStringGauge() << '\n';
        }
        cout << '\n';
        number++;
        sleepDelay(delay);
    }
}
