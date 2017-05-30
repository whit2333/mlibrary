#ifndef SYSTEMTEXTFACTORY_H
#define SYSTEMTEXTFACTORY_H 1

#include "../systemFactory.h"

// system factory
class GSystemTextFactory : GSystemFactory
{
public:
	void loadSystem(GOptions* gopt) {
		verbosity = gopt->getInt("vsetup");
		if(verbosity > 1) {
			cout << " Loading <text> systems " << endl;
		}
		loadMaterial();
		loadGeometry();
	}

private:
	vector<string> paths; // Paths to system data
	int verbosity;

private:
	virtual void loadMaterial();
	virtual void loadGeometry();

};


#endif
