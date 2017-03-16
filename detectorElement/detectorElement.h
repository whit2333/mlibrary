#ifndef  DETECTORELEMENT_H
#define  DETECTORELEMENT_H

// c++
#include <string>
using namespace std;

// geant4
#include "G4PVPlacement.hh"
#include "G4VisManager.hh"

// CLHEP units
#include "CLHEP/Units/PhysicalConstants.h"
using namespace CLHEP;

// options
#include "goptions.h"

class DetectorElement
{
public:
	DetectorElement();

private:
	string                 name;   ///< Name of the volume. Since this is the key of the STL map, it has to be unique.
	string               mother;   ///< Mother Volume name.
	string          description;   ///< Volume Description, for documentation.
	string              factory;   ///< Provenience. It can be perl, pyton, cad or gdml

	int                 visible;   ///< visibility of the detector: 0=invisible 1=visible
	int                   style;   ///< Visual style: 0=wireframe 1=solid
	string                color;   ///< 6(7) digits colors in RRGGBB format. Last optional digit is transparency

	// solid attributes
	string                 type;   ///< solid type. This follows the GEANT4 definitions
	vector<double>   dimensions;   ///< vector of dimensions. Size depends on solid type

	// logical attributes
	string             material;   ///< Volume Material name.
	string             magfield;   ///< Magnetic Field. The string "no" means that the field is inherited from the mother volume.

	// physical attributes
	G4ThreeVector           pos;   ///< Position relative to the mother volume, as G4ThreeVector
	G4RotationMatrix        rot;   ///< Rotation Matrix, defined by rotations along x,y,z axis relative to the mother volume
	bool                  pMany;   ///< Needed by geant4 at G4PVPlacement time


	int                   exist;   ///< detector ON/OFF switch

	string sensitivity;   ///< Assigns digitization type by name

	// special cases
	string   copyOf;
	string   replicaOf;
	string   solidOperation;
	int      ncopy;             ///< copy number, in case of copies and replicas


private:
	G4VSolid*             solidVolume;   ///< G4 Solid
	G4LogicalVolume*    logicalVolume;   ///< Logical Volume
	G4VPhysicalVolume* physicalVolume;   ///< Physical Volume
	G4Material*            g4material;

	// defined in utilities
	vector< vector<string> > dimensionsType();

public:
	int buildSolid(int verbosity, string catchName, map<string, DetectorElement*> *detectorsMap); // builds and assigns a G4VSolid to solidVolume



	// defined in utilities
	friend ostream &operator<<(ostream &stream, DetectorElement); ///< Overloaded "<<" for DetectorElement class. Dumps infos on screen.
	bool operator== (const DetectorElement& D) const;             ///< Overloaded "==" operator for DetectorElement class

};



#endif
