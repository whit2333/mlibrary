#ifndef  GMEDIA_H
#define  GMEDIA_H  1

// mlibrary
#include "gdata.h"
#include "gdl.h"

class GMedia
{

public:
	virtual ~GMedia() = default;

	
	bool publishData(vector<GEventData*> *runData);

	virtual bool publishHeader(vector<GEventData*> *runData) { return false;}
	
private:
	string outputFileName;
	
	
	// method to dynamically load factories
	static GMedia* instantiate(const dlhandle handle) {
		
		if (handle == nullptr) return nullptr;
		
		void *maker = dlsym(handle , "GMediaFactory");
		
		if (maker == nullptr) return nullptr;
		
		typedef GMedia* (*fptr)();
		
		// static_cast not allowed here
		// see http://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast
		// need to run the DLL GMediaFactory function that returns the factory
		fptr func = reinterpret_cast<fptr>(reinterpret_cast<void*>(maker));
		
		return func();
	}

};


#endif
