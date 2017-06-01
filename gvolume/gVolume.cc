// gVolume
#include "gVolume.h"

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
	name        = pars[0];
	mother      = pars[1];
	description = pars[2];

	type        = pars[3];
	dimensions  = pars[4];

	visible     = (pars[5] == "1") ? 1 : 0;;
	style       = stoi(pars[6]);;
	color       = pars[7];

	material    = pars[8];
	magfield    = pars[9];

	pos         = pars[10];
	rot         = pars[11];

	sensitivity = pars[12];
	touchableID = pars[13];

	copyOf      = pars[14];
	replicaOf   = pars[15];
	ncopy       = stoi(pars[16]);
	solidsOpr   = pars[17];

	mirror      = pars[18];
}







