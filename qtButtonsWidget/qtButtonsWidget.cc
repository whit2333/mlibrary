#include "qtButtonsWidget.h"



QString buttonInfo::doesIconExist(string name)
{

	return QString("notAvailable.png");
}

buttonInfo::buttonInfo(string bname, string btext)
{
	iconHover = QIcon(doesIconExist(bname + "_hover.png"));
	iconNorma = QIcon(doesIconExist(bname + "_norma.png"));
	iconCurre = QIcon(doesIconExist(bname + "_curre.png"));

	thisButton = new QPushButton();
	thisButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	QStateMachine *machine = new QStateMachine();

	QState *stateHover = new QState();
	QState *stateNorma = new QState();
	QState *stateCurre = new QState();

	stateHover->assignProperty(thisButton, "icon", getIconForState(1));
	stateNorma->assignProperty(thisButton, "icon", getIconForState(2));
	stateCurre->assignProperty(thisButton, "icon", getIconForState(3));

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
		buttons.push_back(buttonInfo(b.first, b.second));
	}


	QVBoxLayout *layout = new QVBoxLayout;

	for(auto &b : buttons) {
		layout->addWidget(b.thisButton);
	}

//	layout->setContentsMargins(0, 0, h, v*buttons.size());
	layout->setContentsMargins(-10, -10, 0, 0);
	setLayout(layout);
	
	
}
