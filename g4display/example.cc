/// \file example.cc

// example on how to use the g4displa library and the displayUI widget

// g4display
#include "g4display.h"
#include "displayUI.h"

// qt
#include <QApplication>
#include <QMainWindow>

//! example of main declaring GOptions
int main(int argc, char* argv[])
{

	QApplication app(argc, argv);


	GOptions *gopts = new GOptions(argc, argv, G4Display::defineOptions(), 1);
	G4Display *g4Display = new G4Display(gopts);

	// main window
	QMainWindow *window = new QMainWindow();
	window->setWindowTitle(QString::fromUtf8("displayUI example"));
	window->resize(600, 800);


	DisplayUI *dUI = new DisplayUI(gopts, window);

	window->setCentralWidget(dUI);


	window->show();
	delete g4Display;

	return app.exec();

}

