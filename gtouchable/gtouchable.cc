// gtouchable
#include "gtouchable.h"

// c++
#include <string>

// mlibrary
#include "gstring.h"
using namespace gstring;

GTouchable::GTouchable(string sensitivity, string gtouchableString) :
trackId(0),
eFraction(1)
{
	if(sensitivity == "flux") {
		gType = flux;
	} else 	if(sensitivity == "counter") {
		gType = counter;
	} else  {
		gType = readout;
	}

	// loading gvolume touchable id. It is in a loop because we get doubles from getG4NumbersFromString
	vector<double> touchD = getG4NumbersFromString(gtouchableString);
	for(auto &td : touchD) {
		gTid.push_back(td);
	}
}
