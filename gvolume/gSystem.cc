// gVolume
#include "gSystem.h"

// mlibrary
#include "gstring.h"
using namespace gstring;


GSetup::GSetup(GOptions* gopt, int runNo)
{
	// this is already validated for XML syntax and file existance
	QDomDocument domDocument = gopt->configurationQDomDocument;

	// load the systems
	QDomNode domNode = domDocument.documentElement().firstChild();
	while(!domNode.isNull()) {
		QDomElement domElement = domNode.toElement();                     // converts the node to an element.
		if(!domElement.isNull()) {                                        // the node really is an element.
			if(qVariantToStdString(domElement.tagName()) == "system")  {  // selecting "system" nodes

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
	
	// load the modifiers
	domNode = domDocument.documentElement().firstChild();
	while(!domNode.isNull()) {
		QDomElement domElement = domNode.toElement();                       // converts the node to an element.
		if(!domElement.isNull()) {                                          // the node really is an element.
			if(qVariantToStdString(domElement.tagName()) == "modifier")  {  // selecting "modifier" nodes

				string    thisNname = assignAttribute(domElement, "volume",   "na");
				string thisPosition = assignAttribute(domElement, "position", "default");
				string thisRotation = assignAttribute(domElement, "rotation", "default");
				string     presence = assignAttribute(domElement, "present",  "yes");
				if(thisNname != "na" && (thisPosition != "default" || thisRotation != "default" || presence != "yes") ){
					setupModifiers[thisNname] = new GModifiers(thisNname,
												   thisPosition,
												   thisRotation,
												   presence);
				}
			}
		}
		domNode = domNode.nextSibling();
	}


	// loading static factories with setup verbosity
	GManager gSystemManager(gopt->getInt("vsetup"));

	for(auto &s : setup) {
		string gSFactoryType = s.second->getFactory();

		if(gSFactoryType == "text") {
			// factory not found, registering it in the manager and loading it into the map
			if(systemFactory.find(gSFactoryType) == systemFactory.end()) {
				gSystemManager.RegisterObjectFactory<GSystemTextFactory>(gSFactoryType);
				systemFactory[gSFactoryType] = gSystemManager.CreateObject<GSystemFactory>(gSFactoryType);
			}
		}
	}

	// now building the detector

}


GSystem::GSystem(string n, string f, string v, int r, int dr) : name(n), factory(f), variation(v), runNumber(r) {
	cout << setupLogHeader << " System " << name << " loaded with factory " << factory;
	cout << ", variation: " << variation << ", run number: " << runNumber ;
	if(dr != r) cout << " (non default) ";
	cout << endl;
}
