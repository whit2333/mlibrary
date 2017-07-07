#ifndef  DISPLAYUI_H
#define  DISPLAYUI_H 1

// qt
#include <QtWidgets>

// mlibrary
#include "goptions.h"

class DisplayUI: public QTabWidget {

public:
	DisplayUI(GOptions* gopt, QWidget* parent = Q_NULLPTR);

public:
	// DisplayUI options
	static map<string, GOption> defineOptions();

};


#endif
