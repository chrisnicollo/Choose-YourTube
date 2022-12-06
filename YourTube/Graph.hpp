#pragma once
#include "Video.hpp"
#include "../YourTube/settings.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <chrono>

class Graph {
    std::vector<std::string> rootVideoIDs;
    std::unordered_map<std::string, Video*> idToVideo;
    Settings filterInfo;
    int size = 0;
    int testing;

    // ----------  FILTERING ---------- //

    bool passesFilter(Video* currVid) const;

    // ----------  MEMORY AND DATA MANAGEMENT HELPERS ---------- //
    void copyVals(const Graph& original);
    void deleteVals();

    // ----------  GRAPH TRAVERSAL HELPERS ---------- //

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

    void insertVideo(std::vector<std::string> stats,
    std::vector<std::string> relatedIDs, bool isRoot);

    // ----------  GRAPH TRAVERSALS ---------- //

    std::pair<std::vector<Video*>, double> traverseBreadthFirstN(std::string startID, int n) const; 
    std::pair<std::vector<Video*>, double> traversePostorderDepthFirstN(std::string startID, int n) const;

    // ----------  GETTERS ---------- //

    int getSize() const;
    int getNumRootVideos() const;
    std::vector<Video*> getNFilteredRootVideos(int n) const;
    float getSimilarityScore(std::string firstVidID, std::string secondVidID) const;
    float getSimilarityScore(Video* firstVid, Video* secondVid) const;
    Video* getVideoByID(std::string vidID);
    /// TODO: Delete function after debugging. Please use only for debugging and not actual implementations
    std::vector<std::string> getRootVideoIDs() const;
    /// TODO: Delete function after debugging. Please use only for debugging and not actual implementations
    std::vector<Video*> getRootVideos() const;

    // ----------  SETTERS ---------- //

    void setFilterInfo(Settings filterInfo);
};
