/// \file example.cc

// example on how to use the text progress bar library

// text progress bar
#include "gstring.h"
using namespace gstring;


// c++
#include <iostream>


//! example of main declaring GOptions
int main(int argc, char* argv[])
{

	if(argc != 2) {
		cout << " !! Error: run example with one argument" << endl;
	} else {

	string test = argv[1];


	vector<string> testResult = getStringVectorFromString(test);


	for(auto &s : testResult)
		cout << s << endl;

	}

	return 1;
}

