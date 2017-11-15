
// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::publishDetectorTrueInfosHits(GDetectorObservables *detectorHits)
{
	if(ofile == nullptr) return false;
	
	*ofile  << " " << detectorHits->getName() << " true information {" << endl;
	
	vector<string> varNames = detectorHits->getObservableName();
	
	for(size_t v=0; v<varNames.size(); v++) {
		*ofile << GVARIABLEFLUSH << varNames[v] << ":";
		
		// get true infos
		for(auto dHit: detectorHits->getTObservables()) {
			
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
	
	
	
	*ofile  << " }" << endl;
	
	return true;
}
