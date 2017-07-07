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
	// a button name must have 2 png files:
	// 1. "name_1.png"
	// 2. "name_2.png"
	ButtonInfo(string icon);

public:
	QListWidgetItem *thisButton;
	QIcon buttonForState(int state);

private:
	string buttonName;
};



class QtButtonsWidget : public QWidget
{
	Q_OBJECT

public:
	QtButtonsWidget(double h, double v, vector<string> bicons, QWidget *parent = Q_NULLPTR);

private:
	QListWidget *buttonsWidget;

	vector<ButtonInfo*> buttons;

private slots:
	void buttonWasPressed(QListWidgetItem*);
};


#endif
