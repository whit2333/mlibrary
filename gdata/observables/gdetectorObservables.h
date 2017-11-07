#ifndef  GDETECTOR_DATA_H
#define  GDETECTOR_DATA_H  1

// gdata
#include "observables/gobservables.h"

// PRAGMA TODO: decide if we have a pointer object, how to copy it, etc.

// detector observales, all hits are accumulated here for one detector
class GDetectorObservables
{
public:
	GDetectorObservables() {
		detectorObservables.clear();
	}
	void addDetectorObservables(GObservables *observables) {
		detectorObservables.push_back(observables);
	}
	
private:
	// accumulating over hits
	vector<GObservables*> detectorObservables;  // one observable / hit
	
};
#endif
