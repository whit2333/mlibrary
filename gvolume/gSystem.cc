// gVolume
#include "gSystem.h"

// mlibrary
#include "gstring.h"
using namespace gstring;


GSetup::GSetup(GOptions* gopt, int runNo)
{
	// this is already validated for XML syntax and file existance
	QDomDocument domDocument = gopt->configurationQDomDocument;

	// add all the systems
	QDomNode domNode = domDocument.documentElement().firstChild();

	while(!domNode.isNull()) {
		QDomElement domElement = domNode.toElement();                     // converts the node to an element.
		if(!domElement.isNull()) {                                        // the node really is an element.
			if(qVariantToStdString(domElement.tagName()) == "system")  {  // selecting "detector" nodes
				string     thisNname = assignAttribute(domElement, "name",      "na");
				string   thisFactory = assignAttribute(domElement, "factory",   "na");
				string thisVariation = assignAttribute(domElement, "variation", "default");
				int    thisRunNumber = assignAttribute(domElement, "runno",     runNo);

				if(thisNname != "na" && thisFactory != "na") {
					setup[thisNname] = new GSystem(thisNname,
												   thisFactory,
												   thisVariation,
												   thisRunNumber,
												   runNo);
				}

			}
		}
		domNode = domNode.nextSibling();
	}

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

	return optionsMap;
}
