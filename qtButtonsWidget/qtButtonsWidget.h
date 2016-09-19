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

	// a button name must have 3 png files:
	// 1. "name_hover.png"
	// 2. "name_norma.png"
	// 3. "name_curre.png"
	buttonInfo(string bname, string btext);
	
public:
	QPushButton *thisButton;

private:
	string doesIconExist(string name);

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
