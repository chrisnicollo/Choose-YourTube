#ifndef SETTINGS_H
#define SETTINGS_H
#pragma once
#include <string>
using namespace std;

class Settings {
private:
    float minRating;
    int minViews;
    string maxDur;
    string minDur;
    string filterCategory;
    string startingVid;
    bool relatedVids;
public:
    Settings();
    void printSettings();
    // Get Functions
    float getMinRating();
    int getMinViews();
    string getMaxDur();
    string getMinDur();
    string getFilterCategory();
    string getStartingVid();
    bool getIfRelated();
    // Set Functions
    void setMinRating(float input);
    void setMinViews(int input);
    void setMaxDur(string input);
    void setMinDur(string input);
    void setFilterCategory(string input);
    void setStartingVid(string input);
    void setRelatedVids(bool input);
};

#endif // SETTINGS_H
