
#include "detectorElement.h"

DetectorElement::DetectorElement()
{
	// init geant4 pointers to null
	solidVolume    = NULL;
	logicalVolume  = NULL;
	physicalVolume = NULL;
	g4material     = NULL;
}


//int DetectorElement::buildSolid()
//{
//
//	
//	return 0;
//}
