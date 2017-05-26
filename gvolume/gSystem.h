#ifndef  GSYSTEM_H
#define  GSYSTEM_H 1

// c++
#include <string>
using namespace std;

// gvolume
#include "gVolume.h"

// options
#include "goptions.h"


class GSystem {

private:
	string      name;    // System name
	string   factory;    // Factory that builds the detector
	string variation;    // Variation of the detector. Default is "main"
	int    runNumber;    // Run Number selected for this detector
	bool   isPresent;    // true by default

	// modifiers
	string shift;
	string tilts;

	// map containing the volumes
	// the key is system + volume name so the names must be unique in each system
	map<string, GVolume> systems;

};

class GSetup {
	// constructor from a gcard
	GSetup(GOptions* gopt);

private:
	map<string, GSystem> setup;

public:
	// GSetup options
	static map<string, GOption> defineOptions();

};

#endif
