#include "g4SetupFactory.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

bool G4SetupFactory::checkSolidDependencies(bool verbosity, GVolume *s, map<string, G4Volume*> *g4s)
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
			// first string must be copyOf
			if(copies[0] == "copyOf:") {
				// checking if the copy solid exists
				if(verbosity) cout << " " << s->getName() << " is a copy of " << copies[1] ;
				if(getSolidFromMap(copies[1], g4s) != nullptr) {
					if(verbosity) cout << " which already exists" << endl; ;
					return true;
				} else {
					if(verbosity) cout << " which does not exist yet." << endl; ;
					return false;
				}
			} else {
				if(verbosity) cout << " Did you intend to make a copy? The first string must be: \"copyOf:\" but you have " << copies[0] << endl ;
				return false;
			}
		} else {
			if(verbosity) cout << " Did you intend to make a copy? The syntax is \"copyOf:\" volumeName, but you have " << copyOf << endl; ;
			return false;
		}
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

bool G4SetupFactory::checkLogicalDependencies(bool verbosity, GVolume *s, map<string, G4Volume*> *g4s)
{
	// maybe check material here?

	return true;
}

bool G4SetupFactory::checkPhysicalDependencies(bool verbosity, GVolume *s, map<string, G4Volume*> *g4s)
{
	string vname      = s->getName();
	string motherName = s->getMother();

	// the gvolume must exist
	if(g4s->find(vname) == g4s->end()) {

		if(verbosity) cout << "  - g4setup dependencies: " << vname << " not found in gvolume map yet." << endl ;

		return false;
	}

	// checking if its and mother logical volume exists
	if(getLogicalFromMap(vname, g4s)   == nullptr) {
		if(verbosity) cout << "  <" << vname << ">  - g4setup logical volume not found yet." << endl ;
		return false;
	}
	if(getLogicalFromMap(motherName, g4s) == nullptr) {
		if(verbosity) cout << "  - g4setup dependencies: <" << vname << "> mother <" << motherName << "> logical volume not found yet." << endl ;
		return false;
	}

	if(verbosity) cout << " - g4setup dependencies: <" << vname << "> and mother <" << motherName << "> logical volumes are found. Ready to build Physical volume." << endl ;

	return true;
}

