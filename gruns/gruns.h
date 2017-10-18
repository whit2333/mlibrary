#ifndef GRUNS_H
#define GRUNS_H 1

// options
#include "goptions.h"

// mlibrary
#include "gdynamic.h"

// geant4
#include "G4UImanager.hh"

#define GRUNLOGMSGITEM  " ■"
#define GRUNERRMSGITEM  " ■"

class GRuns {

public:
	GRuns(GOptions* gopt, map<string, GDynamic*> *gDigi);

	// gruns options
	static map<string, GOption> defineOptions();

	// public api
	map<int, int> getRunEvents() {return runEvents;}
	
	int getCurrentRun() {return listOfRuns[runIndex];}
	
	// increase run index
	void setNextRun() {runIndex++;}

	// sums number of events across all runs
	int getTotalNumberOfEvents();
	
	// this will:
	// initiate all available gdynamic plugins for each run
	// run beamOn for each run
	// log on screen infos if enough verbosity
	int processEvents();
	
private:
	int verbosity;

	// map of runs with weights as coming from the file
	map<int, double> runWeights;

	// map with numnber of events for each run, based on weight map
	map<int, int> runEvents;
	
	vector<int> listOfRuns;

	// fill the number of events map
	void distributeEvents(int neventsToProcess);

	void printRunsDetails(int neventsToProcess);
	
	int runIndex;

	map<string, GDynamic*> *gDigitizationGlobal;

	// show digitization constants and parameters
	void showDigitizationParameters(string system, vector<string> digiConstants, vector<string> digiPars);
	
};

#endif
