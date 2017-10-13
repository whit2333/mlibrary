#ifndef SYSTEMTEXTFACTORY_H
#define SYSTEMTEXTFACTORY_H 1

// gvolume
#include "../systemFactory.h"

// system factory
class GSystemTextFactory : GSystemFactory
{
public:
	void loadSystem(GOptions* gopt, GSystem *s) {
		verbosity = gopt->getInt("gvolumev");
		if(verbosity > GVERBOSITY_SUMMARY) {
			cout << setupLogHeader << " Loading <text> system " << s->getName() << endl;
		}
		loadMaterial(gopt, s);
		loadGeometry(gopt, s);
	}

private:
	vector<string> paths; // Paths to system data

private:
	// PRAGMA TODO: is GOptions necessary?
	virtual void loadMaterial(GOptions* gopt, GSystem *s);
	virtual void loadGeometry(GOptions* gopt, GSystem *s);
};

#endif
