/// \file example.cc

// example on how to use the gruns framework library

// gruns
#include "gruns.h"


map<string, GOption> defineOptions()
{
	map<string, GOption> optionsMap;
	optionsMap += GRuns::defineOptions();
	return optionsMap;
}



//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	cout << " Usage example: example -n=1000 -runWeightsFile=runWeights.txt -grunv=3" << endl;

	GOptions *gopts = new GOptions(argc, argv, defineOptions(), 1);

	GRuns *gruns = new GRuns(gopts);


	return 1;
}


