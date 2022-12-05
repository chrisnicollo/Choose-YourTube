#include "settings.h"
#include <iostream>
using namespace std;

// Constructor
Settings::Settings() {
    minRating = 0.0;
    minViews = 0;
    maxDur = "";
    minDur = "00:00";
    filterCategory = "";
    startingVid = "Not Specified";
    relatedVids = false;
}

// Print for testing
void Settings::printSettings() {
    cout << "Starting Video: " << getStartingVid() << endl;
    cout << "Showing Related Videos? " << getIfRelated() << endl;
    cout << endl;
    cout << "Minimum Rating: " << getMinRating() << endl;
    cout << "Minimum View Count: " << getMinViews() << endl;
    cout << "Minimum Duration: " << getMinDur() << endl;
    cout << "Maximum Duration: " << getMaxDur() << endl;
    cout << "Category: " << getFilterCategory() << endl;
}

// Get Functions
float Settings::getMinRating() { return minRating; }
int Settings::getMinViews() { return minViews; }
string Settings::getMaxDur() { return maxDur; }
string Settings::getMinDur() { return minDur; }
string Settings::getFilterCategory() { return filterCategory; }
string Settings::getStartingVid() { return startingVid; }
bool Settings::getIfRelated() { return relatedVids; }

// Set Functions
void Settings::setMinRating(float input) { minRating = input; }
void Settings::setMinViews(int input) { minViews = input; }
void Settings::setMaxDur(string input) { maxDur = input; }
void Settings::setMinDur(string input) { minDur = input; }
void Settings::setFilterCategory(string input) { filterCategory = input; }
void Settings::setStartingVid(string input) { startingVid = input; }
void Settings::setRelatedVids(bool input) { relatedVids = input; }
