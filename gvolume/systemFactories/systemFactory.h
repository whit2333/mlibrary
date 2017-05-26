#ifndef SYSTEMFACTORY_H
#define SYSTEMFACTORY_H 1

// c++
#include <string>
#include <vector>
using namespace std;

// mlibrary
#include "goptions.h"

// system factory
class GSystemFactory
{
public:
	virtual void loadSystem(GOptions* gopt) = 0;
	virtual ~GSystemFactory() = default;

};

#endif
