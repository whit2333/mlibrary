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

	GManager manager(1);  // loads DLL that instantiate derived factories - we only know of the base one in this case "Car"

	manager.registerDL("ctofRoutines");

//	map<string, GDynamic*> dynamicRoutines;
//	dynamicRoutines["ctof"] = manager.LoadObjectFromLibrary<GDynamic>("ctofRoutines");
//
//
//	dynamicRoutines["ctof"]->loadConstants();
	

	return 1;
}

