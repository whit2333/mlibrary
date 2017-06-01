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
	GModifiers(string n, string s, string t, string e, int verbosity) : name(n), shift(s), tilts(t) {

		present = true;
		if(e == "no") present = false;

		if(verbosity > 0) {
			cout << setupLogHeader <<  " Volume " << name << " modified with:";
			if (  shift != "default") cout << " - shift: "     << shift   ;
			if (  tilts != "default") cout << " - tilts: "     << tilts   ;
			if (present != true)      cout << " - existance: " << present ;
			cout << endl;
		}
	}
private:
	string name;  // volume name
	string shift;
	string tilts;
	bool present; // true by default
};


class GSystem {

public:
	GSystem(string n, string f, string v, int r, int dr, int verbosity);

public:
	string getFactory() const { return factory; }
	string getName() const    { return name; }
	ifstream gSystemFile(int which, vector<string> locations, int verbosity);  // 0: material. 1: geometry

	void addGVolume(vector<string> pars, int verbosity);

	GVolume* getGVolume(string key) {
		return systems[key];
	}

private:
	string      name;     // System name
	string   factory;     // Factory that builds the detector
	string variation;     // Variation of the detector. Default is "default"
	int    runNumber;     // Run Number selected for this detector. Default is 1

	// map containing the volumes
	// the key is system + volume name so the names must be unique in each system
	map<string, GVolume*> systems;


};


class GSetup {
public:
	// constructor from a gcard
	// by default all systems will have the same run number but
	GSetup(GOptions* gopt, int runNo = 1);

private:
	map<string, GSystem*> setup;
	map<string, GModifiers*> setupModifiers;

	// manager to register the factories
	GManager gSystemManager;
	void registerFactoriesAndLoadSystems(GOptions* gopt);
	
public:
	// GSetup options - defined in utilities.cc
	static map<string, GOption> defineOptions();

};

#endif
