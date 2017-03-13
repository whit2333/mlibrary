#include "qtButtonsWidget.h"

#include <iostream>

// returns background stylesheet if file exist
string ButtonInfo::doesIconExist(string name)
{
	QFileInfo checkFile(QString(name.c_str()));

	// check if file exists and if yes: Is it really a file and no directory?
	if (checkFile.exists() && checkFile.isFile()) {
		return "background-image: url(" + name + ");";
	}
	
	return "";
}

ButtonInfo::ButtonInfo(string bname, string btext)
{

	thisButton = new QPushButton();
	thisButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QStateMachine *machine = new QStateMachine();

	QState *stateHover = new QState();
	QState *stateNorma = new QState();
	QState *stateCurre = new QState();

	stateNorma->assignProperty(thisButton, "styleSheet", doesIconExist(bname + "_norma.png").c_str());
	stateHover->assignProperty(thisButton, "styleSheet", doesIconExist(bname + "_hover.png").c_str());
	stateCurre->assignProperty(thisButton, "styleSheet", doesIconExist(bname + "_curre.png").c_str());

	QEventTransition *enterTransition = new QEventTransition(thisButton, QEvent::Enter);
	QEventTransition *leaveTransition = new QEventTransition(thisButton, QEvent::Leave);

	leaveTransition->setTargetState(stateNorma);
	enterTransition->setTargetState(stateHover);

	stateNorma->addTransition(enterTransition);
	stateHover->addTransition(leaveTransition);

	machine->addState(stateHover);
	machine->addState(stateNorma);
	machine->addState(stateCurre);

	machine->setInitialState(stateNorma);
	machine->start();

}



QtButtonsWidget::QtButtonsWidget(double h, double v, map<string, string> bdesc, QWidget *parent)
	: QWidget(parent), buttonsHSize(h), buttonsVSize(v)
{

	buttons.clear();
	for(auto &b : bdesc) {
		buttons.push_back(new ButtonInfo(b.first, b.second));
	}

	QVBoxLayout *layout = new QVBoxLayout;

	for(auto &b : buttons) {
		layout->addWidget(b->thisButton);
	}

	layout->setContentsMargins(0, 0, 0, 0);
	setLayout(layout);

	setGeometry(0, 0, h, v*buttons.size());
	
}




