#include "g4volume.h"

#include <iostream>
using namespace std;

void g4Setup::
(g4Volume g4v, string name) {


	// first check that the name does not already exist
	if(namesMap.find(name) != namesMap.end()) {
		unsigned newIndex = setup.size();
		setup[]
	} else {

		cout << " !! Warning: volume " << name << " already exists." << endl;
	}
}
