#include "Video.hpp"

// ----------  CONSTRUCTORS ---------- //
Video::Video(std::vector<std::string> stats, std::vector<std::string> relatedIDs) {
    this->id = stats.at(0);
    this->uploaderUsername = stats.at(1);
    this->age = stoi(stats.at(2));
    this->category = stats.at(3);
    this->length = stoi(stats.at(4));
    this->numViews = stoi(stats.at(5));
    this->overallRating = std::stof(stats.at(6));
    this->numRatings = stoi(stats.at(7));
    this-> numComments = stoi(stats.at(8));
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

std::string Video::getURL() const{
    std::string url = "https://www.youtube.com/watch?v=";
    url += id;
    return url;
}
