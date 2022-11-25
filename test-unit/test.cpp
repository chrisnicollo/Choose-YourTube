#define CATCH_CONFIG_MAIN
#include "../src/main.cpp"
#include "catch.hpp"
#include <iostream>

// Include any necessary files

/*
	To check output (At the Project3 directory):
		g++ -std=c++14 -Werror -Wuninitialized -o build/test test-unit/test.cpp src/*.cpp && build/test
*/

TEST_CASE("Test Case 1", "[non-null video]"){
    std::string id = "W91sqAs-_-g";
    std::string uploaderUsername = "dusted21";
    int age = 776;
    std::string category = "Music";
    int length = 249;
    int numViews = 1556837;
    float overallRating = 4.61;
    int numRatings = 7314;
    int numComments = 3899;
    std::vector<std::string> relatedIDs = {
		"tZw-8RSyvh8", "-L6tFCeR_ZQ", "SgHk5JDCdx0", "4U5dmIVBzq8", "MwzSxbqyzcE",
		"UFMx8fkpLNg", "Jl2AaYYgIXo", "XJaHmGD8UEk", "gL3EjCPu-Q4", "abGQ_ehWm2Y",
		"_oPYs-LNYGo", "GzqvzhpLfIg", "f2uBfi4miC8", "8Eaj9OZ--K0", "mj7mYbHEasI",
		"gJ0I92_1Vt8", "n58uchRpgO0", "jDVPJ_7dS3k", "KizKliQvF_M", "w8dpP4uQglk"
	};
	/*
    Video vid(id, uploaderUsername, age, category, length,
	 numViews, overallRating, numRatings, numComments, relatedIDs);

	REQUIRE(vid.getID() == id);
	REQUIRE(vid.getUploaderUsername() == uploaderUsername);
	REQUIRE(vid.getAge() == age);
	REQUIRE(vid.getCategory() == category);
	REQUIRE(vid.getLength() == length);
	REQUIRE(vid.getNumViews() == numViews);
	REQUIRE(vid.getOverallRating() == overallRating);
	REQUIRE(vid.getNumRatings() == numRatings);
	REQUIRE(vid.getNumComments() == numComments);
	REQUIRE(vid.getRelatedIDs() == relatedIDs);
	REQUIRE(vid.getURL() == "https://www.youtube.com/watch?v=W91sqAs-_-g");
	REQUIRE(vid.isNull() == false);

	std::unordered_map<std::string, Video> temp;
    bool x = true;
    if (x == true) {
        temp.emplace(id, vid);
    }
    auto iter = temp.begin();
    std::cout << iter->first << ", " << iter->second.getURL();
	*/
	// Checking creating videos with vectors works
	Video vid_vec(std::vector<std::string> {id, uploaderUsername, "776", category, "249",
	"1556837", "4.61", "7314", "3899"}, relatedIDs);

	REQUIRE(vid_vec.getID() == id);
	REQUIRE(vid_vec.getUploaderUsername() == uploaderUsername);
	REQUIRE(vid_vec.getAge() == age);
	REQUIRE(vid_vec.getCategory() == category);
	REQUIRE(vid_vec.getLength() == length);
	REQUIRE(vid_vec.getNumViews() == numViews);
	REQUIRE(vid_vec.getOverallRating() == overallRating);
	REQUIRE(vid_vec.getNumRatings() == numRatings);
	REQUIRE(vid_vec.getNumComments() == numComments);
	REQUIRE(vid_vec.getRelatedIDs() == relatedIDs);
	REQUIRE(vid_vec.getURL() == "https://www.youtube.com/watch?v=W91sqAs-_-g");
}


TEST_CASE("Test Case 2", "[null video]"){
    std::string id = "W91sqAs-_-g";
	std::vector<std::string> emptyVec;
	/*
    Video vid(id, "", -1, "", -1, -1, -1, -1, -1, 
    std::vector<std::string>(), true);

	REQUIRE(vid.getID() == id);
	REQUIRE(vid.getUploaderUsername() == "");
	REQUIRE(vid.getAge() == -1);
	REQUIRE(vid.getCategory() == "");
	REQUIRE(vid.getLength() == -1);
	REQUIRE(vid.getNumViews() == -1);
	REQUIRE(vid.getOverallRating() == -1);
	REQUIRE(vid.getNumRatings() == -1);
	REQUIRE(vid.getNumComments() == -1);
	REQUIRE(vid.getRelatedIDs() == emptyVec);
	REQUIRE(vid.getURL() == "https://www.youtube.com/watch?v=W91sqAs-_-g");
	// REQUIRE(vid.isNull() == true);
	// REQUIRE(vid.isNull() == vid.isNull());
	// REQUIRE(true == true);
	REQUIRE(vid.getRelatedIDs().size() == 0);

	for (int i = 0; i < vid.getRelatedIDs().size(); i++) {
		std::cout << "item " << i << ": " << vid.getRelatedIDs().at(i) << "\n";
		emptyVec.push_back(vid.getRelatedIDs().at(i));
	}
	REQUIRE(emptyVec.size() == 0);
	if (vid.isNull()) {
		std::cout << "\nnull video\n";
	}
	std::cout << vid.isNull();
	*/
	// Checking creating videos with vectors works
	Video vid_vec(std::vector<std::string> {id, "", "-1", "", "-1",
	"-1", "-1", "-1", "-1"}, std::vector<std::string>());

	REQUIRE(vid_vec.getID() == id);
	REQUIRE(vid_vec.getUploaderUsername() == "");
	REQUIRE(vid_vec.getAge() == -1);
	REQUIRE(vid_vec.getCategory() == "");
	REQUIRE(vid_vec.getLength() == -1);
	REQUIRE(vid_vec.getNumViews() == -1);
	REQUIRE(vid_vec.getOverallRating() == -1);
	REQUIRE(vid_vec.getNumRatings() == -1);
	REQUIRE(vid_vec.getNumComments() == -1);
	REQUIRE(vid_vec.getRelatedIDs() == emptyVec);
	REQUIRE(vid_vec.getURL() == "https://www.youtube.com/watch?v=W91sqAs-_-g");
	// REQUIRE(vid_vec.isNull() == true);
	// REQUIRE(vid_vec.isNull() == vid.isNull());
	// REQUIRE(true == true);
	REQUIRE(vid_vec.getRelatedIDs().size() == 0);
}

TEST_CASE("Test Case 3", "[create graph][small]") {
    std::string id = "W91sqAs-_-g";
    std::string uploaderUsername = "dusted21";
    int age = 776;
    std::string category = "Music";
    int length = 249;
    int numViews = 1556837;
    float overallRating = 4.61;
    int numRatings = 7314;
    int numComments = 3899;
	std::vector<std::string> stats = {id, uploaderUsername, "776", category, "249",
	"1556837", "4.61", "7314", "3899"};
    std::vector<std::string> relatedIDs = {
		"tZw-8RSyvh8", "-L6tFCeR_ZQ", "SgHk5JDCdx0", "4U5dmIVBzq8", "MwzSxbqyzcE",
		"UFMx8fkpLNg", "Jl2AaYYgIXo", "XJaHmGD8UEk", "gL3EjCPu-Q4", "abGQ_ehWm2Y",
		"_oPYs-LNYGo", "GzqvzhpLfIg", "f2uBfi4miC8", "8Eaj9OZ--K0", "mj7mYbHEasI",
		"gJ0I92_1Vt8", "n58uchRpgO0", "jDVPJ_7dS3k", "KizKliQvF_M", "w8dpP4uQglk"
	};
	Graph g;
	// first insert
	g.insertVideo(stats, relatedIDs, true);
	REQUIRE(g.getSize() == 1);
	REQUIRE(g.getRootVideoIDs() == std::vector<std::string> {"W91sqAs-_-g"});

	// second insert
	stats.clear();
	stats = {
		"Tz_Ees_-kE4",	"palgy83",	"772",	"Comedy",	"456",	"64195",	"4.76",	"316",	"117"
	};
	relatedIDs.clear();
	relatedIDs = {
		"WjgxlqOlLFI",	"C7v6flubU64",	"AcFGUzg3tRQ",	"r-y96G3Ld2Y",	"RcLlwSA0MGI",	"ZOM6hkS6oMs",	"AzLXvGXm6GQ",	"uBVp0dgvbHc",	"dhAvj3xLi28",	"MN3_pRnT0Hs",	"NEjHAOJ3Vmw",	"zQSZFa03ZlI",	"2Up9LGlucv0",	"rBCFT7Sdt5w",	"b-_R0hmgwo4",	"X5IBJQk5LwA",	"q5kfujtWUkI",	"6j3KJvx85vk",	"ofhxOThaMIA",	"av1oymc77kc"
	};
	g.insertVideo(stats, relatedIDs, true);
	REQUIRE(g.getSize() == 2);
	REQUIRE(g.getRootVideoIDs() == std::vector<std::string> {"W91sqAs-_-g", "Tz_Ees_-kE4"});

	// third insert
	stats.clear();
	stats = {
		"BcEg5VmcL7s",	"CapnOAwesome",	"772",	"People & Blogs",	"1057",	"4163",	"4.37",	"315",	"239"
	};
	relatedIDs.clear();
	relatedIDs = {
		"oqYqL07MMRE"	"pGXfuz2ErAo"	"Zqj-iN1xILQ"	"rdo9AprmLbU"	"UVh47R2J7qI"	"eh5PJdhhYuY"	"_7Dzs6OLD40"	"HiXFR62IGQ0"	"RHDnI3cZ7Tk"	"L5jSa-QqX_s"	"50G6gKQ7iDQ"	"xp6sbC--d68"	"GNr0zEwcUAg"	"l_QMv1Q9M9w"	"fZyEv96Fiyo"	"H30UAP8x4Dc"	"Wgu345gtpJY"	"2NztFqqOYuI"	"JcbmH1qsZYk"	"P3fHY1T89Pw"
	};
	g.insertVideo(stats, relatedIDs, false);
	REQUIRE(g.getSize() == 3);
	REQUIRE(g.getRootVideoIDs() == std::vector<std::string> {"W91sqAs-_-g", "Tz_Ees_-kE4"});
	
}

TEST_CASE("Test Case 4", "[parse input]") {

    Graph g;
    std::string line = "W91sqAs-_-g	dusted21	776	Music	249	1556837	4.61	7314	3899	tZw-8RSyvh8	-L6tFCeR_ZQ	SgHk5JDCdx0	4U5dmIVBzq8	MwzSxbqyzcE	UFMx8fkpLNg	Jl2AaYYgIXo	XJaHmGD8UEk	gL3EjCPu-Q4	abGQ_ehWm2Y	_oPYs-LNYGo	GzqvzhpLfIg	f2uBfi4miC8	8Eaj9OZ--K0	mj7mYbHEasI	gJ0I92_1Vt8	n58uchRpgO0	jDVPJ_7dS3k	KizKliQvF_M	w8dpP4uQglk";
    Parser::readLine(g, line, false);
    line = "JVXcPrnwzHA	GetMoneyTV	776	Music	60	73467	4.28	72	61	JVXcPrnwzHA	mMZOChNioD4	BBNu1AErWAw	Ea8M0WtU7vs	REuYnkUjaJU	T0RshhRW4fE	DzYaIq9FDRc	Swa4FRX6rHE	fvPC1ABp4VE";
    Parser::readLine(g, line, false);
    line = "JVXcPrnwzHA	GetMoneyTV	776	Music	60	73467	4.28	72";
    Parser::readLine(g, line, false);
	// Note that this test is just for eyeballing output
	
}

TEST_CASE("Test Case 5", "[parse files]") {
	Graph g;
	Parser::readData(g, "test", "io-data/");
	REQUIRE(g.getRootVideoIDs() == std::vector<std::string> {"W91sqAs-_-g", "oqcaJ4NrUKA", "XSGc5Vkh_1g", "zPvmwuLaXhE", "rx6zsub-neU"});
    REQUIRE(g.getSize() == 60);
	std::vector<std::string> roots = g.getRootVideoIDs();
	for (int i = 0; i < roots.size(); i++) {
		std::cout << roots.at(i) << ", ";
	}
	std::cout << g.getSize();
}

TEST_CASE("Test Case 6", "[parse files][traversals]") {
	Graph g;
	Parser::readData(g, "test", "io-data/");
	REQUIRE(g.getRootVideoIDs() == std::vector<std::string> {"W91sqAs-_-g", "oqcaJ4NrUKA", "XSGc5Vkh_1g", "zPvmwuLaXhE", "rx6zsub-neU"});
    REQUIRE(g.getSize() == 60);
	std::vector<std::string> roots = g.getRootVideoIDs();
	for (int i = 0; i < roots.size(); i++) {
		std::cout << roots.at(i) << ", ";
	}
	std::cout << g.getSize() << std::endl;

	/// TODO: formally test traversals

}



/// TODO: Begin graph checks with smaller amounts of data
/// Check that the traversals work as expected (they appear to)
/// Check that large graph isn't overly slow

// Finished checks
// Confirmed that graph destruction doesn't segfault
/// Confirmed that creating videos via vector works
/// Checked destruction