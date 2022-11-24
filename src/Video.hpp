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
    bool nullState;
    // 'null' is to account for finding ID's without data in the graph

public:
    // ----------  CONSTRUCTORS ---------- //
    /// TODO: Phase long constructor out of use
    /*
    Video(
    std::string id,
    std::string uploaderUsername,
    int age,
    std::string category,
    int length,
    int numViews,
    float overallRating,
    int numRatings,
    int numComments,
    std::vector<std::string> relatedIDs,
    bool nullState = false);
    */

    Video(std::vector<std::string> stats, std::vector<std::string> relatedIDs,
    bool nullState = false);

    // ----------  GETTER FUNCTIONS ---------- //
    std::string getID() const;
    std::string getUploaderUsername() const;
    int getAge() const; // Note that a greater number here means a younger video
    std::string getCategory() const;
    int getLength() const;
    int getNumViews() const;
    float getOverallRating() const;
    int getNumRatings() const;
    int getNumComments() const;
    std::vector<std::string> getRelatedIDs() const;
    bool isNull() const;
    std::string getURL() const;
};
