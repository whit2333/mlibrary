/// \file example.cc

// example on how to use the gtouchable library

// gtouchable
#include "gtouchable.h"

// c++
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{


	// a touchable
	GTouchable ctof("ctof", "paddle 22");

	cout << " E multiplier: " << ctof.getEnergyMultiplier() << endl;

	return 1;
}

