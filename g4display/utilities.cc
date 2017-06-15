// g4display
#include "g4display.h"


/*! \fn map<string, GOption> G4Display::defineOptions()

 \return defines GSetup specific options

 */
map<string, GOption> G4Display::defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["g4view"] = GOption("The geant4 viewer", "OGLSQt 800x800 400-100", "g4display", true);
	optionsMap["g4view"].addHelp("The available viewers are:\n");
	optionsMap["g4view"].addHelp(" - OGLSQt: Open GL Qt Store mode (default)\n");
	optionsMap["g4view"].addHelp(" - OGLIQt: Open GL Qt Immediate mode\n");
	optionsMap["g4view"].addHelp("Additional optional arguments:\n");
	optionsMap["g4view"].addHelp(" - widthxheigth: window size. Default: 800x800\n");
	optionsMap["g4view"].addHelp(" - xcoordinate-ycoordinate): window position. Default: 400-100\n");

	return optionsMap;
}
