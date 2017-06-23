// g4volume
#include "g4NativeSetupFactory.h"

// geant4
#include "G4NistManager.hh"
#include "G4Material.hh"

// mlibrary
#include "gstring.h"
using namespace gstring;

bool G4NativeSetupFactory::buildLogical(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s)
{
	// check dependencies first
	if(!checkLogicalDependencies(s, g4s)) return false;

	// dependencies are there, can build volume
	string vname   = s->getName();
	string matName = s->getMaterial();
	string dmat    = gopt->getString("defaultMat");
	bool gui       = gopt->getBool("gui");

	// if the g4volume doesn't exist, create one and add it to the map
	G4Volume *thisG4Volume = nullptr;

	// check if g4s already exists
	// it could not exist if this is a copy
	if(g4s->find(vname) != g4s->end()) {
		thisG4Volume = (*g4s)[vname];
		// if the solid is already built, nothing to do
		if(thisG4Volume->getLogical() != nullptr) return true;

		// if the solid does not exist, can't build the logical
		if(thisG4Volume->getSolid() == nullptr) return false;
	} else {
		thisG4Volume = new G4Volume();
	}

	G4NistManager* NISTman = G4NistManager::Instance();

	// looking for material
	G4Material* thisMaterial = NISTman->FindOrBuildMaterial(matName);
	// if not found, use the material specified in the options
	if(thisMaterial == nullptr) {
		cout << " ! Warning: material " << matName << " not found for volume " << vname << ". Using " << dmat << " instead." << endl;
		thisMaterial = NISTman->FindOrBuildMaterial(dmat);
		if(thisMaterial == nullptr) {
			// you set an option incorrectly, error!
			cout << " !!! Error: options default material " << dmat << " not found. Exiting." << endl;
			exit(99);
		}
	}

	// material found, can build the logical volume
	if(gui) {
		// vis attributes
	}



	return false;
}








