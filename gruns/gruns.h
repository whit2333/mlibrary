#ifndef GRUNS_H
#define GRUNS_H


// options
#include "goptions.h"

class GRuns {

public:
	GRuns(GOptions* gopt);

	//! gets the run number based on the event number 
	int getRunNumber(int n);

	bool isNew() {return isNewRun;}

	// gruns options
	static map<string, GOption> defineOptions();


private:

	// map of runs with weights as coming from the file
	map<int, double> runWeights;

	// map with numnber of events for each run, based on weight map
	map<int, int> runEvents;

	// fill the number of events map
	void distributeEvents(int n);

	// start from this event number
	int startEvent;

	bool isNewRun;

	//! by default there is only 1 weight,
	//! and the run number is defaultRunNumber for all events
	int defaultRunNumber;
	//! current run number
	int runNo;

	void printSummary(int neventsToProcess);

};



#endif
