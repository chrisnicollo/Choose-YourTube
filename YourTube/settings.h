#ifndef SETTINGS_H
#define SETTINGS_H
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
    // Get Functions
    float getMinRating();
    int getMinViews();
    string getMaxDur();
    string getMinDur();
    string getFilterCategory();
    string getStartingVid();
    bool wantRelatedVids();
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
