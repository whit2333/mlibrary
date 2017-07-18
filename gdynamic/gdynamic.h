#ifndef  GDYNAMIC_H
#define  GDYNAMIC_H 1

// mlibrary
#include "gfactory.h"
#include "gtouchable.h"

// c++
#include <vector>
using namespace std;

// geant4
#include "G4Step.hh"

class GDynamic {

public:


	// by default the touchable is not changed
	// this function is loaded by plugin methods
	virtual vector<GTouchable*> processTouchable(GTouchable *gTouchID, G4Step* thisStep) {return { gTouchID } ;}


	// loads the calibration constants
	// return false for failure
	virtual bool loadConstants(int runno, string variation) { return false; }


	// this method must be present for the dynamic loaded factories
	static GDynamic* instantiate(const dlhandle handle) {

		if (handle == nullptr) return nullptr;

		void *maker = dlsym(handle , "GDynamicFactory");

		if (maker == nullptr) return nullptr;

		typedef GDynamic* (*fptr)();

		// static_cast not allowed here
		// see http://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
		// need to run the DLL GDynamicFactory function that returns the factory
		fptr func = reinterpret_cast<fptr>(reinterpret_cast<void*>(maker));

		return func();
	}

};


#endif
