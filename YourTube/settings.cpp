#include "settings.h"

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

// Get Functions
float Settings::getMinRating() { return minRating; }
int Settings::getMinViews() { return minViews; }
string Settings::getMaxDur() { return maxDur; }
string Settings::getMinDur() { return minDur; }
string Settings::getFilterCategory() { return filterCategory; }
string Settings::getStartingVid() { return startingVid; }
bool Settings::wantRelatedVids() { return relatedVids; }

// Set Functions
void Settings::setMinRating(float input) { minRating = input; }
void Settings::setMinViews(int input) { minViews = input; }
void Settings::setMaxDur(string input) { maxDur = input; }
void Settings::setMinDur(string input) { minDur = input; }
void Settings::setFilterCategory(string input) { filterCategory = input; }
void Settings::setStartingVid(string input) { startingVid = input; }
void Settings::setRelatedVids(bool input) { relatedVids = input; }
