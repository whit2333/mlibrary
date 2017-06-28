#ifndef  GVOLUME_H
#define  GVOLUME_H 1

// c++
#include <string>
#include <array>
#include <vector>
#include <map>
using namespace std;

#define gVolumeNumberOfParameters 19
extern array<string, gVolumeNumberOfParameters> gVolumeValidKeys;

class GVolume
{
public:
	GVolume(vector<string> pars);

private:
	string        name;   ///< Name of the volume.
	string      mother;   ///< Mother Volume name.
	string description;   ///< Volume Description, for documentation.

	// solid parameters
	string        type;   ///< solid type. This follows the GEANT4 definitions
	string  parameters;   ///< vector of parameters used in the geant4 solid constructor

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
	string        shift;   ///< Position modifier
	string         tilt;   ///< Rotation modifier
	bool          exist;  ///< Existance modifier

	string  sensitivity;   ///< Assigns digitization type and collection ID
	string  touchableID;   ///< Assigns identifier to single volume

	// special cases
	string       copyOf;   ///< name of gvolume to copy from
	string    replicaOf;   ///< name of gvolume to replica from
	string    solidsOpr;   ///< solids operation
	// PRAGMA: is this used in g4?
	int         pCopyNo;   ///< copy number, in case of copies and replicas

	// mirrors
	string       mirror;

	// defined in utilities
	friend ostream &operator<<(ostream &stream, GVolume); ///< Logs infos on screen.

public:
	string getName()       {return name;}
	string getMother()     {return mother;}
	string getType()       {return type;}
	string getParameters() {return parameters;}
	string getMaterial()   {return material;}
	int    getPCopyNo()    {return pCopyNo;}

	// special cases
	string getCopyOf()     {return copyOf;}
	string getReplicaOf()  {return replicaOf;}
	string getSolidsOpr()  {return solidsOpr;}

	// assign modifier
	void modifyPos(string s)     {shift = s;}
	void modifyRot(string t)     {tilt  = t;}
	void modifyExistence(bool e) {exist = e;}
};


#endif
