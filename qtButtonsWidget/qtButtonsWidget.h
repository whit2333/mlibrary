#ifndef  QTBUTTONSWIDGET_H
#define  QTBUTTONSWIDGET_H

// c++
#include <string>
#include <vector>
using namespace std;

// qt
#include <QtWidgets>

struct buttonInfo
{

	// a button name must have 3 xpm file:
	// 1. "name_hover.xpm"
	// 2. "name_norma.xpm"
	// 3. "name_curre.xpm"
	buttonInfo(string bname, string btext);
	
public:
	QPushButton *thisButton;

	QState *stateNorma;
	QState *stateHover;
	QState *stateCurre;

	QIcon getIconForState(int state);

	QIcon *iconNorma;
	QIcon *iconHover;
	QIcon *iconCurre;

private:
	QString doesIconExist(string name);
};



class QtButtonsWidget : public QWidget
{
public:
	QtButtonsWidget(double h, double v, map<string, string> bdesc, QWidget *parent = 0);

private:
	double buttonsHSize;
	double buttonsVSize;

	vector<buttonInfo*> buttons;

};


#endif
