#include "gruns.h"

map<string, GOption> GRuns::defineOptions()
{
	map<string, GOption> optionsMap;
	
	// by default, do not process any event
	optionsMap["n"]     = GOption("Number of events to process", 0, "run");
	optionsMap["runno"] = GOption("Use this run number", 1, "run");
	
	optionsMap["runWeightsFile"] = GOption("Text filename with run list and weights", "na", "run");
	optionsMap["runWeightsFile"].addHelp("The text file must have two columns, run# and weight.\n");
	optionsMap["runWeightsFile"].addHelp("For example a \"weights.txt\" file that contains:\n");
	optionsMap["runWeightsFile"].addHelp("11 0.1\n");
	optionsMap["runWeightsFile"].addHelp("12 0.7\n");
	optionsMap["runWeightsFile"].addHelp("13 0.2\n");
	optionsMap["runWeightsFile"].addHelp("will simulate 10% of events with run number 11 conditions, 70% for run 12 and 20% for run 13.\n");
	
	optionsMap["grunv"] = GOption("GRuns Verbosity", 0, "run");
	optionsMap["grunv"].addHelp("Possible values:\n");
	optionsMap["grunv"].addHelp(GVERBOSITY_SILENT_D);
	optionsMap["grunv"].addHelp(GVERBOSITY_SUMMARY_D);
	optionsMap["grunv"].addHelp(GVERBOSITY_DETAILS_D);
	optionsMap["grunv"].addHelp(GVERBOSITY_ALL_D);
	
	optionsMap["nEventsBuffer"] = GOption("Write to disk every nEventsBuffer", 1000, "run");

	return optionsMap;
}

