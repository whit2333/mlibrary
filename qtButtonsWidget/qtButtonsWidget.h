#ifndef  QTBUTTONSWIDGET_H
#define  QTBUTTONSWIDGET_H

// c++
#include <string>
#include <vector>
using namespace std;

// qt
#include <QtWidgets>

struct ButtonInfo
{
	// a button name must have 3 png files:
	// 1. "name_hover.png"
	// 2. "name_norma.png"
	// 3. "name_curre.png"
	ButtonInfo(string bname, string btext);
	
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

	vector<ButtonInfo*> buttons;

};


#endif
