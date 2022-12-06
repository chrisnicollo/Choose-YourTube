#include "mainwindow.h"
#include "settings.h"
#include "Parser.hpp"
#include <QApplication>
#include <iostream>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings settings;
    MainWindow w(settings);
    Graph g;
    Parser p;
    p.readData(g, "test");
    vector<string> testing = g.getRootVideoIDs();
    cout << "test" << endl;
    for(unsigned i = 0; i < testing.size(); i++) {
        cout << testing[i] << endl;
    }
    w.show();
    return a.exec();
}

/*#include "Parser.hpp"
#include <iostream>
#include <typeinfo>


int main() {

    Graph g;

    bool success = Parser::readData(g, "0403", "../io-data/");
    // std::vector<std::string> roots = g.getRootVideoIDs();
    // for (int i = 0; i < roots.size(); i++) {
    //     std::cout << roots.at(i) << "\n";
    // }
    // std::cout << g.getSize();
    // std::cout << std::endl;
    // auto start = std::chrono::steady_clock::now();
    std::pair<std::vector<Video*>, double> breadthResult = g.traverseBreadthFirstN("W91sqAs-_-g", 21);
    // auto end = std::chrono::steady_clock::now();
    // std::chrono::duration<double> breadthTime = end-start;

    // start = std::chrono::steady_clock::now();
    std::pair<std::vector<Video*>, double> depthResult = g.traversePostorderDepthFirstN("W91sqAs-_-g", 10);
    // end = std::chrono::steady_clock::now();
    // std::chrono::duration<double> depthTime = end-start;

    std::cout << "breadth result:\n";
    for (int i = 0; i < breadthResult.first.size(); i++) {
        std::cout << breadthResult.first.at(i)->getID() << std::endl;
    }
    std::cout << "time taken: " << breadthResult.second << "s\n";

    std::cout << "\ndepth result:\n";
    for (int i = 0; i < depthResult.first.size(); i++) {
        std::cout << depthResult.first.at(i)->getID() << std::endl;
    }
    std::cout << "time taken: " << depthResult.second << "s\n";

    // std::vector<Video*> filteredRoots = g.getNFilteredRootVideos(10);
    // std::cout << "\nfiltered roots:\n";
    // for (int i = 0; i < filteredRoots.size(); i++) {
    //     std::cout << filteredRoots.at(i)->getID() << std::endl;
    // }
    // std::cout << "roots size: " << g.getNumRootVideos() << "\n";

    // bool success = Parser::readData(g, "input-files", "../test-io/");

    // std::ifstream inFS("../io-data/0403/3.txt");
    // if (inFS.is_open()) {
    //     std::cout << "file open\n";
    // }
    // else {
    //     std::cout << "file not open\n";
    // }
    // bool success = Parser::readFile(g, inFS, true);

    if (!success) {
        std::cout << "\nnot ";
     }
    std::cout << "a success!\n";

    std::cout << g.getSimilarityScore("", "W91sqAs-_-g") << std::endl;
    std::cout << g.getSimilarityScore("W91sqAs-_-g", "") << std::endl;
    std::cout << g.getSimilarityScore("W91sqAs-_-g", "oqcaJ4NrUKA") << std::endl;
    std::cout << g.getSimilarityScore(breadthResult.first.at(0), breadthResult.first.at(1)) << std::endl;
    g.setFilterInfo(Settings());
    std::vector<Video*> temp = g.getRootVideos();


    // std::string line = "W91sqAs-_-g	dusted21	776	Music	249	1556837	4.61	7314	3899	tZw-8RSyvh8	-L6tFCeR_ZQ	SgHk5JDCdx0	4U5dmIVBzq8	MwzSxbqyzcE	UFMx8fkpLNg	Jl2AaYYgIXo	XJaHmGD8UEk	gL3EjCPu-Q4	abGQ_ehWm2Y	_oPYs-LNYGo	GzqvzhpLfIg	f2uBfi4miC8	8Eaj9OZ--K0	mj7mYbHEasI	gJ0I92_1Vt8	n58uchRpgO0	jDVPJ_7dS3k	KizKliQvF_M	w8dpP4uQglk";
    // Parser::readLine(g, line, false);
    // line = "JVXcPrnwzHA	GetMoneyTV	776	Music	60	73467	4.28	72	61	JVXcPrnwzHA	mMZOChNioD4	BBNu1AErWAw	Ea8M0WtU7vs	REuYnkUjaJU	T0RshhRW4fE	DzYaIq9FDRc	Swa4FRX6rHE	fvPC1ABp4VE";
    // Parser::readLine(g, line, false);
    // line = "JVXcPrnwzHA	GetMoneyTV	776	Music	60	73467	4.28	72";
    // Parser::readLine(g, line, false);


    return 0;
}*/
