/// \mainpage
/// \section Overview
/// The translation tanle framework provides an interface between an
/// hardware object <Crate Slot Channel> to a vector of int.\n

/// \file translationTable.h
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

#ifndef GTRANSLATIONTABLE_H
#define GTRANSLATIONTABLE_H

// c++
#include <string>
#include <map>
#include <vector>
using namespace std;

struct hardware {

private:
	int crate   = 0;
	int slot    = 0;
	int channel = 0;

public:
	int getCrate()   {return crate;}
	int getSlot()    {return slot;}
	int getChannel() {return channel;}

};


class translationTable {
public:
	translationTable(string n) : name(n) { ; }

private:
	map<string, hardware> tt;
	string name;
	string hardwareKey(vector<int>);

public:
	hardware getHardware(vector<int>);
	void addHardwareItem(vector<int>, hardware);

};


#endif





