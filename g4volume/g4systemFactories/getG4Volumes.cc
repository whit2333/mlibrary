#include "g4SetupFactory.h"

G4VSolid* G4SetupFactory::getSolidFromMap(string vname, map<string, G4Volume*> *g4s) const
{

	if(g4s->find(vname) != g4s->end()) {
		auto thisGVolume = (*g4s)[vname];
		return thisGVolume->getSolid();
	}

	return nullptr;
}

G4LogicalVolume* G4SetupFactory::getLogicalFromMap(string vname, map<string, G4Volume*> *g4s) const
{

	if(g4s->find(vname) != g4s->end()) {
		auto thisGVolume = (*g4s)[vname];
		return thisGVolume->getLogical();

	}

	return nullptr;
}

G4VPhysicalVolume* G4SetupFactory::getPhysicalFromMap(string vname, map<string, G4Volume*> *g4s) const
{

	if(g4s->find(vname) != g4s->end()) {
		auto thisGVolume = (*g4s)[vname];
		return thisGVolume->getPhysical();

	}

	return nullptr;
}

G4RotationMatrix* G4SetupFactory::getRotation(GVolume *s)
{

	return nullptr;
}

G4ThreeVector G4SetupFactory::getPosition(GVolume *s)
{

	return G4ThreeVector(0,0,0);
}
