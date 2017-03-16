// detectorElement
#include "detectorElement.h"

// geant4
#include "G4VSolid.hh"
#include "G4Box.hh"


int DetectorElement::buildSolid(int verbosity, string catchName, map<string, DetectorElement*> *detectorsMap)
{
	// cad, gdml obects will not be built
	if(factory.find("gdml") != string::npos) return 0;
	if(factory.find("cad")  != string::npos) return 0;

	bool verbose = isVerbose(verbosity, catchName);

	int built = 0;
	// delete object if exists already
	if(solidVolume) delete solidVolume;



	// the order of these objects is the same as on the geant4 website
	// https://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/ForApplicationDeveloper/html/ch04.html

	if(type == "G4Box") {
		if(dimensions.size() != 3) {
			cout << " !! Fatal Error: the number of dimensions for " << name
			     << " is " << dimensions.size() <<  ":" << endl;
			for(unsigned int i=0; i<dimensions.size(); i++) {
				cout << "      dimension " << i + 1 << ": " <<  dimensions[i] << endl;
			}
			cout << "      This does not match a G4Box. Exiting" << endl << endl;
			exit(0);
		}

		// checking BOX dimensions
		for(unsigned int i=0; i<dimensions.size(); i++)
			if(dimensions[i] == 0)
			cout <<   "   !!! Warning: BOX has one side null!" << endl;

		solidVolume = new G4Box(name,             ///< name
						   dimensions[0],    ///< half length in X
						   dimensions[1],    ///< half length in Y
						   dimensions[2]);   ///< half length in Z

		built = 1;
	}


	return built;
}
