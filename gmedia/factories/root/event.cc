// txt gmedia
#include "gmediaROOTFactory.h"


bool GMediaROOTFactory::startEvent()
{
	if(rootfile == nullptr) return false;
	
	
	return true;
}




bool GMediaROOTFactory::endEvent()
{
	if(rootfile == nullptr) return false;
	
	
	return true;
}
