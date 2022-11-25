#include "Graph.hpp"

// ----------  FILTERING ---------- //
bool Graph::passesFilter(Video* currVid) const {
    /// TODO: Make this call to the actual filter function
    /// To filter out videos with characteristics the user
    /// Doesn't want to see

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
int Graph::getSize() const {
    return size;
}

int Graph::getNumRootVideos() const {
    return rootVideoIDs.size();
}

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

std::vector<std::string> Graph::getRootVideoIDs() const {
    return rootVideoIDs;
}
