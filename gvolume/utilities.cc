// gvolume
#include "gVolume.h"
#include "gSystem.h"

// c++
#include <iostream>

ostream &operator<<(ostream &stream, GVolume gVol)
{
	cout  << endl;
	cout << "   Volume Name:  "    << gVol.name     << "  -  " <<  gVol.description << endl;
	cout << "   Mother:  "         << gVol.mother              << endl;
	cout << "   Factory:  "        << gVol.factory             << endl;
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

	optionsMap["setupDir"] = GOption("Add a path to check for setup", "na", "system", true);

	optionsMap["vsetup"] = GOption("Setup Verbosity", 1, "system");
	optionsMap["vsetup"].addHelp("Possible values:\n");
	optionsMap["vsetup"].addHelp(" - 0: silent\n");
	optionsMap["vsetup"].addHelp(" - 1: summary information\n");
	optionsMap["vsetup"].addHelp(" - 2: details\n");

	return optionsMap;
}





