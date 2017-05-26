#ifndef  GSYSTEM_H
#define  GSYSTEM_H 1

// c++
#include <string>
using namespace std;

// gvolume
#include "gVolume.h"

// mlibrary
#include "goptions.h"
#include "gfactory.h"

#define setupLogHeader " - setup:"

class GModifiers {
public:
	GModifiers(string n, string s, string t, string e) : name(n), shift(s), tilts(t) {

		present = true;
		if(e == "no") present = false;


		cout << setupLogHeader <<  " Volume " << name << " modified with:";
		if (  shift != "default") cout << " - shift: "     << shift   ;
		if (  tilts != "default") cout << " - tilts: "     << tilts   ;
		if (present != true)      cout << " - existance: " << present ;
		cout << endl;
	}
private:
	string name;  // volume name
	string shift;
	string tilts;
	bool present; // true by default
};

class GSystem {

public:
	GSystem(string n, string f, string v, int r, int dr) : name(n), factory(f), variation(v), runNumber(r) {
		cout << setupLogHeader << " System " << name << " loaded with factory " << factory;
		cout << ", variation: " << variation << ", run number: " << runNumber ;
		if(dr != r) cout << " (non default) ";
		cout << endl;
	}
	void setPaths(vector<string> p) {paths = p;}

private:
	string      name;     // System name
	string   factory;     // Factory that builds the detector
	string variation;     // Variation of the detector. Default is "default"
	int    runNumber;     // Run Number selected for this detector. Default is 1
	vector<string> paths; // Paths to system data

	// map containing the volumes
	// the key is system + volume name so the names must be unique in each system
	map<string, GVolume*> systems;
	map<string, GManager> systemGFactories;

};

class GSetup {
public:
	// constructor from a gcard
	// by default all systems will have the same run number but
	GSetup(GOptions* gopt, int runNo = 1);

private:
	map<string, GSystem*> setup;
	map<string, GModifiers*> setupModifiers;

public:
	// GSetup options - defined in utilities.cc
	static map<string, GOption> defineOptions();

};

#endif
