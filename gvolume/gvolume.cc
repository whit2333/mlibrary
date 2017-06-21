// gVolume
#include "gvolume.h"

// the double brackets is used because
// initializer lists ambiguity:
//
// std::vector<int> i{10, 0};    // 10 elements of value zero
// std::vector<int> j{{10, 0}};  // 2 elements of value 10 and 0 respectively

array<string, gVolumeNumberOfParameters> gVolumeValidKeys = { {
	"name",
	"mother",
	"description",
	"type",
	"dimensions",
	"visible",
	"style",
	"color",
	"material",
	"magfield",
	"pos"       ,
	"rot",
	"sensitivity",
	"touchableID",
	"copyOf",
	"replicaOf",
	"ncopy",
	"solidsOpr",
	"mirror" } } ;



// c++
#include <iostream>

// mlibrary
#include "gstring.h"
using namespace gstring;

GVolume::GVolume(vector<string> pars)
{
	// size is already checked in addVolume, the only interface to volume
	name        = trimSpacesFromString(pars[0]);
	mother      = trimSpacesFromString(pars[1]);
	description = trimSpacesFromString(pars[2]);

	type        = trimSpacesFromString(pars[3]);
	dimensions  = trimSpacesFromString(pars[4]);

	string pvis = trimSpacesFromString(pars[5]);
	visible     = (pvis == "1") ? true : false;
	style       = stoi(trimSpacesFromString(pars[6]));
	color       = trimSpacesFromString(pars[7]);

	material    = trimSpacesFromString(pars[8]);
	magfield    = trimSpacesFromString(pars[9]);

	pos         = trimSpacesFromString(pars[10]);
	rot         = trimSpacesFromString(pars[11]);

	sensitivity = trimSpacesFromString(pars[12]);
	touchableID = trimSpacesFromString(pars[13]);

	copyOf      = trimSpacesFromString(pars[14]);
	replicaOf   = trimSpacesFromString(pars[15]);
	ncopy       = stoi(trimSpacesFromString(pars[16]));
	solidsOpr   = trimSpacesFromString(pars[17]);

	mirror      = trimSpacesFromString(pars[18]);
}


ostream &operator<<(ostream &stream, GVolume gVol)
{
	string style = "unknown";
	if(gVol.style == 0) {
		style = "wireframe";
	} else if(gVol.style == 1){
		style = "solid";

	}
	string visibility = "yes";
	if(!gVol.visible) {
		visibility = "no";
	}

	stream  << endl;
	stream << "   - Name:           "    << gVol.name     << "  -  " <<  gVol.description << endl;
	stream << "   - Mother:         "    << gVol.mother      << endl;
	stream << "   - Type:           "    << gVol.type        << endl;
	stream << "   - Dimensions:     "    << gVol.dimensions  << endl;
	stream << "   - Color:          "    << gVol.color   << "  , visible: " << visibility << ",  with style: "  << style << endl;
	stream << "   - Material:       "    << gVol.material << endl;
	stream << "   - Magnetic Field: "    << gVol.magfield << endl;
	stream << "   - Position (cm):  "    << gVol.pos << endl;
	stream << "   - Rotation:       "    << gVol.rot << endl;
	stream << "   - Sensitivity:    "    << gVol.sensitivity << endl;
	stream << "   - Touchable ID:   "    << gVol.touchableID << endl;

	return stream;
}




