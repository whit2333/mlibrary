// gVolume
#include "gSystem.h"
#include "systemFactory.h"
#include "text/systemTextFactory.h"

// mlibrary
#include "gfactory.h"

void GSetup::registerFactoriesAndLoadSystems(GOptions* gopt)
{

	map<string, GSystemFactory*> systemFactory;

	// registering factories in the manager
	// and adding them to systemFactory
	for(auto &s : setup) {
		string factory = s.second->getFactory();

		// text
		// ----
		if(factory == "text") {
			// if factory not found, registering it in the manager and loading it into the map
			if(systemFactory.find(factory) == systemFactory.end()) {
				gSystemManager.RegisterObjectFactory<GSystemTextFactory>(factory);
				systemFactory[factory] = gSystemManager.CreateObject<GSystemFactory>(factory);
			}
		}

	}


	// now loading detector definitions
	for(auto &s : setup) {
		string factory    = s.second->getFactory();
		string systemName = s.first;
		
		systemFactory[factory]->loadSystem(gopt, setup[systemName]);
	}


}
