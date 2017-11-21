// txt gmedia
#include "gmediaROOTFactory.h"


bool GMediaROOTFactory::startEvent()
{
	if(rootfile == nullptr) return false;
	
	// clearing maps vectors for all trees
	for(auto t: (*gRootTrees)) {
		t.second->initTreeForTheEvent();
	}
	
	return true;
}




bool GMediaROOTFactory::endEvent()
{
	if(rootfile == nullptr) return false;
	
	
	return true;
}
