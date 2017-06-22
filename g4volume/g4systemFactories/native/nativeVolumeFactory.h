#ifndef G4NATIVEVOLUMEFACTORY_H
#define G4NATIVEVOLUMEFACTORY_H 1

// g4volume
#include "../g4VolumeFactory.h"

// system factory
class G4NativeSystemFactory : G4SetupFactory
{
public:
	bool loadG4Setup(GOptions* gopt, G4Setup *s) {
		verbosity = gopt->getInt("vsetup");
		if(verbosity > 1) {
			cout << setupLogHeader << " Building geant4 volumes." << endl;
		}
		return true;
	}

private:
	int verbosity;

private:
	void buildSolid(   GOptions* gopt, G4Setup *s) ;
	void buildLogical( GOptions* gopt, G4Setup *s);
	void buildPhysicsl(GOptions* gopt, G4Setup *s);

};


#endif
