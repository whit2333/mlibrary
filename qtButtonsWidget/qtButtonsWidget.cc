#include "qtButtonsWidget.h"

#include <iostream>


QIcon buttonInfo::getIconForState(int state)
{
	switch(state) {
		case 1: return *(iconNorma); break;
		case 2: return *(iconHover); break;
		case 3: return *(iconCurre); break;
	}
	return *(iconNorma);
}

QString buttonInfo::doesIconExist(string name)
{
	QFileInfo checkFile(QString(name.c_str()));


	// check if file exists and if yes: Is it really a file and no directory?
	if (checkFile.exists() && checkFile.isFile()) {

		cout << " yes " << name.c_str() << endl;

		return QString(name.c_str());
	} else {
		cout << " no " << name.c_str() << endl;
		return QString("notAvailable.png");
	}
}

buttonInfo::buttonInfo(string bname, string btext)
{
	iconNorma = new QIcon(doesIconExist(bname + "_norma.png"));
	iconHover = new QIcon(doesIconExist(bname + "_hover.png"));
	iconCurre = new QIcon(doesIconExist(bname + "_curre.png"));

	thisButton = new QPushButton();
	thisButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//	QStateMachine *machine = new QStateMachine();

	stateHover = new QState();
	stateNorma = new QState();
	stateCurre = new QState();

	stateNorma->assignProperty(thisButton, "icon", getIconForState(1));
	stateHover->assignProperty(thisButton, "icon", getIconForState(2));
	stateCurre->assignProperty(thisButton, "icon", getIconForState(3));

	stateNorma->assignProperty(thisButton, "text", (btext + "Normal").c_str());
	stateHover->assignProperty(thisButton, "text", (btext + "Hover").c_str());
	stateHover->assignProperty(thisButton, "text", (btext + "Selected").c_str());

}



QtButtonsWidget::QtButtonsWidget(double h, double v, map<string, string> bdesc, QWidget *parent)
: QWidget(parent), buttonsHSize(h), buttonsVSize(v)
{

	QStateMachine *machine = new QStateMachine(this);


	buttons.clear();
	for(auto &b : bdesc) {

		cout << b.first << endl;

		buttonInfo *thisButton = new buttonInfo(b.first, b.second);
		buttons.push_back(thisButton);

		machine->addState(thisButton->stateHover);
		machine->addState(thisButton->stateNorma);
		machine->addState(thisButton->stateCurre);

		QEventTransition *enterTransition = new QEventTransition(thisButton->thisButton, QEvent::Enter);
		QEventTransition *leaveTransition = new QEventTransition(thisButton->thisButton, QEvent::Leave);

		leaveTransition->setTargetState(thisButton->stateNorma);
		enterTransition->setTargetState(thisButton->stateHover);

		thisButton->stateNorma->addTransition(enterTransition);
		thisButton->stateHover->addTransition(leaveTransition);

		machine->setInitialState(thisButton->stateNorma);

	}


	machine->start();


	QVBoxLayout *layout = new QVBoxLayout;

	for(auto &b : buttons) {
		layout->addWidget(b->thisButton);
	}

//	layout->setContentsMargins(0, 0, h, v*buttons.size());
	layout->setContentsMargins(0, 0, 0, 0);
	setLayout(layout);
	
	
}
