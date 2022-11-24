#include "Video.hpp"

// ----------  CONSTRUCTOR ---------- //
Video::Video(std::string id,
std::string uploaderUsername,
int age,
std::string category,
int length,
int numViews,
float overallRating,
int numRatings,
int numComments,
std::vector<std::string> relatedIDs,
bool nullState) {
    this->id = id;
    this->uploaderUsername = uploaderUsername;
    this->age = age;
    this->category = category;
    this->length = length;
    this->numViews = numViews;
    this->overallRating = overallRating;
    this->numRatings = numRatings;
    this-> numComments = numComments;
    this->relatedIDs = relatedIDs;
}

// ----------  GETTER FUNCTIONS ---------- //
std::string Video::getID() const {
    return id;
}

std::string Video::getUploaderUsername() const {
    return uploaderUsername;
}

int Video::getAge() const {
    return age;
}

std::string Video::getCategory() const {
    return category;
}

int Video::getLength() const {
    return length;
}

int Video::getNumViews() const {
    return numViews;
}

float Video::getOverallRating() const {
    return overallRating;
}

int Video::getNumRatings() const {
    return numRatings;
}

int Video::getNumComments() const {
    return numComments;
}

std::vector<std::string> Video::getRelatedIDs() const {
    return relatedIDs;
}

bool Video::isNull() const {
    return nullState;
}

std::string Video::getURL() const{
    std::string url = "https://www.youtube.com/watch?v=";
    url += id;
    return url;
}
