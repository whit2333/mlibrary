// gmedia
#include "gmediaROOTFactory.h"

bool GMediaROOTFactory::publishDetectorDigiObservables(GDetectorObservables *detectorHits)
{
	if(rootfile == nullptr) return false;
	
	string tname            = detectorHits->getName() + string(DIGITNAMESUFFIX);
	vector<string> varNames = detectorHits->getDigiObservableName();
	
	// get or define root tree from the map
	// only the first hit is needed
	GRootTree *observablesTree = getGRootTree(tname, varNames, detectorHits->getDigiObservables().front());

	return observablesTree->fillTree(varNames, detectorHits->getDigiObservables());

}
