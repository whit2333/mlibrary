#ifndef GMEDIATXTFACTORY_H
#define GMEDIATXTFACTORY_H 1

// gmedia
#include "gmedia.h"

#define GVARIABLEFLUSH "   "

class GMediaTxtFactory : public GMedia
{
public:
	GMediaTxtFactory() : ofile(nullptr) {}
	
private:
	bool openConnection();
	
	// one per event
	bool startEvent();
	bool endEvent();
	
	bool publishHeader(GHeader gh);

	// digitized observables
	bool publishDetectorDigiObservables(GDetectorObservables *detectorHits);
	// true observables
	bool publishDetectorTrueObservables(GDetectorObservables *detectorHits);
	
	bool closeConnection();
	
private:
	// utility function to write observable
	// PRAGMA TODO: check if this is feasible for all output plugins. In case, make it virtual
	void writeObservables(GObservables* observableAtIndex, int index);
	
private:
	ofstream *ofile;
};



#endif // GMEDIATXTFACTORY_H
