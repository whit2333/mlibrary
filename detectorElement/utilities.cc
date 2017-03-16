
#include "detectorElement.h"

ostream &operator<<(ostream &stream, DetectorElement detE)
{
	cout  << endl;
	cout << "   Detector name:  "  << detE.name     << "  -  " <<  detE.description << endl;
	cout << "   Mother:  "         << detE.mother                                   << endl;
	cout << "   Position (cm):  "  << detE.pos/cm                                   << endl;
	cout << "   Rotation:       "  << detE.rot                                      << endl;
	cout << "   Color:  "          << detE.color                                    << endl;
	cout << "   Type:  "           << detE.type                                     << endl;
	vector< vector<string> > dtypes = detE.dimensionsType();

//	if(dtypes.size() != Detector.dimensions.size() && Detector.type.find("CopyOf") != 0)
//	{
//		for(unsigned int i=0; i<Detector.dimensions.size(); i++)
//			cout << "   Size " << i + 1 << ":  "  << Detector.dimensions[i]  << endl;
//	}
//	if(dtypes.size() == Detector.dimensions.size() && Detector.type.find("CopyOf") != 0)
//	for(unsigned int i=0; i<dtypes.size(); i++)
//		cout << "   " << dtypes[i][0] << ":  "  << G4BestUnit(Detector.dimensions[i], dtypes[i][1])  << endl;
//
//	cout << "   Material:  "       << Detector.material                               << endl;
//	cout << "   Magnetic Field:  " << Detector.magfield                               << endl;
//	cout << "   Copy Number:  "    << Detector.ncopy                                  << endl;
//	cout << "   Activated: "       << ( Detector.exist==1 ?   "yes"   : "no" )        << endl;
//	cout << "   Visible: "         << ( Detector.visible==1 ? "yes"   : "no" )        << endl;
//	cout << "   Style: "           << ( Detector.style==1 ?   "solid" : "wireframe" ) << endl;
//	cout << "   Sensitivity: "     << Detector.sensitivity                            << endl;
//	if(Detector.sensitivity != "no")
//	cout << "   hitType: "       << Detector.hitType                               << endl;
//
//	if(Detector.identity.size())
//	cout << Detector.identity ;
//
//	if(Detector.SolidV) {
//		cout << "   Volume: "       << bestValueUnits(Detector.SolidV->GetCubicVolume(), "Volume") << endl;
//		cout << "   Surface Area: " << bestValueUnits(Detector.SolidV-> GetSurfaceArea(), "Surface") << endl;
//	}
//	if(Detector.LogicV) {
//		cout << "   Mass: " << bestValueUnits(Detector.LogicV->GetMass(), "Mass") << endl;
//	}
//	cout << endl;

	return stream;
}

bool DetectorElement::operator == (const DetectorElement& detE) const
{
	// Name uniquely identifies a volume
	if(detE.name == this->name)
		return true;
	else
		return false;
}


// Returns dimensions nomenclature for different solid type
vector< vector<string> > DetectorElement::dimensionsType()
{

	vector< vector<string> > dtypes;
	vector<string> dt;
	dt.resize(2);

	if(type == "Box")
	{
		dt[0] = "half length in X";
		dt[1] = "Length";
		dtypes.push_back(dt);
		dt[0] = "half length in Y";
		dtypes.push_back(dt);
		dt[0] = "half length in Z";
		dtypes.push_back(dt);
	}

	if(type == "Sphere")
	{
		dt[1] = "Length";
		dt[0] = "Inner radius";
		dtypes.push_back(dt);
		dt[0] = "Outer radius";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Starting Phi angle of the segment";
		dtypes.push_back(dt);
		dt[0] = "Delta Phi angle of the segment";
		dtypes.push_back(dt);
		dt[0] = "Starting Theta angle of the segment";
		dtypes.push_back(dt);
		dt[0] = "Delta Theta angle of the segment";
		dtypes.push_back(dt);
	}
	if(type == "Tube")
	{
		dt[1] = "Length";
		dt[0] = "Inner radius";
		dtypes.push_back(dt);
		dt[0] = "Outer radius";
		dtypes.push_back(dt);
		dt[0] = "Half length in z";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Starting Phi angle";
		dtypes.push_back(dt);
		dt[0] = "Delta Phi angle";
		dtypes.push_back(dt);
	}
	if(type == "Trd")
	{
		dt[1] = "Length";
		dt[0] = "Half-length along x at the surface at -dz";
		dtypes.push_back(dt);
		dt[0] = "Half-length along x at the surface at +dz";
		dtypes.push_back(dt);
		dt[0] = "Half-length along y at the surface at -dz";
		dtypes.push_back(dt);
		dt[0] = "Half-length along y at the surface at +dz";
		dtypes.push_back(dt);
		dt[0] = "dz: Half-length along z axis";
		dtypes.push_back(dt);
	}
	if(type == "Cons")
	{
		dt[1] = "Length";
		dt[0] = "Inner radius at start";
		dtypes.push_back(dt);
		dt[0] = "Outer radius at start";
		dtypes.push_back(dt);
		dt[0] = "Inner radius at end";
		dtypes.push_back(dt);
		dt[0] = "Outer radius at end";
		dtypes.push_back(dt);
		dt[0] = "Half length in z";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Starting Phi angle";
		dtypes.push_back(dt);
		dt[0] = "Delta Phi angle";
		dtypes.push_back(dt);
	}
	if(type == "G4Trap")
	{
		dt[1] = "Length";
		dt[0] = "Half z length ";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Polar angle of the line joining the centres of the faces";
		dtypes.push_back(dt);
		dt[0] = "Azimuthal angle of the line joining the centre of the face";
		dtypes.push_back(dt);
		dt[1] = "Length";
		dt[0] = "Half y length at -pDz";
		dtypes.push_back(dt);
		dt[0] = "Half x length of the side at y=-pDy1, -pDz";
		dtypes.push_back(dt);
		dt[0] = "Half x length of the side at y=+pDy1, -pDz";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Angle to the y axis from the centre (lower endcap) ";
		dtypes.push_back(dt);
		dt[1] = "Length";
		dt[0] = "Half y length at +pDz";
		dtypes.push_back(dt);
		dt[0] = "Half x length of the side at y=-pDy2, +pDz";
		dtypes.push_back(dt);
		dt[0] = "Half x length of the side at y=+pDy2, +pDz";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Angle to the y axis from the centre (upper endcap) ";
		dtypes.push_back(dt);
	}

	if(type == "G4EllipticalTube")
	{
		dt[1]="Lenght";
		dt[0]="Half length x";
		dtypes.push_back(dt);
		dt[1]="Lenght";
		dt[0]="Half length y";
		dtypes.push_back(dt);
		dt[1]="Lenght";
		dt[0]="Half length z";
		dtypes.push_back(dt);
	}

	if(type == "Hype")
	{
		dt[1]="Length";
		dt[0]="Inner radius";
		dtypes.push_back(dt);
		dt[0] = "Outer radius";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Inner stereo angle";
		dtypes.push_back(dt);
		dt[0] = "Outer stereo angle";
		dtypes.push_back(dt);
		dt[1]="Length";
		dt[0] = "Half length in z";
		dtypes.push_back(dt);
	}

	if(type == "Parallelepiped")
	{
		dt[1]="Length";
		dt[0]="Half length in x";
		dtypes.push_back(dt);
		dt[0] = "Half length in y";
		dtypes.push_back(dt);
		dt[0] = "Half length in z";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Angle formed by the y axis and the plane joining the centre of the faces parallel to the z-x plane at -dy and +dy" ;
		dtypes.push_back(dt);
		dt[0] = "Polar angle of the line joining the centres of the faces at -dz and +dz in z ";
		dtypes.push_back(dt);
		dt[0] = "Azimuthal angle of the line joining the centres of the faces at -dz and +dz in z ";
		dtypes.push_back(dt);
	}

	if(type == "Torus")
	{
		dt[1]="Length";
		dt[0]="Inner radius";
		dtypes.push_back(dt);
		dt[0] = "Outer radius";
		dtypes.push_back(dt);
		dt[0] = "Swept radius of torus";
		dtypes.push_back(dt);
		dt[1] = "Angle";
		dt[0] = "Starting Phi angle";
		dtypes.push_back(dt);
		dt[0] = "Outer stereo angle";
		dtypes.push_back(dt);
	}

	if(type == "Ellipsoid")
	{
		dt[1]="Length";
		dt[0]="Semiaxis in X";
		dtypes.push_back(dt);
		dt[0] = "Semiaxis in Y ";
		dtypes.push_back(dt);
		dt[0] = "Semiaxis in Z ";
		dtypes.push_back(dt);
		dt[0] = "lower cut plane level, z";
		dtypes.push_back(dt);
		dt[0] = "upper cut plane level, z";
		dtypes.push_back(dt);
	}

	return dtypes;
}

