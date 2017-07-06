#ifndef  DISPLAYUI_H
#define  DISPLAYUI_H 1

// qt
#include <QtWidgets>

// mlibrary
#include "goptions.h"

class DisplayUI: public QTabWidget {

public:
	DisplayUI(GOptions* gopt, QWidget* parent = 0);

public:
	// DisplayUI options
	static map<string, GOption> defineOptions();

};


#endif
