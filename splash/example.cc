/// \file example.cc

// example on how to use the options framework library

// options
#include "gsplash.h"



map<string, GOption> defineOptions()
{
	map<string, GOption> optionsMap;
	optionsMap["splashPic"] = GOption("Splash Screen Picture", "GEMC gemcArchitecture.png", "gui");
	optionsMap["splashPic"].addHelp("The arguments are:\n");
	optionsMap["splashPic"].addHelp("1. env. variable location of the picture file\n");
	optionsMap["splashPic"].addHelp("2. picture file\n");

	optionsMap["gui"] = GOption("Use the QT interface", "0", "gui");
	optionsMap["gui"].addHelp("Possible choices are:\n");
	optionsMap["gui"].addHelp("0: run the program in batch mode\n");
	optionsMap["gui"].addHelp("1. run the program in interactive mode\n");

	optionsMap["header"] = GOption("Message to display on (splash)screen", " > ", "init");

	return optionsMap;
}

// distinguishing between graphical and batch mode
QCoreApplication* createApplication(int &argc, char *argv[], double use_gui)
{
	if(!use_gui)
		return new QCoreApplication(argc, argv);
	return new QApplication(argc, argv);
}

//! example of main declaring GOptions
int main(int argc, char* argv[])
{

	GOptions *gopts = new GOptions(argc, argv, defineOptions(), 1);


	
	QScopedPointer<QCoreApplication> app(createApplication(argc, argv, gopts->getOption("gui").getBoolValue()));

	GSplash gsplash(gopts);

	
	return 1;

}

