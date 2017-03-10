// splash
#include "gsplash.h"

// qt
#include <QApplication>

GSplash::GSplash(GOptions* gopts, bool g)
{
	gui    = g;
	header = gopts->getString("header");

	if(gui) {
		vector<string> splashInfo = gopts->getStringVectorValue("splashPic");
		string picLocation = ".";
		string picName     = splashInfo[1];

		if(getenv(splashInfo[0].c_str()) != NULL) {
			picLocation = (string) getenv(splashInfo[0].c_str());
		}

		string filename = picLocation + "/" + picName;

		// pixmap is empty if filename doesn't exist.
		QPixmap pixmap(filename.c_str());

		splash = new QSplashScreen(pixmap);
		splash->show();

		qApp->processEvents();
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

	optionsMap["splashPic"] = GOption("Splash Screen Picture", "SPLASH gemcArchitecture.png", "gui");
	optionsMap["splashPic"].addHelp("The arguments are:\n");
	optionsMap["splashPic"].addHelp("1. env. variable location of the picture file\n");
	optionsMap["splashPic"].addHelp("2. picture file\n");

	// prints ">" for every message on splash or on screen
	optionsMap["header"] = GOption("Message header to display on (splash)screen", " > ", "init");

	return optionsMap;
}
