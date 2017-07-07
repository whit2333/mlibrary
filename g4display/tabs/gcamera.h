#ifndef  GCAMERA_H
#define  GCAMERA_H 1

// qt
#include <QtWidgets>

// mlibrary
#include "goptions.h"

// geant4 headers
#include "G4UImanager.hh"

class GCamera: public QWidget {

	// metaobject required for non-qt slots
	Q_OBJECT

public:
	GCamera(GOptions* gopt, QWidget* parent = Q_NULLPTR);


private:
	QSlider *cameraTheta;
	QSlider *cameraPhi;

	// geant4 UIManager
	G4UImanager  *g4uim;

private slots:
	void changeCameraDirection();

};


#endif
