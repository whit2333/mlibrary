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