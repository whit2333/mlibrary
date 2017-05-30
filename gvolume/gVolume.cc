// gVolume
#include "gVolume.h"

// the double brackets is used because
// initializer lists ambiguity:
//
// std::vector<int> i{10, 0};    // 10 elements of value zero
// std::vector<int> j{{10, 0}};  // 2 elements of value 10 and 0 respectively

array<string, 20> gTableValidKeys = { {
	"name",
	"mother",
	"description",
	"factory",
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
	"copyOf",
	"replicaOf",
	"ncopy",
	"solidsOpr",
	"mirrorType",
	"mirrorMat" } } ;

array<string, 5> gVolumeNecessaryKeys = { {
	"name",
	"factory",
	"type",
	"dimensions",
	"material",
} } ;


// c++
#include <iostream>

// mlibrary
#include "gstring.h"
using namespace gstring;


// checks for key validity
bool GTable::isValidKey(string thisKey)
{
	if(find(gTableValidKeys.begin(), gTableValidKeys.end(), thisKey) != gTableValidKeys.end()) {
		return true;
	}

	return false;
}

bool GTable::addData(string thisKey, string data)
{
	if(isValidKey(thisKey)) {
		// remove leading and trailing spaces
		gtable[thisKey] = trimSpacesFromString(data);
		return true;
	}
	return false;
}

string GTable::getData(string thisKey)
{
	if(isValidKey(thisKey)) {
		// making sure the key exist
		if(gtable.find(thisKey) != gtable.end()) {
			return gtable[thisKey];
		}
	}
	return "notDefined";
}

GVolume::GVolume(GTable gt)
{
	// initialize variables that could be omitted
	initGVolumeMembers();

	// making sure the necessary variables are there
	for (auto &s : gVolumeNecessaryKeys) {
		if(gt.getData(s) == "notDefined") {
			cout << " !!! Fatal Error: key " << s << " not defined. Exiting. " << endl;
			exit(0);
		}
	}

	// now initializing members
	// making sure the necessary variables are there
	for (auto &s : gTableValidKeys) {
		string tableValue = gt.getData(s);
		if(tableValue != "notDefined") {
				 if(s == "name")               name = tableValue;
			else if(s == "mother")           mother = tableValue;
			else if(s == "description") description = tableValue;
			else if(s == "factory")         factory = tableValue;
			else if(s == "type")               type = tableValue;
			else if(s == "dimensions")   dimensions = tableValue;
			else if(s == "visible")        visible  = (tableValue == "1") ? 1 : 0;
			else if(s == "style")             style = stoi(tableValue);
			else if(s == "color")             color = tableValue;
			else if(s == "material")       material = tableValue;
			else if(s == "magfield")       magfield = tableValue;
			else if(s == "pos")                 pos = tableValue;
			else if(s == "rot")                 rot = tableValue;
			else if(s == "sensitivity") sensitivity = tableValue;
			else if(s == "copyOf")          copyOf  = tableValue;
			else if(s == "replicaOf")     replicaOf = tableValue;
			else if(s == "ncopy")             ncopy = stoi(tableValue);
			else if(s == "solidsOpr")     solidsOpr = tableValue;
			else if(s == "mirrorType")   mirrorType = tableValue;
			else if(s == "mirrorMat")     mirrorMat = tableValue;
		}
	}
}


// these member variables may be left unitialized
void GVolume::initGVolumeMembers()
{
	mother      = "root";
	description = "notGiven";
	visible     = true;
	style       = 1;
	color       = "556699";
	magfield    = "inherit";
	pos         = "no";
	rot         = "no";
	sensitivity = "no";
	copyOf      = "no";
	replicaOf   = "no";
	ncopy       = 0;
	solidsOpr   = "no";
	mirrorType  = "no";
	mirrorMat   = "no";
}








