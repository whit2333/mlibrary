#ifndef  G4VOLUME_H
#define  G4VOLUME_H 1

// geant4
#include "G4PVPlacement.hh"
#include "G4VisManager.hh"
#include "G4VSolid.hh"
#include "G4LogicalVolume.hh"

// c++
#include <map>
using namespace std;

// mlibrary
#include "goptions.h"
#include "gfactory.h"
#include "gsystem.h"

#define g4setupLogHeader " ⌂ g4setup ▸"

class G4Volume
{

public:
	G4Volume(G4VSolid* s = nullptr, G4LogicalVolume* l = nullptr, G4VPhysicalVolume* p = nullptr) : solidVolume(s), logicalVolume(l), physicalVolume(p) { ; }

public:
	G4VSolid*          getSolid()    const { if(solidVolume)    return solidVolume;    else return nullptr;}
	G4LogicalVolume*   getLogical()  const { if(logicalVolume)  return logicalVolume;  else return nullptr;}
	G4VPhysicalVolume* getPhysical() const { if(physicalVolume) return physicalVolume; else return nullptr;}

	void addSolid(G4VSolid* s, int verbosity=0);
	void addLogical(G4LogicalVolume* l, int verbosity=0);
	void addPhysical(G4VPhysicalVolume* p, int verbosity=0);

private:
	G4VSolid*             solidVolume;   ///< Solid
	G4LogicalVolume*    logicalVolume;   ///< Logical Volume
	G4VPhysicalVolume* physicalVolume;   ///< Physical Volume
};


class G4Setup
{

public:
	G4Setup(GSetup* gsetup, GOptions* gopt) {
		g4setup = new map<string, G4Volume*>;
		buildSetup(gsetup, gopt);
	}

	G4VSolid*          getSolid(string vname) const;
	G4LogicalVolume*   getLogical(string vname) const;
	G4VPhysicalVolume* getPhysical(string vname) const;

private:

	// the key has the form system/volumename
	map<string, G4Volume*> *g4setup;
	void buildSetup(GSetup* gsetup, GOptions* gopt);
	G4Volume* getG4Volume(string name) const;

	// manager to register the factories
	GManager g4SystemManager;
	void registerFactoriesAndBuildG4Volumes(GSetup* gsetup, GOptions* gopt);
	void buildWorld(GOptions* gopt);

public:
	void addG4Volume(G4Volume *g4v, string name);

	// G4Setup options - defined in utilities.cc
	static map<string, GOption> defineOptions();

};

#endif
