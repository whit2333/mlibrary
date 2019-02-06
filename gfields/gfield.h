#ifndef  GFIELD_H
#define  GFIELD_H  1

// G4 headers
#include "G4MagneticField.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4ChordFinder.hh"

// gfields
#include "gMap.h"

// c++
#include <set>
using namespace std;

// one gfield / geant4 volume.
// it has one field manager (this what attaches to the volume)
// it can have several maps, uniform and multiple fields
// it has two parts:
// 1. define the how tracking is done (field manager)
// 2. define the fields. All fields present in the volume are super-imposed

class GField : public G4MagneticField
{
	// public api from G4MagneticField
	// returns the field at point x. This is a dispatcher for the various symmetries below
	void GetFieldValue(const double x[3], double *Bfield) const;


private:
	// field manager take care of:
	// - field equation
	// - stepper
	// - chord finder
	G4Mag_UsualEqRhs*       createFieldEquation(G4MagneticField* gfield);
	G4MagIntegratorStepper* createFieldStepper(string integrationMethod, G4Mag_UsualEqRhs* fEquation);
	G4ChordFinder*          createChordFinder(G4MagneticField* gfield, double minStep, G4MagIntegratorStepper* fieldStepper);

	
	// all the real fields
private:
	
	set<GMap> maps;
	
	
	
};


#endif

