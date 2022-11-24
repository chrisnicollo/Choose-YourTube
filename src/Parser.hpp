#include "Graph.hpp"
#include <fstream>

struct Parser {
    static void readData(Graph& graph, std::string runName, std::string dirModifier = "../io-data/");
    static void readRootFile(Graph& graph, std::fstream file);
    static void readFile(Graph& graph, std::fstream file);
    // static void readRootLine
    // static void readLine

    /// TODO: Start from basics here. Read a stringline as a string stream,
    /// Then repeat that over and over with a file
    /// Then do that for all files

};
