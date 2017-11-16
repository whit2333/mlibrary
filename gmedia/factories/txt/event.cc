// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::startEvent(int evn)
{
	if(ofile == nullptr) return false;
	
	*ofile  << "Event n. " << evn  << " {" << endl;
	
	return true;
}




bool GMediaTxtFactory::endEvent(int runNo)
{
	if(ofile == nullptr) return false;
	
	*ofile  << " }" << endl;
	
	return true;
}
