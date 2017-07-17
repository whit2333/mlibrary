#ifndef  GDYNAMIC_H
#define  GDYNAMIC_H




class GDynamic {

public:



	// by default the touchable is not changed
	// this function is loaded by plugin methods
	virtual vector<GTouchable*> processTouchable(GTouchable *gTouchID, G4Step* thisStep) {return { gTouchID } ;}




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
