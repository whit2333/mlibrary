/// \file example.cc

// example on how to use the qtButtonsWidget library

// text progress bar
#include "qtButtonsWidget.h"

// c++
#include <iostream>
using namespace std;


//! example of main declaring GOptions
int main(int argc, char* argv[])
{



	QApplication app(argc, argv);


	map<string, string> bmodel;

	bmodel["monkey"] = "add monkey";

	QtButtonsWidget window(128, 128, bmodel);
	window.show();


	return app.exec();


	return 1;
}

