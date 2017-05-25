// gvolume
#include "gVolume.h"

// c++
#include <iostream>

ostream &operator<<(ostream &stream, GVolume gVol)
{
	cout  << endl;
	cout << "   Volume Name:  "    << gVol.name     << "  -  " <<  gVol.description << endl;
	cout << "   Mother:  "         << gVol.mother              << endl;
	cout << "   Factory:  "        << gVol.factory             << endl;
	cout << "   Type:  "           << gVol.type                << endl;
	cout << "   Dimensions:  "     ;

	for(unsigned int i=0; i<gVol.dimensions.size(); i++) {
		cout << "  " << gVol.dimensions[i]   << "  " ;
	}
	cout << endl;


	string visibility = "yes";
	if(!gVol.visible) {
		visibility = "no";
	}
	string style = "unknown";
	if(gVol.style == 0) {
		style = "wireframe";
	} else if(gVol.style == 1){
		style = "solid";

	}
	cout << "   Color:  "          << gVol.color   << "  Visible: " << visibility << ",  with style: "  << style << endl;

	cout << "   Material:  "       << gVol.material << endl;
	cout << "   Magnetic Field:  " << gVol.magfield << endl;

	cout << "   Position (cm):  "  << gVol.pos << endl;
	cout << "   Rotation:       "  << gVol.rot << endl;

	cout << "   Sensitivity: "     << gVol.sensitivity << endl;

	return stream;
}








