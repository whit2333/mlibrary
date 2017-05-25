#include "gVolume.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

// checks for key validity
bool GTable::isValidKey(string thisKey)
{
	if(find(validKeys.begin(), validKeys.end(), thisKey) != validKeys.end()) {
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
