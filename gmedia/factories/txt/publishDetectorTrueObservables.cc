// txt gmedia
#include "gmediaTxtFactory.h"

bool GMediaTxtFactory::publishDetectorTrueObservables(GDetectorObservables *detectorHits)
{
	if(ofile == nullptr) return false;
	
	*ofile  << GVARIABLEFLUSH << detectorHits->getName() << " true observables {" << endl;
	
	vector<string> varNames = detectorHits->getTrueObservableName();
	vector<string> varUnits = detectorHits->getTrueObservableUnit();

	for(size_t v=0; v<varNames.size(); v++) {
		*ofile << GVARIABLEFLUSH << GVARIABLEFLUSH << varNames[v] << " (" << varUnits[v] << ") : ";

		// get true observables
		for(auto dHit: detectorHits->getTrueObservables()) {
			
			switch(dHit->getTypeAtIndex(v)) {
				case gint_t:
					*ofile << dHit->getIntVarAtIndex(v) << " ";
					break;
				case gfloat_t:
					*ofile << dHit->getFloatVarAtIndex(v) << " ";
					break;
				case gdouble_t:
					*ofile << dHit->getDoubleVarAtIndex(v) << " ";
					break;
				case gstring_t:
					*ofile << dHit->getIntVarAtIndex(v) << " ";
					break;
			}
		}
		*ofile << endl;
	}
	
	
	
	*ofile  << GVARIABLEFLUSH << "}" << endl;
	
	return true;
}
