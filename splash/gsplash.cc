// splash
#include "gsplash.h"

// qt
#include <QApplication>

GSplash::GSplash(GOptions* gopts)
{
	gui    = gopts->getBoolValue("gui");
	header = gopts->getValue("header");

	if(gui) {
		vector<string> splashInfo = gopts->getValues("splashPic");
		string picLocation = splashInfo[0];
		string picName     = splashInfo[1];

		if(getenv(picLocation.c_str()) == NULL) {
			cout << "  !! Warning: <" << picLocation << "> environment variable not defined." << endl;
			splash = NULL;
		} else {
			
			string filename = (string) getenv(picLocation.c_str()) + "/" + picName;

			QPixmap pixmap(filename.c_str());

			splash = new QSplashScreen(pixmap);
			splash->show();
			
			qApp->processEvents();
		}
	}
}

// prints a message on the splash if interactive
// otherwise re-direct to screen
void GSplash::message(string msg)
{
	if(gui) {
		if(splash != NULL)
			splash->showMessage(msg.c_str(),  Qt::AlignLeft,  Qt::white );

		qApp->processEvents();
	}
	else
		cout << header << msg << endl;

}

GSplash::~GSplash()
{
	if(gui)
		if(splash != NULL)
			delete splash ;
}


map<string, GOption> GSplash::defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["splashPic"] = GOption("Splash Screen Picture", "GEMC gemcArchitecture.png", "gui");
	optionsMap["splashPic"].addHelp("The arguments are:\n");
	optionsMap["splashPic"].addHelp("1. env. variable location of the picture file\n");
	optionsMap["splashPic"].addHelp("2. picture file\n");

	optionsMap["gui"] = GOption("Use the QT interface", 1, "gui");
	optionsMap["gui"].addHelp("Possible choices are:\n");
	optionsMap["gui"].addHelp("0: run the program in batch mode\n");
	optionsMap["gui"].addHelp("1. run the program in interactive mode\n");

	optionsMap["header"] = GOption("Message to display on (splash)screen", " > ", "init");

	return optionsMap;
}
