// g4volume
#include "nativeVolumeFactory.h"

// geant4
#include "G4NistManager.hh"
#include "G4Material.hh"

bool G4NativeSystemFactory::buildLogical(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s)
{
	string vname = s->getName();
	string matName = s->getMaterial();
	string dmat = gopt->getString("defaultMat");

	// if the g4volume doesn't exist, create one and add it to the map
	G4Volume *thisG4Volume = nullptr;

	// check if g4s already exists
	// it could not exist if this is a copy
	if(g4s->find(vname) != g4s->end()) {
		thisG4Volume = (*g4s)[vname];
		// if the solid is already built, nothing to do
		if(thisG4Volume->getLogical() != nullptr) return true;
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


	

	return false;
}
