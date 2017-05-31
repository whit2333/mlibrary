// gvolume
#include "systemTextFactory.h"


// c++
#include <iostream>
#include <fstream>
using namespace std;


void GSystemTextFactory::loadGeometry(GOptions* gopt, GSystem *s) {
	if(verbosity > 1) {
		cout << setupLogHeader << " Loading <text> geometry for " <<  s->getName() << endl;
	}

	vector<string> possibleLocations = gopt->getStringVectorValue("setupDir");
	ifstream IN = s->gSystemFile(1, possibleLocations, verbosity);
	
}

