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
	// 1. "name_norma.png"
	// 2. "name_hover.png"
	// 3. "name_curre.png"
	ButtonInfo(string bname, string btext);

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
	QtButtonsWidget(double h, double v, map<string, string> bdesc, QWidget *parent = 0);

private:
	QListWidget *buttonsWidget;

	vector<ButtonInfo*> buttons;

private slots:
	void buttonWasEntered(QListWidgetItem*);
	void buttonWasPressed(QListWidgetItem*);
};


#endif
