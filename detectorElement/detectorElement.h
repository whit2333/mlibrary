#ifndef  DETECTORELEMENT_H
#define  DETECTORELEMENT_H

// c++
#include <string>
using namespace std;

// geant4
#include "G4PVPlacement.hh"
#include "G4VisManager.hh"

class DetectorElement
{

private:
	string                 name;   ///< Name of the volume. Since this is the key of the STL map, it has to be unique.
	string               mother;   ///< Mother Volume name.
	string          description;   ///< Volume Description for documentation.

	G4ThreeVector           pos;   ///< Position relative to the mother volume, as G4ThreeVector
	G4RotationMatrix        rot;   ///< Rotation Matrix, defined by rotations along x,y,z axis relative to the mother volume

	G4VisAttributes       VAtts;   ///< Visual Attributes: color, transparency, style (wireframe, solid), visibility

	string                 type;   ///< solid type. This follows the GEANT4 definitions
	vector<double>   dimensions;   ///< vector of dimensions. Size depends on solid type

	string             material;   ///< Volume Material name.
	string             magfield;   ///< Magnetic Field. The string "no" means that the field is inherited from the mother volume.

	int                   ncopy;   ///< copy number
	bool                  pMany;   ///< Needed by geant4 at G4PVPlacement time

	int                   exist;   ///< detector ON/OFF switch
	int                 visible;   ///< visibility of the detector: 0=invisible 1=visible
	int                   style;   ///< Visual style: 0=wireframe 1=solid

	string          sensitivity;   ///< Defines the Sensitive Detector. possible choices: "no" "hits collection name"

};



#endif
