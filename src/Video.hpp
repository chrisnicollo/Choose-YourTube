#pragma once
#include <string>
#include <vector>

class Video {
    std::string id;
    std::string uploaderUsername;
    int age;
    std::string category;
    int length;
    int numViews;
    float overallRating;
    int numRatings;
    int numComments;
    std::vector<std::string> relatedIDs;

public:
    // ----------  CONSTRUCTORS ---------- //
    Video(std::vector<std::string> stats, std::vector<std::string> relatedIDs);

    // ----------  GETTER FUNCTIONS ---------- //
    std::string getID() const;
    std::string getUploaderUsername() const;
    int getAge() const; // Note that a greater number here means a younger video
    std::string getCategory() const;
    int getLength() const;
    int getNumViews() const;
    float getOverallRating() const; // total number of ratings
    int getNumRatings() const; // actual rating
    int getNumComments() const;
    std::vector<std::string> getRelatedIDs() const;
    std::string getURL() const;
};
