.c_str()/// \file example.cc

// example on how to use the goptions framework library

// options
#include "goptions.h"


map<string, GOption> defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["geometry"]      = GOption("Window Geometry", "1400x1200");
	optionsMap["timeWindow"]    = GOption("Defines the Time Window", 100, "time");
	optionsMap["interpolation"] = GOption("Interpolation algorithm", "linear", "process");
	optionsMap["interpolation"].addHelp("Possible choices are:\n");
	optionsMap["interpolation"].addHelp("- linear\n");
	optionsMap["interpolation"].addHelp("- none (no interpolation)\n");

	return optionsMap;
}


//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	
	GOptions *gopts = new GOptions(argc, argv, defineOptions(), 1);

	cout << " example: The option interpolation is set at: " << gopts->getValue("interpolation") << endl;
	cout << " example: Interpolation Option: " << gopts->getOption("interpolation") << endl << endl;

	return 1;
}

