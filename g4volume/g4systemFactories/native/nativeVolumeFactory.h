#ifndef SYSTEMTEXTFACTORY_H
#define SYSTEMTEXTFACTORY_H 1

// gvolume
#include "../systemFactory.h"

// system factory
class G4NativeSystemFactory : G4SystemFactory
{
public:
	void loadSystem(GOptions* gopt, G4Setup *s) {
		verbosity = gopt->getInt("vsetup");
		if(verbosity > 1) {
			cout << setupLogHeader << " Loading <text> system " << s->getName() << endl;
		}
		loadMaterial(gopt, s);
		loadGeometry(gopt, s);
	}

private:
	int verbosity;

private:
	virtual void buildSolid(GOptions* gopt, G4Setup *s)    = 0;
	virtual void buildLogical(GOptions* gopt, G4Setup *s)  = 0;
	virtual void buildPhysicsl(GOptions* gopt, G4Setup *s) = 0;

};


#endif
