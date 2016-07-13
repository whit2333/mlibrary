/// \file example.cc

// example on how to use the gruns framework library

// gruns
#include "gruns.h"


map<string, GOption> defineOptions()
{
	map<string, GOption> optionsMap;
	optionsMap["startEvent"] = GOption("Start Event Number", 1, "run");
	optionsMap["runno"]      = GOption("Run Number", 1, "run");

	// by default, do not process any event
	optionsMap["N"]          = GOption("Number of events to process", 0, "run");

	optionsMap["runWeightsFile"] = GOption("Text filename with run list and weights", "na", "run");
	optionsMap["runWeightsFile"].addHelp("The text file must have two columns, run# and weight.\n");
	optionsMap["runWeightsFile"].addHelp("For example:\n");
	optionsMap["runWeightsFile"].addHelp(" 11 0.1\n");
	optionsMap["runWeightsFile"].addHelp(" 12 0.7\n");
	optionsMap["runWeightsFile"].addHelp(" 13 0.2\n");
	optionsMap["runWeightsFile"].addHelp("Will simulate 10% of events with run number 11 conditions, 70% for run 12 and 20% for run 13.\n");


	return optionsMap;
}



//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	cout << " Usage example: example -N=1000 -runWeightsFile=runWeights.txt" << endl;

	GOptions *gopts = new GOptions(argc, argv, defineOptions(), 1);

	GRuns *gruns = new GRuns(gopts);

	cout << " Run number for event 100 is: <" << gruns->getRunNumber(100) << ">" << endl;

	return 1;
}


