// g4volume
#include "g4VolumeFactory.h"
#include "native/nativeVolumeFactory.h"

void G4Setup::registerFactoriesAndBuildG4Volumes(GSetup* gsetup, GOptions* gopt)
{
	map<string, G4SetupFactory*> g4setupactory;

	// registering factories in the manager
	// and adding them to systemFactory
	for(auto &s : gsetup->getSetup()) {
		string factory = s.second->getFactory();

		// text
		// ----
		if(factory == "text") {
			// if factory not found, registering it in the manager and loading it into the map
			if(g4setupactory.find(factory) == g4setupactory.end()) {
				g4SystemManager.RegisterObjectFactory<G4NativeSystemFactory>(factory);
//				g4setupactory[factory] = g4SystemManager.CreateObject<G4SetupFactory>(factory);
			}
		}
	}
	

}
