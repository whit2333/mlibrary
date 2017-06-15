#ifndef  G4VOLUME_H
#define  G4VOLUME_H

// geant4
#include "G4PVPlacement.hh"
#include "G4VisManager.hh"

// c++
#include <map>
using namespace std;

class g4Volume {

public:
	G4VSolid* getSolid() const { return solidVolume;}
	
private:
	G4VSolid*             solidVolume;   ///< G4 Solid
	G4LogicalVolume*    logicalVolume;   ///< Logical Volume
	G4VPhysicalVolume* physicalVolume;   ///< Physical Volume

};


class g4Setup {

public:
	void createG4Volume(g4Volume g4v, string name);

private:

	// the key has the form system/volumename
	map<string, g4Volume> setup;


	
};

#endif
