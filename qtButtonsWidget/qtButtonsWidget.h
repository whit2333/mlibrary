#ifndef  QTBUTTONSWIDGET_H
#define  QTBUTTONSWIDGET_H

// c++
#include <string>
#include <vector>
using namespace std;

// qt
#include <QtWidgets>

struct buttonInfo {

	buttonInfo(string h, string n, string c) : iconHover(h), iconNormal(n), iconCurrent(c) {}

private:
	string iconHover;
	string iconNormal;
	string iconCurrent;
};

struct buttonsModel {

	buttonsModel(double h, double v, vector<buttonInfo> b) : buttonsHSize(h), buttonsVSize(v), buttons(b) {}

private:
	double buttonsHSize;
	double buttonsVSize;

	vector<buttonInfo> buttons;

};


class QtButtonsWidget : public QWidget
{
public:
	QtButtonsWidget(buttonsModel m, QWidget *parent = 0) : QWidget(parent), model(m)
	{
	}


private:
	buttonsModel model;

};


#endif
