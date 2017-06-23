// g4volume
#include "g4NativeSetupFactory.h"

// geant4
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4LogicalVolume.hh"

// mlibrary
#include "gstring.h"
using namespace gstring;

bool G4NativeSetupFactory::buildLogical(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s)
{
	// if it's a component, do nothing
	string matName = s->getMaterial();
	if(matName == "component") return true;

	// dependencies are there, can build volume
	string vname   = s->getName();
	string dmat    = gopt->getString("defaultMat");
	bool gui       = gopt->getBool("gui");

	// if the g4volume doesn't exist, create one and add it to the map
	G4Volume *thisG4Volume = nullptr;

	// check if g4s already exists
	// it could not exist if this is a copy
	if(g4s->find(vname) != g4s->end()) {
		thisG4Volume = (*g4s)[vname];
		// if the logical is already built, nothing to do
		// this can happen if it's a copy
		if(thisG4Volume->getLogical() != nullptr) return true;

		// if the solid does not exist, can't build the logical
		// PRAGMA TODO:
		// catch exception here if solid is unknown to system
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

	// everything is set to build the logical volumes.
	// The constructor looks like:
	//	G4LogicalVolume(G4VSolid* pSolid,
	//					G4Material* pMaterial,
	//					const G4String& name,
	//					G4FieldManager* pFieldMgr=0,
	//					G4VSensitiveDetector* pSDetector=0,
	//					G4UserLimits* pULimits=0,
	//					G4bool optimise=true);
	// Constructor. The solid and material pointer must be non null.
	// The parameters for field, detector and user limits are optional.
	// The volume also enters itself into the logical volume Store.
	// Optimisation of the geometry (voxelisation) for the volume
	// hierarchy is applied by default. For parameterised volumes in
	// the hierarchy, optimisation is -always- applied.

	thisG4Volume->addLogical(new G4LogicalVolume(thisG4Volume->getSolid(), thisMaterial, vname));

	// material found, can build the logical volume
	if(gui) {
		// vis attributes
	}



	return false;
}








