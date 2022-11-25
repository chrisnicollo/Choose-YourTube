#include "Parser.hpp"

/// TODO: Get rid of this include state after tests
#include <iostream>

bool Parser::readFile(Graph& graph, std::ifstream& file, bool isRoot) {
    bool noErrors = true;
    std::string line;
    /// TODO: Delete debugging variable
    // int count = 0;
    while (std::getline(file, line)) {
        /// TODO: Delete debug print statement
        // std::cout << "Reading in line " << ++count << std::endl;
        if (readLine(graph, line, isRoot) == false) {
            noErrors = false;
        }
    }
    return noErrors;
}

bool Parser::readLine(Graph& graph, std::string line, bool isRoot) {
    // std::cout << "The current line is: " << line << std::endl;
    std::istringstream inSS(line);
    std::vector<std::string> stats;
    std::vector<std::string> relatedIDs;
    std::string token;
    for (int i = 0; i < 9; i++) {
        if (inSS >> token) {
            if (token == "&") {
                if (i != 4) {
                    /// TODO: Delete debug print statement
                    std::cout << "error in reading\n";
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
            /// TODO: Get rid of debug print statement
            std::cout << "error in reading";
            if (i == 1) {
                // Note that this is sometimes to be expected, as there are
                // Lines with just ids and nothing after
                // Mostly due to already having been visited in their level
                std::cout << " (missing file data)";
            }
            std::cout << std::endl;
            return false;
        }
    }
    while (inSS >> token) {
        relatedIDs.push_back(token);
    }
    graph.insertVideo(stats, relatedIDs, isRoot);
    /// TODO: Delete debug print statement
    // std::cout << "Printing out stats\n";
    // for (int i = 0; i < stats.size(); i++) {
    //     std::cout << stats.at(i) << ", ";
    // }
    // std::cout << std::endl;
    // std::cout << "Printing out relatedIDs\n";
    // for (int i = 0; i < relatedIDs.size(); i++) {
    //     std::cout << relatedIDs.at(i) << ", ";
    // }
    // std::cout << std::endl << std::endl;
    return true;
}

bool Parser::readData(Graph& graph, std::string runName, std::string dirModifier) {
    bool noErrors = true;
    std::string dirPath = dirModifier + runName + "/";
    std::string filePath = dirPath + "0.txt";
    /// TODO: Delete debug print statement
    // std::cout << filePath <<"\n";
    std::ifstream inFS;
    inFS.open(filePath);
    if (inFS.is_open()) {
        if (readFile(graph, inFS, true) == false) {
            noErrors = false;
        }
    }
    else {
        /// TODO: Delete debug print statement
        std::cout << "invalid data location\n";
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
        /// TODO: Delete debug print statement
        // std::cout << "trying to visit " << filePath << std::endl;
        inFS.close();
        inFS.open(filePath);
    }
    return noErrors;
}