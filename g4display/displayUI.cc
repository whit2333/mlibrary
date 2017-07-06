// g4display
#include "displayUI.h"
#include "tabs/gcamera.h"
#include "tabs/gslice.h"

DisplayUI::DisplayUI(GOptions* gopt, QWidget* parent) : QTabWidget(parent)
{
	setStyleSheet("QTabBar::tab       { background-color: #ACB6B6;}"
				  "QTabBar::tab:focus { color: #000011; }");

	addTab(new GCamera(gopt, this), "Camera");
	addTab(new GSlice(gopt, this),  "View Slice");
	addTab(new QWidget(),"Display Options");
}
