#include "gfield.h"

// geant4 steppers
#include "G4CashKarpRKF45.hh"
#include "G4ClassicalRK4.hh"
#include "G4SimpleHeum.hh"
#include "G4SimpleRunge.hh"
#include "G4ImplicitEuler.hh"
#include "G4ExplicitEuler.hh"
#include "G4HelixImplicitEuler.hh"
#include "G4HelixExplicitEuler.hh"
#include "G4HelixSimpleRunge.hh"
#include "G4NystromRK4.hh"
#include "G4DormandPrinceRK56.hh"




G4Mag_UsualEqRhs* GField::createFieldEquation(G4MagneticField* gfield)
{
	return new G4Mag_UsualEqRhs(this);
}


G4MagIntegratorStepper* GField::createFieldStepper(string integrationMethod, G4Mag_UsualEqRhs* fEquation)
{
	
	
	if (integrationMethod == "G4CashKarpRKF45")	      return new G4CashKarpRKF45(fEquation);
	if (integrationMethod == "G4ClassicalRK4")	      return new G4ClassicalRK4(fEquation);
	if (integrationMethod == "G4SimpleHeum")		  		return new G4SimpleHeum(fEquation);
	if (integrationMethod == "G4SimpleRunge")	      	return new G4SimpleRunge(fEquation);
	if (integrationMethod == "G4ImplicitEuler")	      return new G4ImplicitEuler(fEquation);
	if (integrationMethod == "G4ExplicitEuler")	      return new G4ExplicitEuler(fEquation);
	if (integrationMethod == "G4HelixImplicitEuler")   return new G4HelixImplicitEuler(fEquation);
	if (integrationMethod == "G4HelixExplicitEuler")   return new G4HelixExplicitEuler(fEquation);
	if (integrationMethod == "G4HelixSimpleRunge")	   return new G4HelixSimpleRunge(fEquation);
	if (integrationMethod == "G4NystromRK4")	         return new G4NystromRK4(fEquation);
	
	// verify default: the default stepper for magnetic fields in G4ChordFinder, when a driver/stepper is not specified.
	return new G4DormandPrinceRK56(fEquation);
}


//G4ChordFinder*  GField::createChordFinder(G4MagneticField gfield, double minStep, G4MagIntegratorStepper* fieldStepper)
//{
//
//}
//
