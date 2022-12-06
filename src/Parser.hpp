#pragma once
#include "Graph.hpp"
#include <fstream>
#include <sstream>

// Note: Each token of data in a line of input is separated by a \t
class Parser {
    /**
     * @brief Reads a line of video data and inserts a Video object to the graph.
     * 
     * @param graph reference of videos to add to.
     * @param line string to read from.
     * @param isRoot boolean that is true iff a Video is a 'root' from '0.txt'.
     * @return bool that is false if there is a data reading error.
     */
    static bool readLine(Graph& graph, std::string line, bool isRoot);

    /**
     * @brief Reads a file of video data and inserts corresponding Video objects to the graph.
     * 
     * @param graph reference of videos to add to.
     * @param file ifstream reference to read from.
     * @param isRoot boolean that is true iff the file is '0.txt'.
     * @return bool that is false if there is a data reading error.
     */
    static bool readFile(Graph& graph, std::ifstream& file, bool isRoot);

public:
    /**
     * @brief Reads a folder of video data and inserts corresponding Video objects to the graph.
     * 
     * @param graph reference of videos to add to.
     * @param runName innermost folder name with data.
     * @param dirModifier outer folder path; default is "../io-data/".
     * @return bool that is false if there is a data reading error.
     */
    static bool readData(Graph& graph, std::string runName, std::string dirModifier = "../io-data/");
};
