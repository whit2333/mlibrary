#ifndef  GMAPCOORDINATES_H
#define  GMAPCOORDINATES_H  1

// Class GMAPCOORDINATES
// Thread Type: GLOBAL


// PRAGMA TODO: ADD THREAD TYPE At the top of each class definitions

// c++
#include <string>
#include <vector>
using namespace std;


// clhep
#include "CLHEP/Units/PhysicalConstants.h"
using namespace CLHEP;

class GMapCoordinate {
	
public:
	GMapCoordinate(string name, unsigned int np, double min, double max, string unit, int speed);

private:
	string       name;
	unsigned int np;
	double       min;
	double       max;
	string       unit;
	int          speed;     // 0 is the slowest varying coordinate

};

class GMapCoordinates {
	
public:
	GMapCoordinate getMapCoordinateWithSpeed(int speed);   ///< return coordinate based on speed
	GMapCoordinate getMapCoordinateWithName(string name);  ///< return coordinate based on type

private:
	vector<GMapCoordinate> gCoordinates;
};



#endif
