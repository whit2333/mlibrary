/// \file example.cc

// example on how to use the g4displa library

// g4displa
#include "g4display.h"



//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	GOptions *gopts = new GOptions(argc, argv, G4Display::defineOptions(), 1);

	G4Display *g4Display = new G4Display(gopts);

	delete g4Display;
	return 1;
}

