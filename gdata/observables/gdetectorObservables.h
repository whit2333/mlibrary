#ifndef  GDETECTOR_DATA_H
#define  GDETECTOR_DATA_H  1

// gdata
#include "observables/gobservables.h"

// PRAGMA TODO: decide if we have a pointer object, how to copy it, etc.
// PRAGMA TODO: add "adc", "tcd", "fadc" ?

// detector observales, all hits are accumulated here for one detector
class GDetectorObservables
{
public:
	GDetectorObservables(string sdName) : detectorSDName(sdName) {
		detectorObservables.clear();
	}
	void addDetectorObservables(GObservables *observables) {
		detectorObservables.push_back(observables);
	}
	
	// api to get data
	string getName() {return detectorSDName;}
	vector<GObservables*> getDObservables()       {return detectorObservables;}
	vector<GObservables*> getDObservablesPulses() {return detectorObservablePulses;}

private:
	
	// detector SD name, passed here to it can be published
	string detectorSDName;
	
	// accumulating over hits
	vector<GObservables*> detectorObservables;       // one instance of an observable / hit
	vector<GObservables*> detectorObservablePulses;  // multiple instances of an observable / hit
};
#endif
