// gvolume
#include "gVolume.h"
#include "gSystem.h"

// c++
#include <iostream>
#include <fstream>

ostream &operator<<(ostream &stream, GVolume gVol)
{
	cout  << endl;
	cout << "   Volume Name:  "    << gVol.name     << "  -  " <<  gVol.description << endl;
	cout << "   Mother:  "         << gVol.mother              << endl;
	cout << "   Type:  "           << gVol.type                << endl;
	cout << "   Dimensions:  "     ;

	for(unsigned int i=0; i<gVol.dimensions.size(); i++) {
		cout << "  " << gVol.dimensions[i]   << "  " ;
	}
	cout << endl;


	string visibility = "yes";
	if(!gVol.visible) {
		visibility = "no";
	}
	string style = "unknown";
	if(gVol.style == 0) {
		style = "wireframe";
	} else if(gVol.style == 1){
		style = "solid";

	}
	cout << "   Color:  "          << gVol.color   << "  Visible: " << visibility << ",  with style: "  << style << endl;

	cout << "   Material:  "       << gVol.material << endl;
	cout << "   Magnetic Field:  " << gVol.magfield << endl;

	cout << "   Position (cm):  "  << gVol.pos << endl;
	cout << "   Rotation:       "  << gVol.rot << endl;

	cout << "   Sensitivity: "     << gVol.sensitivity << endl;
	cout << "   Touchable ID: "    << gVol.touchableID << endl;

	return stream;
}





/*! \fn map<string, GOption> GSplash::defineOptions()

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

	optionsMap["vsetup"] = GOption("Setup Verbosity", 1, "system");
	optionsMap["vsetup"].addHelp("Possible values:\n");
	optionsMap["vsetup"].addHelp(" - 0: silent\n");
	optionsMap["vsetup"].addHelp(" - 1: summary information\n");
	optionsMap["vsetup"].addHelp(" - 2: details\n");
	optionsMap["vsetup"].addHelp(" - 3: verbose details\n");

	return optionsMap;
}


ifstream GSystem::gSystemFile(int which, vector<string> locations, int verbosity)
{
	string fname;
	if(which == 0)       fname = name +  "__materials_" ;
	else if (which == 1) fname = name +  "__geometry_" ;
	else if (which == 2) fname = name +  "__mirrors_" ;
	fname += variation + ".txt";

	// default dir is "."
	ifstream IN(fname.c_str());

	if(!IN.good()) {
		for(auto locs : locations) {
			string newName = locs + "/" + fname;
			IN.open(newName.c_str());
			if(verbosity > 1) {
				cout << setupLogHeader << " Trying " << newName << endl;
			}
			if(IN.good()) {
				if(verbosity > 0) {
					cout << setupLogHeader << " Opening " << newName << endl;
				}
				return  IN;
			}
		}
		if(verbosity > 1) {
			cout << setupLogHeader << " File " << fname << "not found " << endl;
		}

	}

	return IN;

}



