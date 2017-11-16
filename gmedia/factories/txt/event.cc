// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::startEvent()
{
	if(ofile == nullptr) return false;
	
	*ofile  << "Event n. " << evn  << " {" << endl;
	
	return true;
}




bool GMediaTxtFactory::endEvent()
{
	if(ofile == nullptr) return false;
	
	*ofile  << "}" << endl;
	
	return true;
}
