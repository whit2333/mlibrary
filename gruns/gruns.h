#ifndef GRUNS_H
#define GRUNS_H 1

// options
#include "goptions.h"

class GRuns {

public:
	GRuns(GOptions* gopt);

	// gruns options
	static map<string, GOption> defineOptions();

	// public api
	map<int, int> getRunEvents() {return runEvents;}
	
	int getCurrentRun() {return listOfRuns[runIndex];}
	void setNextRun() {runIndex++;}

private:

	// map of runs with weights as coming from the file
	map<int, double> runWeights;

	// map with numnber of events for each run, based on weight map
	map<int, int> runEvents;
	
	vector<int> listOfRuns;

	// fill the number of events map
	void distributeEvents(int neventsToProcess);

	void printRunsDetails(int neventsToProcess);
	
	int runIndex;
};

#endif
