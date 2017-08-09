// gvolume
#include "gvolume.h"
#include "gsystem.h"

// c++
#include <fstream>

// mlibrary
#include "gstring.h"
using namespace gstring;

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
	optionsMap["gvolumev"].addHelp(GVERBOSITY_SILENT_D);
	optionsMap["gvolumev"].addHelp(GVERBOSITY_SUMMARY_D);
	optionsMap["gvolumev"].addHelp(GVERBOSITY_DETAILS_D);
	optionsMap["gvolumev"].addHelp(GVERBOSITY_ALL_D);

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
				if(verbosity == GVERBOSITY_ALL) {
					cout << setupLogHeader << " Trying " << newName << endl;
				}
				if(IN->good()) {
					if(verbosity > GVERBOSITY_SILENT) {
						cout << setupLogHeader << " Opening " << newName << endl;
					}
					// file found
					return  IN;
				}
			}
		}
		// file not found
		cout << setupLogHeader << " File " << fname << " not found " << endl;

	}
	// file was found
	return IN;
}

string GSystem::getSystemPath()
{
	return getPathFromFilename(name);

}


