// g4volume
#include "g4volume.h"

// c++
#include <iostream>
using namespace std;

// mlibrary
#include "gstring.h"
using namespace gstring;

// geant4
#include "G4Box.hh"
#include "G4NistManager.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"

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
	G4NistManager* NISTman = G4NistManager::Instance();
	G4Material* air  = NISTman->FindOrBuildMaterial("G4_AIR");

	// for now the hall is a box
	G4ThreeVector worldSize = vectorFromStringVector(gopt->getStringVectorValue("hall"));

	G4Box * solidWorld = new G4Box("world", worldSize.x(), worldSize.y(), worldSize.z());
	G4LogicalVolume * logicWorld = new G4LogicalVolume(solidWorld, air, "World", 0, 0, 0);

	G4VPhysicalVolume * physiWorld
	= new G4PVPlacement(0,               // no rotation
						G4ThreeVector(), // at (0,0,0)
						logicWorld,      // its logical volume
						"World",         // its name
						0,               // its mother  volume
						false,           // no boolean operations
						0);              // copy number

	
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
