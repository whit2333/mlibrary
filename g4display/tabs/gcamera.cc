// g4display
#include "gcamera.h"


GCamera::GCamera(GOptions* gopt, QWidget* parent) : QWidget(parent)
{

	// Camera Direction Group
	// ----------------------
	cameraTheta = new QDial();
	cameraTheta->setRange(0, 180);
	cameraTheta->setSingleStep(1);
	cameraTheta->setNotchesVisible(true);
	cameraTheta->setWrapping(true);



	cameraPhi = new QDial();
	cameraPhi->setRange(0, 360);
	cameraPhi->setSingleStep(1);
	cameraPhi->setWrapping(true);
	cameraPhi->setNotchesVisible(true);

	QHBoxLayout *camDirectionLayout = new QHBoxLayout;
	camDirectionLayout->addWidget(cameraTheta);
	camDirectionLayout->addSpacing(20);
	camDirectionLayout->addWidget(cameraPhi);

	QGroupBox *anglesGroup = new QGroupBox(tr("Camera Direction"));
	anglesGroup->setLayout(camDirectionLayout);





	// all layouts together
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(anglesGroup);
	setLayout(mainLayout);


}
