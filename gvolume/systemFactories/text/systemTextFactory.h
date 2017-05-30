#ifndef SYSTEMTEXTFACTORY_H
#define SYSTEMTEXTFACTORY_H 1

#include "../systemFactory.h"

// system factory
class GSystemTextFactory : GSystemFactory
{
public:
	void loadSystem(GOptions* gopt);
private:
	vector<string> paths; // Paths to system data

private:
	virtual void loadMaterial();
	virtual void loadGeometry();

};


#endif
