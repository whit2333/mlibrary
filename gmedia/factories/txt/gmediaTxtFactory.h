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
	// open and close the output media
	bool openConnection();
	bool closeConnection();

	// start and end each event
	bool startEvent();
	bool endEvent();
	
	// write the header
	bool publishHeader(GHeader gh);

	// write digitized observables
	bool publishDetectorDigiObservables(GDetectorObservables *detectorHits);
	
	// write true observables
	bool publishDetectorTrueObservables(GDetectorObservables *detectorHits);
	
	
private:
	// utility function to write observable
	// PRAGMA TODO: check if this is feasible for all output plugins. In case, make it virtual
	void writeObservables(GObservables* observableAtIndex, int index);
	
private:
	ofstream *ofile;
};



#endif // GMEDIATXTFACTORY_H
