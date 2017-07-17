/// \file example.cc

// example on how to use the gtouchable library

// gtouchable
#include "gtouchable.h"

// c++
#include <iostream>
using namespace std;


//! example of main declaring GOptions
int main(int argc, char* argv[])
{

	int nevents = 100000000;

	gtouchable bar(20, "  index progress: ", 1, nevents);

	for(int i=1; i<nevents; i++) {
		bar.setProgress(i);

	}

	return 1;
}

