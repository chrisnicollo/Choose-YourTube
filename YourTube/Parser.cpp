#include "Parser.hpp"

bool Parser::readFile(Graph& graph, std::ifstream& file, bool isRoot) {
    bool noErrors = true;
    std::string line;
    while (std::getline(file, line)) {
        if (readLine(graph, line, isRoot) == false) {
            noErrors = false;
        }
    }
    return noErrors;
}

bool Parser::readLine(Graph& graph, std::string line, bool isRoot) {
    std::istringstream inSS(line);
    std::vector<std::string> stats;
    std::vector<std::string> relatedIDs;
    std::string token;
    for (int i = 0; i < 9; i++) {
        if (inSS >> token) {
            if (token == "&") {
                if (i != 4) {
                    return false;
                }
                else { // Compound category type
                    std::string category = stats.at(i-1);
                    category += " & ";
                    inSS >> token;
                    category += token;
                    stats.at(--i) = category;
                }
            }
            else {
                stats.push_back(token);
            }
        }
        else {
            return false;
        }
    }
    while (inSS >> token) {
        relatedIDs.push_back(token);
    }
    graph.insertVideo(stats, relatedIDs, isRoot);
    return true;
}

bool Parser::readData(Graph& graph, std::string runName, std::string dirModifier) {
    bool noErrors = true;
    std::string dirPath = dirModifier + runName + "/";
    std::string filePath = dirPath + "0.txt";
    std::ifstream inFS;
    inFS.open(filePath);
    if (inFS.is_open()) {
        if (readFile(graph, inFS, true) == false) {
            noErrors = false;
        }
    }
    else {
        return false;
    }
    int fileNum = 1;
    std::string fileNumStr = std::to_string(fileNum);
    filePath = dirPath + fileNumStr + ".txt";
    inFS.close();
    inFS.open(filePath);
    while (inFS.is_open()) {
        if (readFile(graph, inFS, false) == false) {
            noErrors = false;
        }
        std::string fileNumStr = std::to_string(++fileNum);
        filePath = dirPath + fileNumStr + ".txt";
        inFS.close();
        inFS.open(filePath);
    }
    return noErrors;
}