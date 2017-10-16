// g4volume
#include "g4SetupFactory.h"
#include "native/g4NativeSetupFactory.h"
#include "cad/g4CadSetupFactory.h"

void G4Setup::registerFactoriesAndBuildG4Volumes(GSetup* gsetup, GOptions* gopt)
{
	int verbosity = gopt->getInt("g4volumev");

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
				g4SystemManager.RegisterObjectFactory<G4NativeSetupFactory>("G4NativeSetupFactory");
				g4setupactory[factory] = g4SystemManager.CreateObject<G4SetupFactory>("G4NativeSetupFactory");
			}
		} else if(factory == "cad") {
			// if factory not found, registering it in the manager and loading it into the map
			if(g4setupactory.find(factory) == g4setupactory.end()) {
				g4SystemManager.RegisterObjectFactory<G4CadSetupFactory>("G4CadSetupFactory");
				g4setupactory[factory] = g4SystemManager.CreateObject<G4SetupFactory>("G4CadSetupFactory");
			}
		}
		
	}

	// now building geant4 objects
	// every volume that is not built (due to dependencies) increments remainingVolumes
	int remainingVolumes;
	int allRemainingVolumes = 0;
	do {
		remainingVolumes = 0;
		// looping over systems
		for(auto &s : gsetup->getSetup()) {
			string factory = s.second->getFactory();
			// looping over volumes in that system
			for(auto &v : s.second->getSytems()) {
				if(g4setupactory.find(factory) != g4setupactory.end()) {
					if(g4setupactory[factory]->loadG4Setup(gopt, v.second, g4setup) == false) remainingVolumes = remainingVolumes + 1;
				} else {
					cerr << FATALERRORL << "  Fatal Error: g4setupactory factory <" << factory << "> not found." << endl;
					exit(0);
				}
			}
			if(verbosity == GVERBOSITY_ALL) {
				cout << setupLogHeader << " " << s.first << " remaining g4volumes to be built: " << remainingVolumes << endl;
			}
		}
		if(allRemainingVolumes != 0) {
			if(allRemainingVolumes >= remainingVolumes) {
				cerr << FATALERRORL << " Fatal Error: dependencies are not being resolved: their number should diminish." << endl;
				exit(0);
			}
		} else {
			allRemainingVolumes = remainingVolumes;
		}
	} while (remainingVolumes > 0);
}
