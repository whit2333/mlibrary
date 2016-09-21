/// \file example.cc

// example on how to use the qtButtonsWidget library

// text progress bar
#include "qtButtonsWidget.h"

// c++
#include <iostream>
using namespace std;

// qt
#include <QFileDialog>



//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	QApplication app(argc, argv);


	cout << argv[0] << endl;

	// the exampleResources.rcc is obtained with:
	// rcc -binary exampleResources.qrc -o exampleResources.rcc
	// it is needed in the executable dir in case it is compiled by xcode
	// scons on the other hand knows about it because the qt module
	// compiles exampleResources.qrc directly

	QFileInfo qrcFileInfoExecutable(argv[0]);
	QString rccPath = qrcFileInfoExecutable.absolutePath() + "/" + "exampleResources.rcc";
	QResource::registerResource(rccPath);

	map<string, string> bmodel;

	bmodel[":/images/firstButton"]  = "add monkey 1";
	bmodel[":/images/secondButton"] = "add monkey 2";
	bmodel[":/images/thidButton"]   = "add monkey 3";

	QtButtonsWidget window(128, 128, bmodel);
	window.show();

	return app.exec();

	return 1;
}

