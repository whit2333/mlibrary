#ifndef SYSTEMDFACTORY_H
#define SYSTEMDFACTORY_H 1

// c++
#include <string>
#include <vector>
using namespace std;

// mlibrary
#include "goptions.h"

// system factory
class GSystemDynamicFactory
{
public:
	virtual void loadSystem(GOptions* gopt) = 0;
	virtual ~GSystemDynamicFactory() = default;

	// this method must be present for the dynamic loaded factories
	static GSystemDynamicFactory* instantiate(const dlhandle handle) {

		if (handle == nullptr) return nullptr;

		void *maker = dlsym(handle , "GSystemDynamicFactory");

		if (maker == nullptr) return nullptr;

		typedef GSystemDynamicFactory* (*fptr)();

		// static_cast not allowed here
		// see http://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
		// need to run the DLL GSystemDynamicFactory function that returns the factory
		fptr func = reinterpret_cast<fptr>(reinterpret_cast<void*>(maker));

		return func();
	}

};

#endif
