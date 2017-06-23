#include "g4SetupFactory.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

bool G4SetupFactory::checkSolidDependencies(GVolume *s, map<string, G4Volume*> *g4s)
{
	// checking if it's a copy, replica or solid operation
	// they are mutually exclusve
	string copyOf    = s->getCopyOf();
	string replicaOf = s->getReplicaOf();
	string solidsOpr = s->getSolidsOpr();

	// copy
	if(copyOf != "na") {
		vector<string> copies = getStringVectorFromString(copyOf);
		if(copies.size() == 2) {
			if(copies[0] == "copyOf:") {
				// checking if the copy solid exists
				if(getSolidFromMap(copies[1], g4s) != nullptr) return true;
			} else return false;

		} else return false;

		// replica
	} else if(replicaOf != "na") {

		// solid operation
	} else if(solidsOpr != "na") {
		vector<string> solidOperations = getStringVectorFromString(solidsOpr);
		if(solidOperations.size() == 3) {
			if(solidOperations[1] == "+" || solidOperations[1] == "-" || solidOperations[1] == "*") {
				// checking if the copy solid exists
				if(getSolidFromMap(solidOperations[0], g4s) != nullptr && getSolidFromMap(solidOperations[2], g4s) != nullptr) return true;
			} else return false;

		} else return false;

	}

	return true;
}

bool G4SetupFactory::checkLogicalDependencies(GVolume *s, map<string, G4Volume*> *g4s)
{
	// checking if mother logical volume exists


	return true;
}

