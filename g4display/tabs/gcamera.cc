// g4display
#include "gcamera.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

// c++
#include <string>
using namespace std;

GCamera::GCamera(GOptions* gopt, QWidget* parent) : QWidget(parent)
{
	g4uim = G4UImanager::GetUIpointer();
	double thetaValue = 0;
	double phiValue   = 0;

	vector<double> camDirections = getG4NumbersFromString(gopt->getString("cameraAngles"));

	if(camDirections.size() == 2) {
		thetaValue = camDirections[0];
		phiValue  = camDirections[1];
	}


	// Camera Direction Group
	// ----------------------

	// THETA
	cameraTheta = new QSlider(Qt::Horizontal);
	cameraTheta->setRange(0, 180);
	cameraTheta->setSingleStep(1);
	cameraTheta->setValue(thetaValue);
	QLabel *cameraThetaLabel = new QLabel(tr("θ"));

	QHBoxLayout *cameraThetaLayout = new QHBoxLayout;
	cameraThetaLayout->addWidget(cameraThetaLabel);
	cameraThetaLayout->addWidget(cameraTheta);

	// PHI
	cameraPhi = new  QSlider(Qt::Horizontal);
	cameraPhi->setRange(0, 360);
	cameraPhi->setSingleStep(1);
	cameraPhi->setValue(phiValue);
	QLabel *cameraPhiLabel = new QLabel(tr("ɸ"));

	QHBoxLayout *cameraPhiLayout = new QHBoxLayout;
	cameraPhiLayout->addWidget(cameraPhiLabel);
	cameraPhiLayout->addWidget(cameraPhi);

	// Combine THETA and PHI
	QVBoxLayout *cameraDirectionLayout = new QVBoxLayout;
	cameraDirectionLayout->addLayout(cameraThetaLayout);
	cameraDirectionLayout->addSpacing(12);
	cameraDirectionLayout->addLayout(cameraPhiLayout);

	QGroupBox *anglesGroup = new QGroupBox(tr("Camera Direction"));
	anglesGroup->setLayout(cameraDirectionLayout);

	connect ( cameraTheta, SIGNAL( valueChanged(int) ), this, SLOT( changeCameraDirection() ) );
	connect ( cameraPhi,   SIGNAL( valueChanged(int) ), this, SLOT( changeCameraDirection() ) );

	// Camera and background colors
	// ----------------------------


	// all layouts together
	// --------------------
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addWidget(anglesGroup);
	setLayout(mainLayout);
}

void GCamera::changeCameraDirection()
{
	string command = "/vis/viewer/set/lightsThetaPhi " + to_string(cameraTheta->value()) + " " + to_string(cameraPhi->value());
	g4uim->ApplyCommand(command);

}


