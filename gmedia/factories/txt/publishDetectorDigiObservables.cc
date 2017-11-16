// txt gmedia
#include "gmediaTxtFactory.h"

bool GMediaTxtFactory::publishDetectorDigiObservables(GDetectorObservables *detectorHits)
{
	if(ofile == nullptr) return false;
	
	*ofile  << GVARIABLEFLUSH << detectorHits->getName() << " digitized observables {" << endl;
	
	vector<string> varNames = detectorHits->getDigiObservableName();
	vector<string> varUnits = detectorHits->getDigiObservableUnit();

	for(size_t v=0; v<varNames.size(); v++) {
		*ofile << GVARIABLEFLUSH << GVARIABLEFLUSH << varNames[v] << " [" << varUnits[v] << "]: ";
		
		// get digitized observables
		for(auto dObservableOneHit: detectorHits->getDigiObservables()) {
			writeObservables(dObservableOneHit, v);
		}
		
		*ofile << endl;
	}
	
	*ofile  << GVARIABLEFLUSH << "}" << endl;
	
	return true;
}
