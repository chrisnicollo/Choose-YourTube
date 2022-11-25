#include "Graph.hpp"

// ----------  TEMPORARY FILTER PLACEHOLDERS ---------- //
bool Graph::passesFilter(std::string videoID) {
    /// TODO: Make this call to the actual filter function
    /// To filter out videos with characteristics the user
    /// Doesn't want to see
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
/// TODO: Delete this if we don't want to return null videos at all
/*
Video* Graph::getCurrVideo(std::string currID) const {
    auto currVidIter = idToVideo.find(currID);
    if (currVidIter == idToVideo.end()) {
        /// TODO: Phase long constructor out of use
        // Video* nullVid = new Video(currID, "", -1, "", -1, -1, -1, -1, -1, 
        // std::vector<std::string>(), true);
        Video* nullVid = new Video(std::vector<std::string> {currID, "", "-1", "", "-1", "-1", "-1", "-1", "-1"},
        std::vector<std::string>(), true);
        return nullVid;
    }
    return currVidIter->second;
}
*/

bool Graph::addToTraversal(std::unordered_set<std::string>& visited, std::string videoID) const {
    if (visited.find(videoID) == visited.end()) {
        visited.insert(videoID);
        if (passesFilter(videoID)) {
            return true;
        }
    }
    return false;
}

void Graph::helperTraversePostorderDepthFirstN(std::string currID,
std::vector<Video*>& result, std::unordered_set<std::string>& visited, int n) const {
    auto currVidIter = idToVideo.find(currID);
    if (result.size() < n && currVidIter != idToVideo.end()) {
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
Graph::Graph() {} /// FIXME: Should this do anything?

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
/// TODO: Check these return expected number of and type of results
/// TODO: Determine how to handle being inputted a value n greater than number of nodes?
/// TODO: How do we want to handle a video that's just an id and no other data? 
    /// Do we not want to show it, thus I don't return it?
    /// Right now, I am returning it but can change that
std::vector<Video*> Graph::traverseBreadthFirstN(std::string startID, int n) const {
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

    // q.push(startID);
    while (!q.empty() && result.size() < n) {
        std::string currID = q.front();
        q.pop();
        auto currVidIter = idToVideo.find(currID);
        if (currVidIter != idToVideo.end()) {
            Video* currVid = currVidIter->second;
            result.push_back(currVid);
            for (int neighborInd = 0; neighborInd < currVid->getRelatedIDs().size(); neighborInd++) {
                std::string neighborID = currVid->getRelatedIDs().at(neighborInd);
                if (addToTraversal(visited, neighborID)) {
                    /// TODO: Delete debug statement
                    if (neighborID == startID) {
                        int i = 0;
                    }
                    q.push(neighborID);                
                }
            }
        }

    }
    return result;
}

std::vector<Video*> Graph::traversePostorderDepthFirstN(std::string startID, int n) const {
    std::vector<Video*> result;
    std::unordered_set<std::string> visited;

    // Avoid adding startID to result
    auto startVidIter = idToVideo.find(startID);
    if (startVidIter != idToVideo.end()) {
        Video* startVid = startVidIter->second;
        for (int neighborInd = 0; neighborInd < startVid->getRelatedIDs().size(); neighborInd++) {
            std::string neighborID = startVid->getRelatedIDs().at(neighborInd);
            helperTraversePostorderDepthFirstN(neighborID, result, visited, n);
        }
    }
    return result;
}

// ----------  GETTERS ---------- //
int Graph::getSize() const {
    return size;
}

std::vector<std::string> Graph::getRootVideoIDs() const {
    return rootVideoIDs;
}
