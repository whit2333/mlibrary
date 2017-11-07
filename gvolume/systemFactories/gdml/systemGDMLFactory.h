#ifndef SYSTEMTEXTFACTORY_H
#define SYSTEMTEXTFACTORY_H 1

// gvolume
#include "../systemFactory.h"

// system factory
class GSystemGDMLFactory : GSystemFactory
{
public:
	void loadSystem(GOptions* gopt, GSystem *s) {
		verbosity = gopt->getInt("gvolumev");
		if(verbosity > GVERBOSITY_SUMMARY) {
			cout << setupLogHeader << " Loading <GDML> system " << s->getName() << endl;
		}
		loadMaterial(gopt, s);
		loadGeometry(gopt, s);
	}
	
private:
	vector<string> paths; // Paths to system data
	int verbosity;
	
private:
	// PRAGMA TODO: is GOptions necessary?
	virtual void loadMaterial(GOptions* gopt, GSystem *s);
	virtual void loadGeometry(GOptions* gopt, GSystem *s);
	
};


#endif
