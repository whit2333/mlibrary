// g4volume
#include "nativeVolumeFactory.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

// geant4
#include "G4VSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"


bool G4NativeSystemFactory::buildSolid(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s)
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




// check that the number of parameters matches the geant4 constructor
vector<double> G4NativeSystemFactory::checkAndReturnParameters(GVolume *s)
{

	// PRAGMA TODO
	// Check that the pars are not zero, for example:
	// checking that G4Box does not have null dimensions
	//	for(unsigned i=0; i<parameters.size(); i++) {
	//		if(getG4Number(parameters[i]) == 0) {
	//			cout <<   " !! Warning: G4Box has one side null!" << endl;
	//		}
	//	}


	set<int> possibleNumberOfParameters;
	string type = s->getType();
	string name = s->getName();

	vector<double> parameters = getG4NumbersFromStringVector(getStringVectorFromString(s->getParameters()));

	int actualNumberOfParameters = (int) parameters.size();

		 if(type == "G4Box")     possibleNumberOfParameters = {3};
	else if(type == "G4Tubs")    possibleNumberOfParameters = {5};
	else if(type == "G4CutTubs") possibleNumberOfParameters = {7};
	else if(type == "G4Cons")    possibleNumberOfParameters = {7};
	else if(type == "G4Para")    possibleNumberOfParameters = {6};
	else if(type == "G4Trd")     possibleNumberOfParameters = {5};
	else if(type == "G4Trap")    possibleNumberOfParameters = {4, 11};
	else if(type == "G4Sphere")  possibleNumberOfParameters = {6};
	else if(type == "G4Orb")     possibleNumberOfParameters = {1};
	else if(type == "G4Torus")   possibleNumberOfParameters = {5};

	// polycons are special
	else if(type == "G4Polycone" || type == "G4GenericPolycone")  {
		// the first constructor must have a number of pars multiple of 3
		// the second constructor must have a number of pars (-3) multiple of 2
		if(actualNumberOfParameters%3 !=0 && (actualNumberOfParameters - 3)%2 != 0) {
			cout << " !!! Fatal Error: the number of parameters in the constructor of " << name << ", " << type
			<< " is " << actualNumberOfParameters <<  ":" << s->getParameters() << endl;

			cout << "      This does not match a " << type <<". Exiting." << endl << endl;
			exit(99);
		} else {
			return parameters;
		}
	}

	// polyhedras are special
	else if(type == "G4Polyhedra") {
		// the first constructor must have a number of pars (-4) multiple of 3
		// the second constructor must have a number of pars (-4) multiple of 2
		if((actualNumberOfParameters - 4)%3 !=0 && (actualNumberOfParameters - 3)%2 != 0) {
			cout << " !!! Fatal Error: the number of parameters in the constructor of " << name << ", " << type
			<< " is " << actualNumberOfParameters <<  ":" << s->getParameters() << endl;

			cout << "      This does not match a " << type <<". Exiting." << endl << endl;
			exit(99);
		} else {
			return parameters;
		}

	}
	else if(type == "G4EllipticalTube") possibleNumberOfParameters = {3};
	else if(type == "G4Ellipsoid")      possibleNumberOfParameters = {5};
	else if(type == "G4EllipticalCone") possibleNumberOfParameters = {4};
	else if(type == "G4Paraboloid")     possibleNumberOfParameters = {3};
	else if(type == "G4Hype")           possibleNumberOfParameters = {5};
	else if(type == "G4Tet")            possibleNumberOfParameters = {12, 13};
	else if(type == "G4TwistedBox")     possibleNumberOfParameters = {4};
	else if(type == "G4TwistedTrap")    possibleNumberOfParameters = {5, 11};
	else if(type == "G4TwistedTrd")     possibleNumberOfParameters = {6};
	else if(type == "G4TwistedTubs")    possibleNumberOfParameters = {5};


	if(possibleNumberOfParameters.find(actualNumberOfParameters) == possibleNumberOfParameters.end() ) {
		cout << " !!! Fatal Error: the number of parameters in the constructor of " << name << ", " << type
		<< " is " << actualNumberOfParameters <<  ":" << s->getParameters() << endl;

		cout << "      This does not match a " << type <<". Exiting." << endl << endl;
		exit(99);
	}

	return parameters;
}




