#ifndef G4NATIVEVOLUMEFACTORY_H
#define G4NATIVEVOLUMEFACTORY_H 1

// g4volume
#include "../g4VolumeFactory.h"

// system factory
class G4NativeSystemFactory : G4SetupFactory
{
public:
	bool loadG4Setup(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s) {
		verbosity = gopt->getInt("vsetup");
		if(verbosity > 1) {
			cout << setupLogHeader << " Building geant4 volumes." << endl;
		}

		return buildSolid(gopt, s, g4s) + buildLogical(gopt, s, g4s) + buildPhysicsl(gopt, s, g4s);;
	}

private:
	int verbosity;

private:
	// PRAGMA TODO: is GOptions necessary?
	bool buildSolid(   GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s) ;
	bool buildLogical( GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s);
	bool buildPhysicsl(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s);

	vector<string> descriptionsOfParameters(GVolume *s);         // returns description of geant4 constructor parameters
	vector<string> checkAndReturnParameters(GVolume *s); // checks and returns the number of parameters matches the geant4 constructor

};


#endif
