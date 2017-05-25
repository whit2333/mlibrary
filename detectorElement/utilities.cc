// detectorElement
#include "DetectorElement.h"

// geant4
#include "G4UnitsTable.hh"
#include "G4VSolid.hh"
#include "G4LogicalVolume.hh"

// c++
#include <set>


ostream &operator<<(ostream &stream, DetectorElement detE)
{
	cout  << endl;
	cout << "   Detector name:  "  << detE.name     << "  -  " <<  detE.description << endl;
	cout << "   Mother:  "         << detE.mother              << endl;
	cout << "   Factory:  "        << detE.factory             << endl;
	cout << "   Type:  "           << detE.type                << endl;
	vector< vector<string> > dtypes = detE.dimensionsType();

	if(dtypes.size() == detE.dimensions.size()) {
		for(unsigned int i=0; i<dtypes.size(); i++){
			cout << "   " << dtypes[i][0] << ":  "  << G4BestUnit(detE.dimensions[i], dtypes[i][1])  << endl;
		}
	}

	string visibility = "yes";
	if(!detE.visible) {
		visibility = "no";
	}
	string style = "unknown";
	if(detE.style == 0) {
		style = "wireframe";
	} else if(detE.style == 1){
		style = "solid";

	}
	cout << "   Color:  "          << detE.color   << "  Visible: " << visibility << ",  with style: "  << style << endl;

	cout << "   Material:  "       << detE.material   << endl;
	cout << "   Magnetic Field:  " << detE.magfield   << endl;

	cout << "   Position (cm):  "  << detE.pos/cm     << endl;
	cout << "   Rotation:       "  << detE.rot        << endl;

	if(detE.exist == 0) {
		cout << "  This detector has existance set to zero." << endl;
	}

	cout << "   Sensitivity: "     << detE.sensitivity                            << endl;


	if(detE.solidVolume) {
		cout << "   Volume: "       << G4BestUnit(detE.solidVolume->GetCubicVolume(), "Volume")  << endl;
		cout << "   Surface Area: " << G4BestUnit(detE.solidVolume->GetSurfaceArea(), "Surface") << endl;
	}
	if(detE.logicalVolume) {
		cout << "   Mass: " << G4BestUnit(detE.logicalVolume->GetMass(), "Mass") << endl;
	}
	cout << endl;

	return stream;
}

// do we ever need this?
bool DetectorElement::operator == (const DetectorElement& detE) const
{
	// Name uniquely identifies a volume
	if(detE.name == this->name) {
		return true;
	} else {
		return false;
	}
}


// Returns dimensions nomenclature for different solid type
vector< vector<string> > DetectorElement::dimensionsType()
{

	vector< vector<string> > dtypes;

	if(type == "G4Box") {
		dtypes.push_back({"half length in X", "Length"});
		dtypes.push_back({"half length in Y", "Length"});
		dtypes.push_back({"half length in Z", "Length"});
	} else if(type == "G4Tubs") {
		dtypes.push_back({"Inner radius",       "Length"});
		dtypes.push_back({"Outer radius",       "Length"});
		dtypes.push_back({"Half length in z",   "Length"});
		dtypes.push_back({"Starting Phi angle", "Angle"});
		dtypes.push_back({"Delta Phi angle",    "Angle"});
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

	return dtypes;
}



// check solid number of parameters vs geant4 constructors
void DetectorElement::checkG4SolidDimensions()
{
	set<int> correctDimensions;

		 if(type == "G4Box")     correctDimensions = {3};
	else if(type == "G4Tubs")    correctDimensions = {5};
	else if(type == "G4CutTubs") correctDimensions = {7};
	else if(type == "G4Cons")    correctDimensions = {7};

	if(correctDimensions.find((int) dimensions.size()) == correctDimensions.end() ) {
		cout << " !! Fatal Error: the number of dimensions for " << name
		<< " is " << dimensions.size() <<  ":" << endl;
		for(unsigned int i=0; i<dimensions.size(); i++) {
			cout << "      dimension " << i + 1 << ": " <<  dimensions[i] << endl;
		}
		cout << "      This does not match a " << type <<". Exiting" << endl << endl;
		exit(0);
	}
}

















