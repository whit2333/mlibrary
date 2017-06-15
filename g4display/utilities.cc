// g4display
#include "g4display.h"



/*! \fn map<string, GOption> G4Display::defineOptions()

 \return defines GSetup specific options

 */
map<string, GOption> G4Display::defineOptions()
{
	map<string, GOption> optionsMap;

	string defaultG4viewOption = string(defaultGViewerDriver) + " " +  string(defaultGViewerSize) + " " +  string(defaultGViewerPos);
	string defaultSizeOption   = string(defaultGViewerSize);
	string defaultPosOption    = string(defaultGViewerPos);

	optionsMap["g4view"] = GOption("The geant4 viewer, size and position", defaultG4viewOption, "g4display", true);
	optionsMap["g4view"].addHelp("The available viewers are:\n");
	for(auto &v : availableG4Viewers) {
		optionsMap["g4view"].addHelp(" - " + v + "\n");
	}
	optionsMap["g4view"].addHelp("Size and position optional arguments:\n");
	optionsMap["g4view"].addHelp(" - widthxheigth: window size. Default: "                  + defaultSizeOption + "\n");
	optionsMap["g4view"].addHelp(" - +xcoordinate+ycoordinate): window position. Default: " + defaultPosOption  + "\n");

	return optionsMap;
}
