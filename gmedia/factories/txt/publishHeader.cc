// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::publishHeader(GHeader gh)
{
	if(ofile == nullptr) return false;
	
	*ofile  << GVARIABLEFLUSH << "Header Bank {" << endl;
	*ofile  << GVARIABLEFLUSH << GVARIABLEFLUSH << " time: " << gh.getTimeStamp() << endl;
	*ofile  << GVARIABLEFLUSH << GVARIABLEFLUSH << " g4-local event number: " << gh.getG4Evn() << endl;
	*ofile  << GVARIABLEFLUSH << GVARIABLEFLUSH << " thread id: " << gh.getThreadID() << endl;
//	*ofile  << GVARIABLEFLUSH << GVARIABLEFLUSH << " random status: " << gh.getG4Rnd() << endl;
	*ofile  << GVARIABLEFLUSH << "}" << endl;

	return true;
}
