#ifndef SYSTEMFACTORY_H
#define SYSTEMFACTORY_H 1

// c++
#include <string>
#include <vector>
using namespace std;

// mlibrary
#include "goptions.h"

// gVolume
#include "gSystem.h"


// system factory
class GSystemFactory
{
public:
	virtual void loadSystem(GOptions* gopt, GSystem *s) = 0;
	virtual ~GSystemFactory() = default;

private:
	virtual void loadMaterial() = 0;
	virtual void loadGeometry() = 0;
	
};

#endif
