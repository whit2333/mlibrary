// g4volume
#include "g4volume.h"

// c++
#include <fstream>


/*! \fn map<string, GOption> G4Setup::defineOptions()

 \return defines G4Setup specific options

 */
map<string, GOption> G4Setup::defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["hall"]          = GOption("Hall Dimensions",    "20*m 20*m 20*m", "g4volumes");
	optionsMap["defaultMat"]    = GOption("Default Material",   "G4_AIR",         "g4volumes");
	optionsMap["checkOverlaps"] = GOption("Check for overlaps", 0,                "g4volumes");

	return optionsMap;
}


