/// \file example.cc

// example on how to use the splash framework library

// gsplash
#include "gsplash.h"



map<string, GOption> defineOptions()
{
	map<string, GOption> optionsMap;
	optionsMap += GSplash::defineOptions();
	return optionsMap;
}

// distinguishing between graphical and batch mode
QCoreApplication* createApplication(int &argc, char *argv[], bool gui)
{
	if(!gui)
		return new QCoreApplication(argc, argv);
	return new QApplication(argc, argv);
}

//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	GOptions *gopts = new GOptions(argc, argv, defineOptions(), 1);
	bool gui = gopts->getBoolValue("gui");

	createApplication(argc, argv, gui);

	GSplash gsplash(gopts);

	if(gui) {
		QMainWindow window;
		window.show();

		for(int i=0; i<1000000; i++)
			gsplash.message(to_string(i));

		gsplash.finish(&window);
		return qApp->exec();
	}

	return 1;
}

