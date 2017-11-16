// txt gmedia
#include "gmediaTxtFactory.h"

bool GMediaTxtFactory::publishDetectorTrueObservables(GDetectorObservables *detectorHits)
{
	if(ofile == nullptr) return false;
	
	*ofile  << GVARIABLEFLUSH << detectorHits->getName() << " true observables {" << endl;
	
	vector<string> varNames = detectorHits->getTrueObservableName();
	vector<string> varUnits = detectorHits->getTrueObservableUnit();

	for(size_t v=0; v<varNames.size(); v++) {
		*ofile << GVARIABLEFLUSH << GVARIABLEFLUSH << varNames[v] << " [" << varUnits[v] << "]: ";

		// get true observables
		for(auto dObservableOneHit: detectorHits->getTrueObservables()) {
			writeObservables(dObservableOneHit, v);
		}
		
		*ofile << endl;
	}
	
	*ofile  << GVARIABLEFLUSH << "}" << endl;
	
	return true;
}
