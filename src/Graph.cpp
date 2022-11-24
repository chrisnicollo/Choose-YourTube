#include "Graph.hpp"

// ----------  TEMPORARY FILTER PLACEHOLDERS ---------- //
bool Graph::passesFilter(std::string videoID) {
    /// TODO: Make this call to the actual filter function
    /// To filter out videos with characteristics the user
    /// Doesn't want to see
    return true;
}

// ----------  MEMORY AND DATA MANAGEMENT ---------- //
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
    }
    idToVideo.clear();
}

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

// ----------  GRAPH TRAVERSAL HELPERS ---------- //
bool Graph::addToTraversal(std::unordered_set<std::string>& visited, std::string videoID) const {
    if (visited.find(videoID) == visited.end()) {
        visited.insert(videoID);
        if (passesFilter(videoID)) {
            return true;
        }
    }
    return false;
}

/// TODO: Delete this if we don't want to return null videos at all
Video* Graph::getCurrVideo(std::string currID) const {
    auto currVidIter = idToVideo.find(currID);
    if (currVidIter == idToVideo.end()) {
        Video* nullVid = new Video(currID, "", -1, "", -1, -1, -1, -1, -1, 
        std::vector<std::string>(), true);
        return nullVid;
    }
    return currVidIter->second;
}

// ----------  GRAPH MODIFICATION ---------- //
void Graph::insertRootVideo(
std::string id,
std::string uploaderUsername,
int age,
std::string category,
int length,
int numViews,
float overallRating,
int numRatings,
int numComments,
std::vector<std::string> relatedIDs) {
    insertVideo(id, uploaderUsername, age, category, length,
    numViews, overallRating, numRatings, numComments, relatedIDs);
    rootVideoIDs.push_back(id);
    
}

void Graph::insertVideo(
std::string id,
std::string uploaderUsername,
int age,
std::string category,
int length,
int numViews,
float overallRating,
int numRatings,
int numComments,
std::vector<std::string> relatedIDs) {
    Video* newVid = new Video(id, uploaderUsername, age, category, length,
    numViews, overallRating, numRatings, numComments, relatedIDs);
    idToVideo.emplace(id, newVid);
}

// ----------  GRAPH TRAVERSALS ---------- //
/// TODO: Check these return expected number of and type of results
/// TODO: Determine how to handle being inputted a value n greater than number of nodes?
/// TODO: How do we want to handle a video that's just an id and no other data? 
    /// Do we not want to show it, thus I don't return it?
    /// Right now, I am returning it but can change that
std::vector<Video*> Graph::traverseBreadthFirstN(std::string id, int n) const {
    std::vector<Video*> result;
    int count = 0;

    std::unordered_set<std::string> visited;
    std::queue<std::string> q;
    visited.insert(id);
    q.push(id);
    while (!q.empty() && count < n) {
        std::string currID = q.front();
        q.pop();
        Video* currVid = getCurrVideo(currID);
        result.push_back(currVid);
        for (int neighborInd = 0; neighborInd < currVid->getRelatedIDs().size(); neighborInd++) {
            std::string neighborID = currVid->getRelatedIDs().at(neighborInd);
            if (addToTraversal(visited, neighborID)) {
                q.push(neighborID);                
            }
        }
        n++;
    }
    return result;
}

/// FIXME: POSTORDER
std::vector<Video*> Graph::traversePostorderDepthFirstN(std::string id, int n) const {
    std::vector<Video*> result;

    return result;
}
