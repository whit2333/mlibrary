// gmedia
#include "gmediaROOTFactory.h"

bool GMediaROOTFactory::publishDetectorDigiObservables(GDetectorObservables *detectorHits)
{
	if(rootfile == nullptr) return false;
	
	string tname            = detectorHits->getName() + string(DIGITNAMESUFFIX);
	vector<string> varNames = detectorHits->getDigiObservableName();
	
	// get root tree from the map
	GRootTree *observablesTree = getGRootTree(tname, varNames, detectorHits->getDigiObservables().front());

	return observablesTree->fillTree(detectorHits->getDigiObservables());

}
