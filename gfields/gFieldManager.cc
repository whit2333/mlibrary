#include "gfield.h"



G4Mag_UsualEqRhs* GField::createFieldEquation(G4MagneticField* gfield)
{
	return new G4Mag_UsualEqRhs(this);
}


//G4MagIntegratorStepper* GField::createFieldStepper(string integrationMethod, G4Mag_UsualEqRhs* fEquation)
//{
//
//}
//
//
//G4ChordFinder*  GField::createChordFinder(G4MagneticField gfield, double minStep, G4MagIntegratorStepper* fieldStepper)
//{
//
//}
//
