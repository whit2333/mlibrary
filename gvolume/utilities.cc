// gvolume
#include "gvolume.h"
#include "gsystem.h"

// c++
#include <fstream>


/*! \fn map<string, GOption> GSetup::defineOptions()

 \return defines GSetup specific options

 */
map<string, GOption> GSetup::defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["addSystem"] = GOption("Adds a system", "na", "system", true);
	optionsMap["addSystem"].addHelp("The mandatory arguments, separated by commas, are:\n");
	optionsMap["addSystem"].addHelp(" - system name \n");
	optionsMap["addSystem"].addHelp(" - system factory\n");
	optionsMap["addSystem"].addHelp(" - Optional arguments are:\n");
	optionsMap["addSystem"].addHelp(" - system variation (default: \"default\")\n");
	optionsMap["addSystem"].addHelp(" - system run number (default: 1)\n");
	optionsMap["addSystem"].addHelp(" Example: -addSystem=\"ctof, cad, default, 12\"\n");

	optionsMap["setupDir"] = GOption("Path(s) to check for setup, separated by space", "na", "system", true);

	optionsMap["gvolumev"] = GOption("Volume Verbosity", 0, "verbosity");
	optionsMap["gvolumev"].addHelp("Possible values:\n");
	optionsMap["gvolumev"].addHelp(" - 0: silent\n");
	optionsMap["gvolumev"].addHelp(" - 1: summary information\n");
	optionsMap["gvolumev"].addHelp(" - 2: details\n");
	optionsMap["gvolumev"].addHelp(" - 3: verbose details\n");

	optionsMap["logVolume"] = GOption("Print everything related to this volume", "na", "verbosity");

	return optionsMap;
}


ifstream* GSystem::gSystemFile(int which, vector<string> locations, int verbosity)
{
	string fname;
	if(which == 0)       fname = name +  "__materials_" ;
	else if (which == 1) fname = name +  "__geometry_" ;
	else if (which == 2) fname = name +  "__mirrors_" ;
	fname += variation + ".txt";

	// default dir is "."
	ifstream *IN = new ifstream(fname.c_str());

	if(!IN->good()) {
		for(auto locs : locations) {
			if(locs != "na") {
				string newName = locs + "/" + fname;
				IN->open(newName.c_str());
				if(verbosity > 2) {
					cout << setupLogHeader << " Trying " << newName << endl;
				}
				if(IN->good()) {
					if(verbosity > 0) {
						cout << setupLogHeader << " Opening " << newName << endl;
					}
					return  IN;
				}
			}
		}
		// file not found
		cout << setupLogHeader << " File " << fname << " not found " << endl;

	}
	return IN;
}



