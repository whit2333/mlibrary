/// \file example.cc

// example on how to use the options

// options
#include "options.h"

// c++
#include "iostream"
using namespace std;


class myOptions : public GOptions {
	using GOptions::GOptions;

	void defineOptions();
};

void myOptions::defineOptions()
{
	optionsMap["geometry"]      = GOption("Window Geometry", "1400x1200");
	optionsMap["timeWindow"]    = GOption("Defines the Time Window", 100, "time");
	optionsMap["interpolation"] = GOption("Interpolation algorithm", "linear", "process");
	optionsMap["interpolation"].addHelp("Possible choices are:\n");
	optionsMap["interpolation"].addHelp("- linear\n");
	optionsMap["interpolation"].addHelp("- none (no interpolation)\n");
}

//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	
	myOptions *gopts = new myOptions(argc, argv, 1);

	cout << " example: The option interpolation is set at: " << gopts->getOption("interpolation").getValue() << endl;
	cout << " example: Interpolation Option: " << gopts->getOption("interpolation") << endl;

	return 1;

}

