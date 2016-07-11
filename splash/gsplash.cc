// splash
#include "gsplash.h"

// qt
#include <QApplication>

// c++
//#include <cstdlib>
//using namespace std;

GSplash::GSplash(GOptions* gopts)
{
	qt     = gopts->getOption("gui").getBoolValue();
	header = gopts->getOption("header").getValue();

	cout << " ASD " << qt << " " <<  gopts->getOption("gui").getValue() << endl;

	if(qt) {
		vector<string> splashInfo = gopts->getOption("splashPic").getValues();
		string picLocation = splashInfo[0];
		string picName     = splashInfo[1];

		if(getenv(picLocation.c_str()) == NULL) {
			cout << "  !! Error: <" << picLocation << "> environment variable not defined." << endl;
		} else {
			
			string filename = ":" + (string) getenv(picLocation.c_str()) + picName;
			gsplashPic = new QPixmap(filename.c_str());
			gsplash    = new QSplashScreen(*gsplashPic);

			QFont sansFont("Helvetica", 10);
			gsplash->setFont(sansFont);

			gsplash->show();
			qApp->processEvents();
		}


	}

}
