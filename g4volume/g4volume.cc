// g4volume
#include "g4volume.h"

// c++
#include <iostream>
using namespace std;

// mlibrary
#include "gstring.h"
using namespace gstring;


void G4Setup::addG4Volume(G4Volume *g4v, string name) {

	// first check that the name does not already exist
	if(g4setup->find(name) != g4setup->end()) {
		(*g4setup)[name] = g4v;
	} else {
		G4cout << " !! Warning: volume " << name << " already exists." << endl;
	}
}

void G4Setup::buildSetup(GSetup* gsetup, GOptions* gopt)
{
	int verbosity = gopt->getInt("g4volumev");
	buildWorld(gopt);

	// now loading gmanager
	g4SystemManager = GManager(verbosity - 1, g4setupLogHeader);

	// register the factories needed and build the geant4 volumes
	registerFactoriesAndBuildG4Volumes(gsetup, gopt);
}

G4Volume* G4Setup::getG4Volume(string name) const
{
	if(g4setup->find(name) != g4setup->end()) {
		return (*g4setup)[name];
	} else {
		G4cout << " !! Warning: volume " << name << " does not exist in g4setup." << endl;
	}
	return nullptr;
}

G4VSolid* G4Setup::getSolid(string vname) const
{
	G4Volume* thisVolume = getG4Volume(vname);
	if(thisVolume) {
		return thisVolume->getSolid();
	}
	return nullptr;
}

G4LogicalVolume* G4Setup::getLogical(string vname) const
{
	G4Volume* thisVolume = getG4Volume(vname);
	if(thisVolume) {
		return thisVolume->getLogical();
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




void G4Volume::addSolid(G4VSolid* s, int verbosity)
{
	solidVolume = s;

	if(verbosity>2) {
		cout << g4setupLogHeader << " Geant4 Solid " << s->GetName() << " created." << endl;
	}

}
void G4Volume::addLogical(G4LogicalVolume* l, int verbosity)
{
	logicalVolume = l;
}
void G4Volume::addPhysical(G4VPhysicalVolume* p, int verbosity)
{
	physicalVolume = p;
}





