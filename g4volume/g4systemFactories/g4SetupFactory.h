#ifndef G4SETUPFACTORY_H
#define G4SETUPFACTORY_H 1

// mlibrary
#include "goptions.h"

// g4volume
#include "g4volume.h"


// G4SetupFactory factory
class G4SetupFactory
{
public:
	// returns true if the system could be built
	// returns false if dependencies are not met
	virtual bool loadG4Setup(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s) = 0;
	virtual ~G4SetupFactory() = default;

protected:
	G4VSolid*          getSolidFromMap(   string vname, map<string, G4Volume*> *g4s) const;
	G4LogicalVolume*   getLogicalFromMap( string vname, map<string, G4Volume*> *g4s) const;
	G4VPhysicalVolume* getPhysicalFromMap(string vname, map<string, G4Volume*> *g4s) const;

	bool checkSolidDependencies(   bool verbosity, GVolume *s, map<string, G4Volume*> *g4s);
	bool checkLogicalDependencies( bool verbosity, GVolume *s, map<string, G4Volume*> *g4s);
	bool checkPhysicalDependencies(bool verbosity, GVolume *s, map<string, G4Volume*> *g4s);

	G4RotationMatrix *getRotation(GVolume *s);
	G4ThreeVector     getPosition(GVolume *s);
};

#endif
