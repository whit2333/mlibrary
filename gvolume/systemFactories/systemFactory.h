#ifndef SYSTEMFACTORY_H
#define SYSTEMFACTORY_H 1

// mlibrary
#include "goptions.h"

// gvolume
#include "gsystem.h"


// system factory
class GSystemFactory
{
public:
	virtual void loadSystem(GOptions* gopt, GSystem *s) = 0;
	virtual ~GSystemFactory() = default;

private:
	virtual void loadMaterial(GOptions* gopt, GSystem *s) = 0;
	virtual void loadGeometry(GOptions* gopt, GSystem *s) = 0;
	
};

#endif
