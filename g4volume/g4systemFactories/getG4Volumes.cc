#include "g4SetupFactory.h"



G4VSolid*          G4SetupFactory::getSolidFromMap(   string vname, map<string, G4Volume*> *g4s) const
{

	return nullptr;
}

G4LogicalVolume*   G4SetupFactory::getLogicalFromMap( string vname, map<string, G4Volume*> *g4s) const
{

	return nullptr;
}

G4VPhysicalVolume* G4SetupFactory::getPhysicalFromMap(string vname, map<string, G4Volume*> *g4s) const
{

	return nullptr;
}
