#ifndef  DETECTORELEMENT_H
#define  DETECTORELEMENT_H


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

	// solid parameters
	string                 type;   ///< solid type. This follows the GEANT4 definitions
	vector<double>   dimensions;   ///< vector of dimensions. Size depends on solid type

	// solid visualization style
	bool                visible;   ///< visibility of the detector: 0=invisible 1=visible
	int                   style;   ///< Visual style: 0=wireframe 1=solid
	string                color;   ///< 6(7) digits colors in RRGGBB format. Last optional digit is transparency

	// logical attributes
	string             material;   ///< Volume Material name.
	string             magfield;   ///< Magnetic Field. The string "no" means that the field is inherited from the mother volume.

	// physical attributes
	G4ThreeVector           pos;   ///< Position relative to the mother volume, as G4ThreeVector
	G4RotationMatrix        rot;   ///< Rotation Matrix, defined by rotations along x,y,z axis relative to the mother volume

	int                   exist;   ///< detector ON/OFF switch

	string sensitivity;   ///< Assigns digitization type by name

	// special cases
	string   copyOf;
	string   replicaOf;
	int      ncopy;             ///< copy number, in case of copies and replicas
	string   solidOperation;

	// mirrors
	string   mirrorType;
	string   mirrorMaterial;


private:
	G4VSolid*             solidVolume;   ///< G4 Solid
	G4LogicalVolume*    logicalVolume;   ///< Logical Volume
	G4VPhysicalVolume* physicalVolume;   ///< Physical Volume
	G4Material*            g4material;

	// Phases statuses: 0: not build. 1: built. 2: waiting to build. -1: error: could not build
	int solidBuilt, logicalBuilt, physicalBuilt;

	// defined in utilities
	vector< vector<string> > dimensionsType();  // check dimensions size to geant4 constructors
	void checkG4SolidDimensions();

public:
	G4VSolid*             getSolidVolume() {return solidVolume;}
	G4LogicalVolume*    getLogicalVolume() {return logicalVolume;}
	G4VPhysicalVolume* getPhysicalVolume() {return physicalVolume;}
	G4Material*            getG4material() {return g4material;}

	// sets solidBuilt
	// builds and assigns a G4VSolid to solidVolume
	// need the detectorMap in case this is a boolean operation
	void buildSolid(map<string, DetectorElement*> *detectorsMap);


	// defined in utilities
	friend ostream &operator<<(ostream &stream, DetectorElement); ///< Overloaded "<<" for DetectorElement class. Dumps infos on screen.
	bool operator== (const DetectorElement& D) const;             ///< Overloaded "==" operator for DetectorElement class

};



#endif
