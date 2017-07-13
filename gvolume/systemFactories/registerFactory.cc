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
				gSystemManager.RegisterObjectFactory<GSystemTextFactory>("GSystemTextFactory");
				systemFactory[factory] = gSystemManager.CreateObject<GSystemFactory>("GSystemTextFactory");
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
			cerr << " !!! Fatal Error: systemFactory factory <" << factory << "> not found for " << systemName << endl;
			exit(0);
		}


		// PRAGMA: TODO
		// account number of volume definitions loaded
//		if(verbosity > GVERBOSITY_SILENT) {
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

	// making sure every detector mother is defined
	for(auto &s : setup) {
		for(auto &vname: s.second->getAllVolumeNames()) {
			string mother = s.second->getGVolume(vname)->getMother();
			if(mother != "world") {
				if(s.second->getGVolume(mother) == nullptr) {
					cerr << " !!! Fatal Error: mother <" << mother << "> not found for <" << vname << ">" << endl;
					exit(0);
				}
			}
		}
	}
	
}
