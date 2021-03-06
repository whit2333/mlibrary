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

	// geant4 view option
	optionsMap["g4view"] = GOption("The geant4 viewer, size and position", defaultG4viewOption, "g4display", true);
	optionsMap["g4view"].addHelp("The available viewers are:\n");
	for(auto &v : availableG4Viewers) {
		optionsMap["g4view"].addHelp(string(GOPTIONITEM) + v + "\n");
	}
	optionsMap["g4view"].addHelp("Size and position optional arguments:\n");
	optionsMap["g4view"].addHelp(string(GOPTIONITEM) + "widthxheigth: window size. Default: "                  + defaultSizeOption + "\n");
	optionsMap["g4view"].addHelp(string(GOPTIONITEM) + "+xcoordinate+ycoordinate): window position. Default: " + defaultPosOption  + "\n");

	// camera options
	optionsMap["cameraAngles"] = GOption("Theta and phi angles of the camera, in degrees", "0*deg 0*deg", "g4display", true);


	return optionsMap;
}
