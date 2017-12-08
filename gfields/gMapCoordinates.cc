// gfields
#include "gMapCoordinates.h"


GMapCoordinate::GMapCoordinate(string iname, unsigned int inp, double imin, double imax, string iunit, int ispeed) :
name(iname),
np(inp),
min(imin),
max(imax),
unit(iunit),
speed(ispeed)
{
	// PRAGMA TODO: consistency check with coordinate names, units?
	
}
