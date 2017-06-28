// gvolume
#include "systemFactory.h"
#include "text/systemTextFactory.h"


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

		if(systemFactory.find(factory) != systemFactory.end()) {
			systemFactory[factory]->loadSystem(gopt, setup[systemName]);
		} else {
			cout << " !!! Error: systemFactory factory <" << factory << "> not found for " << systemName << endl;
		}


		// PRAGMA: TODO
		// account number of volume definitions loaded
//		if(verbosity > 0) {
//			cout << setupLogHeader << factory << " factory produced " << setup.size() << " volumes in system " << systemName << endl ;
//		}

	}

	// applying modifiers
	for(auto &m : setupModifiers) {
		for(auto &s : setup) {
			GVolume *thisVolume = s.second->getGVolume(m.first);
			if(thisVolume != nullptr) {
				thisVolume->modifyPos(m.second->getShift());
				thisVolume->modifyRot(m.second->getTilts());
				thisVolume->modifyExistence(m.second->getExistence());
			}
		}
	}


}
