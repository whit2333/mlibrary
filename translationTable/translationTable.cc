/// \file translationTable.cc
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

// translationTable framework
#include "translationTable.h"

// c++
#include <iostream>

string TranslationTable::hardwareKey(vector<int> c)
{
	string hardwareKey = "";
	for(const auto &v : c)
		hardwareKey += to_string(v);

	return hardwareKey;
}


Hardware TranslationTable::getHardware(vector<int> c)
{
	string hk = hardwareKey(c);

	auto search = tt.find(hk);

	if(search != tt.end())
		return search->second;
	else {
		cout << " !! Error: item not found in translation table " << name << " for item " << search->first << endl;
		return Hardware();
	}

}

void TranslationTable::addHardwareItem(vector<int> c, Hardware h)
{
	string hk = hardwareKey(c);
	tt[hk] = h;
}


//! overloading "<<" to print this class
ostream &operator<<(ostream &stream, Hardware h)
{

	stream << " Crate: "   << h.getCrate();
	stream << " Slot: "    << h.getSlot();
	stream << " Channel: " << h.getChannel();
	
	return stream;
}
