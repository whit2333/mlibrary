// splash
#include "gsplash.h"

// qt
#include <QApplication>

/*! \fn GSplash::GSplash(GOptions* gopts, bool g)

 class constructor

 \param gopts GOptions can come from this library or user can define new ones
 \param g boolean to set gui (true) or batch mode (false)

 */
GSplash::GSplash(GOptions* gopts, bool g)
{
	gui    = g;
	header = gopts->getString("header");

	if(gui) {
		vector<string> splashInfo = gopts->getStringVectorValue("splashPic");

		string picLocation = ".";
		string picName     = splashInfo[0];

		// optional second argument
		if(splashInfo.size() == 2) {
			if(getenv(splashInfo[0].c_str()) != NULL) {
				picLocation = (string) getenv(splashInfo[0].c_str());
			}
		}

		string filename = picLocation + "/" + picName;

		// pixmap is empty if filename doesn't exist.
		QPixmap pixmap(filename.c_str());

		splash = new QSplashScreen(pixmap);
		splash->show();

		qApp->processEvents();
	}
}

/*! \fn GSplash::message(string msg)

prints a message on the splash if interactive
otherwise re-direct to screen

 \param msg log to be displayed

 */
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

/*! \fn GSplash::~GSplash()

  deletes splash if existing

*/
GSplash::~GSplash()

{
	if(gui)
		if(splash != NULL)
			delete splash ;
}


/*! \fn map<string, GOption> GSplash::defineOptions()

 \return the class options - users should overwrite these

 */
map<string, GOption> GSplash::defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["splashPic"] = GOption("Splash Screen Picture", "gemcArchitecture.png SPLASH", "gui");
	optionsMap["splashPic"].addHelp("The arguments are:\n");
	optionsMap["splashPic"].addHelp("1. env. variable location of the picture file\n");
	optionsMap["splashPic"].addHelp("2. picture file\n");

	// prints ">" for every message on splash or on screen
	optionsMap["header"] = GOption("Message header to display on (splash)screen", " > ", "init");

	return optionsMap;
}
