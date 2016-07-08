/// \file translationTable.cc
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

// translationTable framework
#include "translationTable.h"

// c++
#include <iostream>

string translationTable::hardwareKey(vector<int> c)
{
	string hardwareKey = "";
	for(const auto &v : c)
		hardwareKey += to_string(v);

	return hardwareKey;
}


hardware translationTable::getHardware(vector<int> c)
{
	string hk = hardwareKey(c);

	auto search = tt.find(hk);

	if(search != tt.end())
		return search->second;
	else {
		cout << " !! Error: item not found in translation table " << name << " for item " << search->first << endl;
		return hardware();
	}

}

void translationTable::addHardwareItem(vector<int> c, hardware h)
{
	string hk = hardwareKey(c);
	tt[hk] = h;
}

