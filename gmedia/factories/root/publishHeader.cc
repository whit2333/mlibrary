// gmedia
#include "gmediaROOTFactory.h"


bool GMediaROOTFactory::publishHeader(GHeader gh)
{
	if(rootfile == nullptr) return false;
	
	// get root tree from the map
	GRootTree *headerTree = getHeaderGRootTree();
	
	// fill variables and tree
	return headerTree->fillTree(gh, evn);
	
}
