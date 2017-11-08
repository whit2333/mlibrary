#ifndef  GMEDIA_H
#define  GMEDIA_H  1

// mlibrary
#include "gdata.h"
#include "gdl.h"

class GMedia
{

public:
	virtual ~GMedia() = default;

	// sets outputFileName and opens it
	bool setOutputName(string filename) {
		outputFileName = filename;
		return openConnection();
	}
	
	// calls below publishers one by one
	map<string, bool> publishData(vector<GEventData*> *runData);
	
	// public api to close connection
	virtual bool closeConnection() { return false;}


protected:
	string outputFileName;
	
	virtual bool openConnection()                            { return false;}
	virtual bool publishHeader(vector<GEventData*> *runData) { return false;}

public:

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
	
	
public:
	// GMedia options - defined in gmedia.cc
	static map<string, GOption> defineOptions();

};


#endif
