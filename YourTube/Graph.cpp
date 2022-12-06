#include "Graph.hpp"

// ----------  FILTERING ---------- //

/**
 * @brief Determines if a Video passes the filter.
 * 
 * @param currVid Video* being checked
 * @return boolean that is true iff the Video passes the filter.
 */
bool Graph::passesFilter(Video* currVid) const {
    /// TODO: Make this call to the actual filter function
    /// To filter out videos with characteristics the user doesn't want to see

    // The below commented out lines are just a basic example filter I tested
    // float rating = currVid->getOverallRating();
    // bool status = rating > 4.5;
    // return status;
    return true;
}

// ----------  MEMORY AND DATA MANAGEMENT HELPERS ---------- //

void Graph::copyVals(const Graph& original) {
    for (int i = 0; i < original.rootVideoIDs.size(); i++) {
        this->rootVideoIDs.push_back(original.rootVideoIDs.at(i));
    }
    for (auto iter = original.idToVideo.begin(); iter != original.idToVideo.end(); iter++) {
        this->idToVideo.emplace(iter->first, iter->second);
    }
}

void Graph::deleteVals() {
    rootVideoIDs.clear();
    for (auto iter = idToVideo.begin(); iter != idToVideo.end(); iter++) {
        delete iter->second;
        size--;
    }
    idToVideo.clear();
}

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
bool Graph::addToTraversal(std::unordered_set<std::string>& visited, std::string videoID) const {
    if (visited.find(videoID) == visited.end()) {
        visited.insert(videoID);
        auto currVidIter = idToVideo.find(videoID);
        if (currVidIter != idToVideo.end()) {
            return passesFilter(currVidIter->second);
        }
    }
    return false;
}

void Graph::helperTraversePostorderDepthFirstN(std::string currID,
std::vector<Video*>& result, std::unordered_set<std::string>& visited, int n) const {
    if (result.size() < n) {
        auto currVidIter = idToVideo.find(currID);
        Video* currVid = currVidIter->second;
        for (int i = 0; i < currVid->getRelatedIDs().size(); i++) {
            std::string neighborID = currVid->getRelatedIDs().at(i);
            if (addToTraversal(visited, neighborID)) {
                helperTraversePostorderDepthFirstN(neighborID, result, visited, n);
            }
        }
        if (result.size() < n) {
            result.push_back(currVid);
        }
    }
}

// ----------  MEMORY AND DATA MANAGEMENT FUNCTIONS ---------- //

/// FIXME: Should this do anything?
Graph::Graph() {}

Graph::Graph(const Graph& original) {
    copyVals(original);
}

Graph& Graph::operator=(const Graph& original) {
    deleteVals();
    copyVals(original);
    return *this;
}

Graph::~Graph() {
    deleteVals();
}  

// ----------  GRAPH CREATION ---------- //

/**
 * @brief Inserts a Video object to the graph.
 * 
 * @param stats string vector of the details of the video, in order of appearance in a file.
 * @param relatedIDs string vector of the IDs of related videos to the video.
 * @param isRoot boolean that is true iff a Video is a 'root' from '0.txt'.
 * @return void.
 */
void Graph::insertVideo(std::vector<std::string> stats,
std::vector<std::string> relatedIDs, bool isRoot) {
    Video* newVid = new Video(stats, relatedIDs);
    idToVideo.emplace(newVid->getID(), newVid);
    if (isRoot) {
        rootVideoIDs.push_back(newVid->getID());
    }
    size++;
}

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
std::pair<std::vector<Video*>, double> Graph::traverseBreadthFirstN(std::string startID, int n) const {
    auto startTime = std::chrono::steady_clock::now();

    std::vector<Video*> result;
    std::unordered_set<std::string> visited;
    std::queue<std::string> q;
    visited.insert(startID);

    // Avoid adding startID to result
    auto startVidIter = idToVideo.find(startID);
    if (startVidIter != idToVideo.end()) {
        Video* startVid = startVidIter->second;
        for (int neighborInd = 0; neighborInd < startVid->getRelatedIDs().size(); neighborInd++) {
            std::string neighborID = startVid->getRelatedIDs().at(neighborInd);
            if (addToTraversal(visited, neighborID)) {
                q.push(neighborID);                
            }
        }
    }

    // Continue from after startID
    while (!q.empty() && result.size() < n) {
        std::string currID = q.front();
        q.pop();
        auto currVidIter = idToVideo.find(currID);
        Video* currVid = currVidIter->second;
        result.push_back(currVid);
        for (int neighborInd = 0; neighborInd < currVid->getRelatedIDs().size(); neighborInd++) {
            std::string neighborID = currVid->getRelatedIDs().at(neighborInd);
            if (addToTraversal(visited, neighborID)) {
                q.push(neighborID);                
            }
        }
    }

    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeDiff = endTime-startTime;
    double runTime = timeDiff.count();
    return std::pair<std::vector<Video*>, double>(result, runTime);
}

/**
 * @brief Gets the first n Videos passing the filter in a postorder depth-first traversal.
 * Measures how long this takes.
 * Returns fewer than n results if not enough Videos pass the filter.
 * 
 * @param startID string ID of a root video.
 * @param n int number of videos to return.
 * @return std::pair<std::vector<Video*>, double> pair of a vector of Video* and a time (in seconds).
 */
std::pair<std::vector<Video*>, double> Graph::traversePostorderDepthFirstN(std::string startID, int n) const {
    auto startTime = std::chrono::steady_clock::now();
    std::vector<Video*> result;
    std::unordered_set<std::string> visited;

    // Avoid adding startID to result
    visited.insert(startID);
    auto startVidIter = idToVideo.find(startID);
    if (startVidIter != idToVideo.end()) {
        Video* startVid = startVidIter->second;
        for (int neighborInd = 0; neighborInd < startVid->getRelatedIDs().size(); neighborInd++) {
            std::string neighborID = startVid->getRelatedIDs().at(neighborInd);
            if (addToTraversal(visited, neighborID)) {
                helperTraversePostorderDepthFirstN(neighborID, result, visited, n);
            }
        }
    }

    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> timeDiff = endTime-startTime;
    double runTime = timeDiff.count();
    return std::pair<std::vector<Video*>, double>(result, runTime);
}

// ----------  GETTERS ---------- //

/**
 * @brief Gets the number of Videos in the graph.
 * 
 * @return int number of Videos.
 */
int Graph::getSize() const {
    return size;
}

/**
 * @brief Gets the number of 'root' Videos from '0.txt' in the graph.
 * 
 * @return int number of root Videos.
 */
int Graph::getNumRootVideos() const {
    return rootVideoIDs.size();
}

/**
 * @brief Gets the first n 'root' Videos passing the filter.
 * 
 * @param n int number of videos to return.
 * @return std::vector<Video*> of filtered videos.
 */
std::vector<Video*> Graph::getNFilteredRootVideos(int n) const {
    std::vector<Video*> result;
    int ind = 0;
    while (ind < rootVideoIDs.size() && result.size() < n) {
        Video* currVid = idToVideo.find(rootVideoIDs.at(ind++))->second;
        if (passesFilter(currVid)) {
            result.push_back(currVid);
        }
    }
    return result;
}


/**
 * @brief Gets the similarity scores between two videos.
 * 
 * @param firstVidID string ID of one Video.
 * @param secondVidID string ID of the other Video.
 * @return float of the similarity score.
 */
float Graph::getSimilarityScore(std::string firstVidID, std::string secondVidID) const {
    auto firstVidIter = idToVideo.find(firstVidID);
    auto secondVidIter = idToVideo.find(secondVidID);
    if (firstVidIter != idToVideo.end() && secondVidIter != idToVideo.end()) {
        return getSimilarityScore(firstVidIter->second, secondVidIter->second);
    }
    else {
        return -1;
    }
}

/**
 * @brief Gets the similarity scores between two videos.
 * 
 * @param firstVid pointer to one Video.
 * @param secondVid pointer to the other Video.
 * @return float of the similarity score.
 */
float Graph::getSimilarityScore(Video* firstVid, Video* secondVid) const {
    /// TODO: Make this call to the actual scoring function
    return 1;
}

std::vector<std::string> Graph::getRootVideoIDs() const {
    return rootVideoIDs;
}

Video* Graph::getVideoByID(std::string vidID) {
    return idToVideo[vidID];
}

std::vector<Video*> Graph::getRootVideos() const {
    std::vector<Video*> result;
    for (int i = 0; i < rootVideoIDs.size(); i++) {
        result.push_back(idToVideo.at(rootVideoIDs.at(i)));
    }
    return result;
}

// ----------  SETTERS ---------- //

/**
 * @brief Sets the Settings object that defines the Video filter
 * within the graph object.
 * 
 * @param filterInfo Settings object that contains filter data.
 * @return void.
 */
void Graph::setFilterInfo(Settings filterInfo) {
    this->filterInfo = filterInfo;
}
