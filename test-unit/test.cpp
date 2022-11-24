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
	REQUIRE(vid_vec.isNull() == false);
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
	"-1", "-1", "-1", "-1"}, std::vector<std::string>(), true);

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
	if (vid_vec.isNull()) {
		std::cout << "\nnull vector video\n";
	}

}

/// TODO: Begin graph checks with smaller amounts of data
/// TODO: Check that graph destruction doesn't segfault
/// Check that the traversals work as expected
/// Check that large graph isn't overly slow
/// Check what happens with returning null vids (make sure it works)
/// Check that creating videos via vector works