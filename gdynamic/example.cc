/// \file example.cc

// example on how to use the gdynamic library

// gdynamic
#include "gdynamic.h"

// c++
#include <iostream>
using namespace std;


//! example of main declaring GOptions
int main(int argc, char* argv[])
{

	GManager manager(1);

	// DL is the name of the
	manager.registerDL("ctofRoutinesExample");

	map<string, GDynamic*> dynamicRoutines;
	dynamicRoutines["ctof"] = manager.LoadObjectFromLibrary<GDynamic>("ctofRoutinesExample");

	dynamicRoutines["ctof"]->loadConstants(1, "original");

	return 1;
}

