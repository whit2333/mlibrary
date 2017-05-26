/// \file example.cc

// example on how to use load a setup

// options
#include "gSystem.h"

// c++
#include <iostream>
using namespace std;

// options
#include "goptions.h"


//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	GOptions *gopts = new GOptions(argc, argv, GSetup::defineOptions(), 1);

	GSetup *setup = new GSetup(gopts);

	if(gopts) delete gopts;
	delete setup;
	return 1;
}

