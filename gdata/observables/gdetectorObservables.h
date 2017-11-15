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
	}
	
	// when adding an observale we can clear its name and description and add them
	// to the container class: saving memory, we dont need a description for every hit
	void addDetectorObservables(GObservables *observables) {
		
		if(!(observables->getDescriptionAssigned())) {
			observableName = observables->getName();
			observableDesc = observables->getDesc();
			observables->clearNamesAndDescriptions();
		}
		
		detectorObservables.push_back(observables);
	}
	
	// api to get data
	string getName() {return detectorSDName;}
	vector<string> getObservableName() {return observableName;}
	vector<string> getObservableDesc() {return observableDesc;}
	vector<string> getTrueInfoName()   {return trueInfoName;}
	vector<string> getTrueInfoDesc()   {return trueInfoDesc;}

	// observables api
	vector<GObservables*> getDObservables()       {return detectorObservables;}
	vector<GObservables*> getDObservablesPulses() {return detectorObservablePulses;}

	// true infos api
	vector<GObservables*> getTObservables()       {return detectorTrueInfos;}
	vector<GObservables*> getTObservablesPulses() {return detectorObservablePulses;}

private:
	
	// detector SD name, passed here to it can be published
	string detectorSDName;
	vector<string> observableName;
	vector<string> observableDesc;
	vector<string> trueInfoName;
	vector<string> trueInfoDesc;

	// observables: accumulating over hits
	vector<GObservables*> detectorObservables;       // one instance of an observable / hit
	vector<GObservables*> detectorObservablePulses;  // multiple instances of an observable / hit

	// true infos: accumulating over hits
	vector<GObservables*> detectorTrueInfos;       // one instance of true infos / hit
	vector<GObservables*> detectorTrueInfosPulses; // multiple instances of true infos / hit
	
};
#endif
