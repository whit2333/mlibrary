// detectorElement
#include "detectorElement.h"

// geant4
#include "G4VSolid.hh"

DetectorElement::DetectorElement()
{
	// init geant4 pointers to null
	solidVolume    = NULL;
	logicalVolume  = NULL;
	physicalVolume = NULL;
	g4material     = NULL;
}

