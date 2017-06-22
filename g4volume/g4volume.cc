// g4volume
#include "g4volume.h"

// c++
#include <iostream>
using namespace std;

// mlibrary
#include "gstring.h"
using namespace gstring;


void G4Setup::createG4Volume(G4Volume *g4v, string name) {

	// first check that the name does not already exist
	if(g4setup->find(name) != g4setup->end()) {
		(*g4setup)[name] = g4v;
	} else {
		cout << " !! Warning: volume " << name << " already exists." << endl;
	}
}

void G4Setup::buildSetup(GSetup* gsetup, GOptions* gopt)
{
	int verbosity = gopt->getInt("vsetup");
	buildWorld(gopt);

	// now loading gmanager
	g4SystemManager = GManager(verbosity, setupLogHeader);

	// register the factories needed and build the geant4 volumes
	registerFactoriesAndBuildG4Volumes(gsetup, gopt);
}

G4Volume* G4Setup::getG4Volume(string name) const
{
	if(g4setup->find(name) != g4setup->end()) {
		return (*g4setup)[name];
	} else {
		cout << " !! Warning: volume " << name << " does not exist in g4setup." << endl;
	}
	return nullptr;
}

G4VPhysicalVolume* G4Setup::getPhysical(string vname) const
{
	G4Volume* thisVolume = getG4Volume(vname);
	if(thisVolume) {
		return thisVolume->getPhysical();
	}
	return nullptr;
}
