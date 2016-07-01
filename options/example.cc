// example on how to use the options

// options
#include "options.h"

// c++
#include "iostream"
using namespace std;


void GOptions::defineOptions()
{

	optionsMap["geometry"]         = GOption("Window Geometry", "1400x1200");
	optionsMap["INTEGRATEDRAW"]    = GOption("Store Time Window Integrated True Information", "na", "hit");
	optionsMap["INTEGRATEDRAW"].addHelp("- \"beamp\"  aligns z axis to the beam directions specified by BEAM_P.\n");
	optionsMap["INTEGRATEDRAW"].addHelp("- \"custom, theta*unit, phi*unit\" aligns z axis to a custom direction, changes BEAM_P reference frame.");

	optionsMap["SAVE_ALL_MOTHERS"] = GOption("Save particle hierarchy", 1.0, "run");
	optionsMap["SAVE_ALL_MOTHERS"] = GOption("Save particle hierarchy", 1.0, "run");
	optionsMap["FIELD_PROPERTIES"] = GOption("Sets Field Properties", "na", "run");

}

int main(int argc, char* argv[])
{
	
	GOptions *gopts = new GOptions(argc, argv, 1);


	cout << " Hello World" << endl;



	return 1;

}

