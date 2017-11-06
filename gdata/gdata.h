#ifndef  GDATA_H
#define  GDATA_H  1

// gdata
#include "observables/gobservables.h"

// c++
#include <vector>
#include <string>
using namespace std;

// mlibrary
#include "ghit.h"
#include "goptions.h"

// detector observales, hits are accumulated here
class GDetectorObservables
{
public:
	void addObservable();
	
private:
	// accumulating over hits
	vector<GObservables> integratedData;  // one observable / hit
	vector<GObservables> marksData;       // multiple observables / hit
	
};


class GEventData
{
private:
	// all detectors
	vector<GDetectorObservables> detectorsData;
	
	// PRAGMA TODO: headers, generators infos
	
	
public:
	// GSetup options - defined in utilities.cc
	static map<string, GOption> defineOptions();
	
};

#endif
