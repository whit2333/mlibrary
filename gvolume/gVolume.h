#ifndef  GVOLUME_H
#define  GVOLUME_H

// c++
#include <string>
#include <array>
#include <vector>
using namespace std;

//// options
//#include "goptions.h"

class GVolume
{
public:
	GVolume();

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
	string                  pos;   ///< Position relative to the mother volume
	string                  rot;   ///< Rotation Matrix, defined by rotations along x,y,z axis relative to the mother volume

	string          sensitivity;   ///< Assigns digitization type and collection ID

	// special cases
	string               copyOf;   ///< name of gvolume to copy from
	string            replicaOf;   ///< name of gvolume to replica from
	int                   ncopy;   ///< copy number, in case of copies and replicas
	string       solidOperation;

	// mirrors
	string   mirrorType;
	string   mirrorMaterial;

	// defined in utilities
//	friend ostream &operator<<(ostream &stream, GVolume); ///< Overloaded "<<" for DetectorElement class. Dumps infos on screen.

public:
	// GVolume options
//	static map<string, GOption> defineOptions();

};


// the class GTable is the interface to the detector
class GTable {
public:
	GTable();
	
private:
	array<string, 20> validKeys = {"name"   , "mother", "description", "factory" , "type"    , "dimensions",
		                           "visible", "style" , "color"      , "material", "magfield", "pos"       ,
									"rot", "sensitivity", "copyOf", "replicaOf", "ncopy", "solidOperation", "mirrorType", "mirrorMaterial"};
	
};

#endif
