// g4volume
#include "g4volume.h"

// c++
#include <iostream>
using namespace std;


void G4Setup::createG4Volume(G4Volume g4v, string name) {

	// first check that the name does not already exist
	if(setup.find(name) != setup.end()) {
		setup[name] = g4v;
	} else {
		cout << " !! Warning: volume " << name << " already exists." << endl;
	}
}

G4Setup::G4Setup(GSetup gsetup)
{

}
