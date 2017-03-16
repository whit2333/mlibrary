// detectorElement
#include "detectorElement.h"

// geant4
#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"


void DetectorElement::buildSolid(map<string, DetectorElement*> *detectorsMap)
{
	// cad, gdml obects will not be built
	if(factory.find("gdml") != string::npos) return;
	if(factory.find("cad")  != string::npos) return;

	// how can it exist already?
	if(solidVolume && solidBuilt == 0) {
		cout << " ! Warning: a g4 solid exists but solidBuild is 0.";
	}
	if(solidVolume == NULL && solidBuilt == 1) {
		cout << " ! Warning: a g4 solid does not exists but solidBuild is 1.";
	}
	// nothing to do
	if(solidBuilt == 1) return;


	solidBuilt = -1; // error if this will never change

	// check dimensions
	checkG4SolidDimensions();

	// the order of these objects is the same as on the geant4 website
	// https://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/ForApplicationDeveloper/html/ch04.html

	if(type == "G4Box") {

		// checking that G4Box does not have null dimensions
		for(unsigned int i=0; i<dimensions.size(); i++) {
			if(dimensions[i] == 0) {
				cout <<   " ! Warning: BOX has one side null!" << endl;
			}
		}

		solidVolume = new G4Box(name,             ///< name
								dimensions[0],    ///< half length in X
								dimensions[1],    ///< half length in Y
								dimensions[2]);   ///< half length in Z

		solidBuilt = 1;
	} else 	if(type == "G4Tubs") {
		solidVolume = new G4Tubs(name,            ///< name
								 dimensions[0],   ///< Inner radius
								 dimensions[1],   ///< Outer radius
								 dimensions[2],   ///< Half length in z
								 dimensions[3],   ///< The starting phi angle
								 dimensions[4]);  ///< Delta Phi angle of the segment
		solidBuilt = 1;
	}

	if(solidBuilt == -1) {
		cout << " !!! error: solid >" << type << "< not recognized. Exiting." << endl;
		exit(0);
	}

	return;
}
