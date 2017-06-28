// g4volume
#include "g4SetupFactory.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

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
	G4RotationMatrix rot(G4ThreeVector(1, 0, 0),
						 G4ThreeVector(0, 1, 0),
						 G4ThreeVector(0, 0, 1));





	return rot;
}

G4ThreeVector G4SetupFactory::getPosition(GVolume *s)
{
	G4ThreeVector pos(0,0,0);

	vector<double> posVector = getG4NumbersFromString(s->getPos());
	if(posVector.size() == 3) {
		pos.setX(posVector[0]);
		pos.setY(posVector[1]);
		pos.setZ(posVector[2]);
	}

	if(s->getShift() != "na") {
		vector<double> shiftVector = getG4NumbersFromString(s->getPos());
		if(shiftVector.size() == 3) {
			G4ThreeVector shift(shiftVector[0], shiftVector[1], shiftVector[2]);
			pos = pos + shift;
		}
	}

	return pos;
}
