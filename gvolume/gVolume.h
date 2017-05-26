#ifndef  GVOLUME_H
#define  GVOLUME_H 1

// c++
#include <string>
#include <array>
#include <vector>
#include <map>
using namespace std;

//// options
//#include "goptions.h"

extern array<string, 20> gTableValidKeys;
extern array<string, 20> GVolumeNecessaryKeys;


// GTable is the interface to the detector
// This class is read by the different factories: CAD, GDML, TEXT and MYSQL
class GTable {
public:
	GTable();

private:
	map<string, string> gtable;

public:
	bool addData(string key, string data);
	string getData(string key);

private:
	bool isValidKey(string key);
	
};

class GVolume
{
public:
	GVolume(GTable gt);

private:
	string        name;   ///< Name of the volume.
	string      mother;   ///< Mother Volume name.
	string description;   ///< Volume Description, for documentation.
	string     factory;   ///< Provenience. It can be perl, pyton, cad or gdml

	// solid parameters
	string        type;   ///< solid type. This follows the GEANT4 definitions
	string  dimensions;   ///< vector of dimensions. Size depends on solid type

	// solid visualization style
	bool        visible;   ///< visibility of the detector: 0=invisible 1=visible
	int           style;   ///< Visual style: 0=wireframe 1=solid
	string        color;   ///< 6(7) digits colors in RRGGBB format. Last optional digit is transparency

	// logical attributes
	string     material;   ///< Volume Material name.
	string     magfield;   ///< Magnetic Field. The string "no" means that the field is inherited from the mother volume.

	// physical attributes
	string          pos;   ///< Position relative to the mother volume
	string          rot;   ///< Rotation Matrix, defined by rotations along x,y,z axis relative to the mother volume

	string  sensitivity;   ///< Assigns digitization type and collection ID

	// special cases
	string       copyOf;   ///< name of gvolume to copy from
	string    replicaOf;   ///< name of gvolume to replica from
	int           ncopy;   ///< copy number, in case of copies and replicas
	string    solidsOpr;   ///< solids operation

	// mirrors
	string   mirrorType;
	string    mirrorMat;

	// defined in utilities
	friend ostream &operator<<(ostream &stream, GVolume); ///< Logs infos on screen.

public:
	// GVolume options
//	static map<string, GOption> defineOptions();

private:
	void initGVolumeMembers();
};


#endif
