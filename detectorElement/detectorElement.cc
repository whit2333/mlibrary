// detectorElement
#include "detectorElement.h"

// geant4
#include "G4VSolid.hh"

DetectorElement::DetectorElement()
{
	// init geant4 pointers to null
	solidVolume    = nullptr;
	logicalVolume  = nullptr;
	physicalVolume = nullptr;
	g4material     = nullptr;
}

