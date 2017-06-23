// g4volume
#include "g4NativeSetupFactory.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

// geant4
#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"


bool G4NativeSetupFactory::buildSolid(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s)
{

	string vname = s->getName();

	// if the g4volume doesn't exist, create one and add it to the map
	G4Volume *thisG4Volume = nullptr;

	// check if g4s already exists
	if(g4s->find(vname) != g4s->end()) {
		thisG4Volume = (*g4s)[vname];
		// if the solid is already built, nothing to do
		if(thisG4Volume->getSolid() != nullptr) return true;
	} else {
		thisG4Volume = new G4Volume();
	}


	// the order of these objects is the same as on the geant4 website
	// https://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/ForApplicationDeveloper/html/ch04.html

	// check and get parameters
	vector<double> parameters = checkAndReturnParameters(s);

	string type = s->getType();

	if(type == "G4Box") {
		thisG4Volume->addSolid(new G4Box(vname,            ///< name
										 parameters[0],    ///< half length in X
										 parameters[1],    ///< half length in Y
										 parameters[2])    ///< half length in Z
							   );
		return true;
	} else 	if(type == "G4Tubs") {
		thisG4Volume->addSolid(new G4Tubs(vname,           ///< name
										  parameters[0],   ///< Inner radius
										  parameters[1],   ///< Outer radius
										  parameters[2],   ///< Half length in z
										  parameters[3],   ///< The starting phi angle
										  parameters[4])   ///< Delta Phi angle of the segment
							   );
		return true;
	}


	return false;
}





