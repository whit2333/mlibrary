// gtouchable
#include "gtouchable.h"

// c++
#include <string>

// mlibrary
#include "gstring.h"
using namespace gstring;

GTouchable::GTouchable(string sensitivity, string gtouchableString) :
trackId(0),
eMultiplier(1)
{
	if(sensitivity == "flux") {
		gType = flux;
	} else 	if(sensitivity == "counter") {
		gType = counter;
	} else  {
		gType = readout;
	}

	// loading gvolume touchable id from the gvolume descriptor, which is in the format <description, integer>
	// sector # layer # paddle # side #
	// the description is ignored
	vector<string> touchD = getStringVectorFromString(gtouchableString);
	for(unsigned i=0; i<touchD.size(); i++) {
		if(i%2 == 1) {
			gTid.push_back(stoi(touchD[i]));
		}
	}
}

string GTouchable::getGTouchableDescriptionString()
{
	string gtstring = "";
	for(auto &t : gTid) {
		gtstring = gtstring + " " + to_string(t);
	}
	return gtstring;
}
