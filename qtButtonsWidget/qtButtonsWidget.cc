#include "qtButtonsWidget.h"

#include <iostream>

// returns icon depending on state
QIcon ButtonInfo::buttonForState(int state)
{

	string bname = buttonName;

	if(state == 1) bname += "_norma.png";
	if(state == 2) bname += "_hover.png";
	if(state == 3) bname += "_curre.png";

	QFileInfo checkFile(QString(bname.c_str()));

	// check if file exists and if yes: Is it really a file and no directory?
	if (checkFile.exists() && checkFile.isFile()) {
		return QIcon(QString(bname.c_str()));
	}
	
	return QIcon();
}

ButtonInfo::ButtonInfo(string bname, string btext)  : buttonName(bname)
{
	thisButton = new QListWidgetItem();

	// default state is normal
	thisButton->setIcon(buttonForState(1));
//	thisButton->setText(tr(btext.c_str()));

	thisButton->setFlags( Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}



QtButtonsWidget::QtButtonsWidget(double h, double v, map<string, string> bdesc, QWidget *parent) : QWidget(parent)
{
	static int distanceToMargin = 10;

	buttons.clear();
	for(auto &b : bdesc) {
		buttons.push_back(new ButtonInfo(b.first, b.second));
	}

	buttonsWidget = new QListWidget;
	buttonsWidget->setViewMode(QListView::IconMode);
	buttonsWidget->setIconSize(QSize(h, v));
	buttonsWidget->setMovement(QListView::Static);
	buttonsWidget->setMouseTracking(1);
//	buttonsWidget->setSpacing(2);

	for(auto &b : buttons) {
		buttonsWidget->addItem(b->thisButton);
	}

	// maybe call from mother
//	buttonsWidget->setCurrentRow(1);
	connect(buttonsWidget,	SIGNAL(itemEntered(QListWidgetItem *)), this, SLOT(buttonWasEntered(QListWidgetItem *)) );
	connect(buttonsWidget,	SIGNAL(itemPressed(QListWidgetItem *)), this, SLOT(buttonWasPressed(QListWidgetItem *)) );


	QVBoxLayout *layout = new QVBoxLayout;
	layout->setContentsMargins(0, 0, 0, 0);
	layout->addWidget(buttonsWidget);

	setLayout(layout);

	//setGeometry(0, 0, h+10, v*buttons.size());


	// icon container sizes
	// depends on the OS
	// on linux platformName returns xcb
	// see also QGuiApplication Class, property platformName
//	if( QGuiApplication::platformName().toStdString() == "cocoa")
//	buttonsWidget->setFixedSize(76, 600);
//	else
//	buttonsWidget->setFixedSize(74, 620);

	setFixedSize(h+distanceToMargin, v*buttons.size());
}

void QtButtonsWidget::buttonWasEntered(QListWidgetItem* item)
{
	for(int i=0; i<buttonsWidget->count(); i++)
		buttonsWidget->item(i)->setIcon(buttons[i]->buttonForState(1));

	// starts at 0
	int index = buttonsWidget->currentRow();

	item->setIcon(buttons[index]->buttonForState(3));
}







