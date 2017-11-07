#ifndef  GDETECTOR_DATA_H
#define  GDETECTOR_DATA_H  1

// gdata
#include "observables/gobservables.h"

// detector observales, hits are accumulated here
class GDetectorObservables
{
public:
	GDetectorObservables() {
		detectorData.clear();
	}
	void addDetectorData(GObservables *data) {
		detectorData.push_back(data);
	}
	
private:
	// accumulating over hits
	vector<GObservables*> detectorData;  // one observable / hit
	
};
#endif
