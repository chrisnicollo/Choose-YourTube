#include "Graph.hpp"
#include <fstream>
#include <sstream>

// Note: Each token of data in a line of input is separated by a \t
class Parser {
public:

    /// FIXME: deal with multi-word categories
    /// FIXME: why isn't line 4 working?
    /// TODO: Make helpers private
    // Returns false if there were any errors in reading the file
    static bool readFile(Graph& graph, std::ifstream& file, bool isRoot);
    // Returns false for bad input (consider changing to void if bool is unused)
    static bool readLine(Graph& graph, std::string line, bool isRoot);

    static bool readData(Graph& graph, std::string runName, std::string dirModifier = "../io-data/");



    /// TODO: Start from basics here. Read a stringline as a string stream,
    /// Then repeat that over and over with a file
    /// Then do that for all files

};
