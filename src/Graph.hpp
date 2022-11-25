#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <chrono>
#include "Video.hpp"

class Graph {
    std::vector<std::string> rootVideoIDs;
    std::unordered_map<std::string, Video*> idToVideo;
    int size = 0;

    /// FIXME: store the object containing the info about the filter
    /// FIXME: How do I get the info to know
    /// what characteristics to filter out
    /// TODO: create a function that takes in the filter detail object

    // ----------  FILTERING ---------- //

    /**
     * @brief Determines if a Video passes the filter.
     * 
     * @param currVid Video* being checked
     * @return boolean that is true iff the Video passes the filter.
     */
    bool passesFilter(Video* currVid) const;

    // ----------  MEMORY AND DATA MANAGEMENT HELPERS ---------- //
    void copyVals(const Graph& original);
    void deleteVals();

    // ----------  GRAPH TRAVERSAL HELPERS ---------- //

    /**
     * @brief Determines if a video associated with an ID should be visited in a traversal.
     * Considers if the ID has already been visited.
     * Considers if there is no associated mapping from ID to Video.
     * Considers if the associated Video passes the filter (using passesFilter).
     * 
     * @param visited reference to a set representing the visited IDs.
     * @param videoID string vector of the video's ID.
     * @return boolean that is true iff the video with that ID should be visited.
     */
    bool addToTraversal(std::unordered_set<std::string>& visited, std::string videoID) const;

    void helperTraversePostorderDepthFirstN(std::string currID,
    std::vector<Video*>& result, std::unordered_set<std::string>& visited, int n) const;

public:
    // ----------  MEMORY AND DATA MANAGEMENT FUNCTIONS ---------- //
    Graph();
    Graph(const Graph& original);
    Graph& operator=(const Graph& original);
    ~Graph();

    // ----------  GRAPH CREATION ---------- //

    /**
     * @brief Inserts a Video object to the graph.
     * 
     * @param stats string vector of the details of the video, in order of appearance in a file.
     * @param relatedIDs string vector of the IDs of related videos to the video.
     * @param isRoot boolean that is true iff a Video is a 'root' from '0.txt'.
     * @return void.
     */
    void insertVideo(std::vector<std::string> stats,
    std::vector<std::string> relatedIDs, bool isRoot);

    // ----------  GRAPH TRAVERSALS ---------- //

    /**
     * @brief Gets the first n Videos passing the filter in a breadth-first traversal.
     * Measures how long this takes.
     * Returns fewer than n results if not enough Videos pass the filter.
     * 
     * @param startID string ID of a root video.
     * @param n int number of videos to return.
     * @return std::pair<std::vector<Video*>, double> pair of a vector of Video* and a time (in seconds).
     */
    std::pair<std::vector<Video*>, double> traverseBreadthFirstN(std::string startID, int n) const; 

    /**
     * @brief Gets the first n Videos passing the filter in a postorder depth-first traversal.
     * Measures how long this takes.
     * Returns fewer than n results if not enough Videos pass the filter.
     * 
     * @param startID string ID of a root video.
     * @param n int number of videos to return.
     * @return std::pair<std::vector<Video*>, double> pair of a vector of Video* and a time (in seconds).
     */
    std::pair<std::vector<Video*>, double> traversePostorderDepthFirstN(std::string startID, int n) const;

    // ----------  GETTERS ---------- //

    /**
     * @brief Gets the number of Videos in the graph.
     * 
     * @return int number of Videos.
     */
    int getSize() const;

    /**
     * @brief Gets the number of 'root' Videos from '0.txt' in the graph.
     * 
     * @return int number of root Videos.
     */
    int getNumRootVideos() const;

    /**
     * @brief Gets the first n 'root' Videos passing the filter.
     * 
     * @param n int number of videos to return.
     * @return std::vector<Video*> of filtered videos.
     */
    std::vector<Video*> getNFilteredRootVideos(int n) const;

    /// TODO: Delete function after debugging
    std::vector<std::string> getRootVideoIDs() const;
};
