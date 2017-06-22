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
	vector<string> parameters = checkAndReturnParameters(s);
	string type = s->getType();

	if(type == "G4Box") {
		thisG4Volume->addSolid(new G4Box(vname,             ///< name
										 parameters[0],    ///< half length in X
										 parameters[1],    ///< half length in Y
										 parameters[2]);   ///< half length in Z
							   )
		return true;
	} else 	if(type == "G4Tubs") {
		thisG4Volume->addSolid(new G4Tubs(vname,            ///< name
										  parameters[0],   ///< Inner radius
										  parameters[1],   ///< Outer radius
										  parameters[2],   ///< Half length in z
										  parameters[3],   ///< The starting phi angle
										  parameters[4]);  ///< Delta Phi angle of the segment
							   return true;
							   }
	

	return false;
}




// returns description of geant4 constructor parameters
vector<string> descriptionsOfParameters(GVolume *s)
{
	vector<string> parsDescription;
	string type = s->getType();

	       if(type == "G4Box") {
		parsDescription.push_back({"half length in X", "Length"});
		parsDescription.push_back({"half length in Y", "Length"});
		parsDescription.push_back({"half length in Z", "Length"});
	} else if(type == "G4Tubs") {
		parsDescription.push_back({"Inner radius",       "Length"});
		parsDescription.push_back({"Outer radius",       "Length"});
		parsDescription.push_back({"Half length in z",   "Length"});
		parsDescription.push_back({"Starting Phi angle", "Angle"});
		parsDescription.push_back({"Delta Phi angle",    "Angle"});
	}



	// to be completed - order is the same as https://geant4.web.cern.ch/geant4/UserDocumentation/UsersGuides/ForApplicationDeveloper/html/ch04.html





	//
	//	if(type == "Sphere")
	//	{
	//		dt[1] = "Length";
	//		dt[0] = "Inner radius";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer radius";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Starting Phi angle of the segment";
	//		dtypes.push_back(dt);
	//		dt[0] = "Delta Phi angle of the segment";
	//		dtypes.push_back(dt);
	//		dt[0] = "Starting Theta angle of the segment";
	//		dtypes.push_back(dt);
	//		dt[0] = "Delta Theta angle of the segment";
	//		dtypes.push_back(dt);
	//	}
	//	if(type == "Trd")
	//	{
	//		dt[1] = "Length";
	//		dt[0] = "Half-length along x at the surface at -dz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half-length along x at the surface at +dz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half-length along y at the surface at -dz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half-length along y at the surface at +dz";
	//		dtypes.push_back(dt);
	//		dt[0] = "dz: Half-length along z axis";
	//		dtypes.push_back(dt);
	//	}
	//	if(type == "Cons")
	//	{
	//		dt[1] = "Length";
	//		dt[0] = "Inner radius at start";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer radius at start";
	//		dtypes.push_back(dt);
	//		dt[0] = "Inner radius at end";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer radius at end";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half length in z";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Starting Phi angle";
	//		dtypes.push_back(dt);
	//		dt[0] = "Delta Phi angle";
	//		dtypes.push_back(dt);
	//	}
	//	if(type == "G4Trap")
	//	{
	//		dt[1] = "Length";
	//		dt[0] = "Half z length ";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Polar angle of the line joining the centres of the faces";
	//		dtypes.push_back(dt);
	//		dt[0] = "Azimuthal angle of the line joining the centre of the face";
	//		dtypes.push_back(dt);
	//		dt[1] = "Length";
	//		dt[0] = "Half y length at -pDz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half x length of the side at y=-pDy1, -pDz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half x length of the side at y=+pDy1, -pDz";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Angle to the y axis from the centre (lower endcap) ";
	//		dtypes.push_back(dt);
	//		dt[1] = "Length";
	//		dt[0] = "Half y length at +pDz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half x length of the side at y=-pDy2, +pDz";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half x length of the side at y=+pDy2, +pDz";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Angle to the y axis from the centre (upper endcap) ";
	//		dtypes.push_back(dt);
	//	}
	//
	//	if(type == "G4EllipticalTube")
	//	{
	//		dt[1]="Lenght";
	//		dt[0]="Half length x";
	//		dtypes.push_back(dt);
	//		dt[1]="Lenght";
	//		dt[0]="Half length y";
	//		dtypes.push_back(dt);
	//		dt[1]="Lenght";
	//		dt[0]="Half length z";
	//		dtypes.push_back(dt);
	//	}
	//
	//	if(type == "Hype")
	//	{
	//		dt[1]="Length";
	//		dt[0]="Inner radius";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer radius";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Inner stereo angle";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer stereo angle";
	//		dtypes.push_back(dt);
	//		dt[1]="Length";
	//		dt[0] = "Half length in z";
	//		dtypes.push_back(dt);
	//	}
	//
	//	if(type == "Parallelepiped")
	//	{
	//		dt[1]="Length";
	//		dt[0]="Half length in x";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half length in y";
	//		dtypes.push_back(dt);
	//		dt[0] = "Half length in z";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Angle formed by the y axis and the plane joining the centre of the faces parallel to the z-x plane at -dy and +dy" ;
	//		dtypes.push_back(dt);
	//		dt[0] = "Polar angle of the line joining the centres of the faces at -dz and +dz in z ";
	//		dtypes.push_back(dt);
	//		dt[0] = "Azimuthal angle of the line joining the centres of the faces at -dz and +dz in z ";
	//		dtypes.push_back(dt);
	//	}
	//
	//	if(type == "Torus")
	//	{
	//		dt[1]="Length";
	//		dt[0]="Inner radius";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer radius";
	//		dtypes.push_back(dt);
	//		dt[0] = "Swept radius of torus";
	//		dtypes.push_back(dt);
	//		dt[1] = "Angle";
	//		dt[0] = "Starting Phi angle";
	//		dtypes.push_back(dt);
	//		dt[0] = "Outer stereo angle";
	//		dtypes.push_back(dt);
	//	}
	//
	//	if(type == "Ellipsoid")
	//	{
	//		dt[1]="Length";
	//		dt[0]="Semiaxis in X";
	//		dtypes.push_back(dt);
	//		dt[0] = "Semiaxis in Y ";
	//		dtypes.push_back(dt);
	//		dt[0] = "Semiaxis in Z ";
	//		dtypes.push_back(dt);
	//		dt[0] = "lower cut plane level, z";
	//		dtypes.push_back(dt);
	//		dt[0] = "upper cut plane level, z";
	//		dtypes.push_back(dt);
	//	}

	return parsDescription;
}



// check that the number of parameters matches the geant4 constructor
vector<string> G4NativeSystemFactory::checkAndReturnParameters(GVolume *s)
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

	vector<string> parameters = getStringVectorFromString(s->getParameters());
	int actualNumberOfParameters = (int) parameters.size();

		 if(type == "G4Box")     possibleNumberOfParameters = {3};
	else if(type == "G4Tubs")    possibleNumberOfParameters = {5};
	else if(type == "G4CutTubs") possibleNumberOfParameters = {7};
	else if(type == "G4Cons")    possibleNumberOfParameters = {7};

	if(possibleNumberOfParameters.find(actualNumberOfParameters) == possibleNumberOfParameters.end() ) {
		cout << " !!! Fatal Error: the number of parameters in the constructor of " << name
		<< " is " << actualNumberOfParameters <<  ":" << s->getParameters() << endl;

		cout << "      This does not match a " << type <<". Exiting." << endl << endl;
		exit(0);
	}
	return parameters;
}




