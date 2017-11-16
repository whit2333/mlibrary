// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::publishHeader(GHeader gh)
{
	if(ofile == nullptr) return false;
	
	*ofile  << GVARIABLEFLUSH << "Header Bank {" << endl;
	*ofile  << GVARIABLEFLUSH << GVARIABLEFLUSH << " "
	*ofile  << GVARIABLEFLUSH << " }" << endl;

	return true;
}
