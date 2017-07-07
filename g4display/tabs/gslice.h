#ifndef  GSLICE_H
#define  GSLICE_H 1

// qt
#include <QtWidgets>

// mlibrary
#include "goptions.h"

// geant4 headers
#include "G4UImanager.hh"

class GSlice: public QWidget {

public:
	GSlice(GOptions* gopt, QWidget* parent = Q_NULLPTR);

private:
	// geant4 UIManager
	G4UImanager  *g4uim;

};


#endif
