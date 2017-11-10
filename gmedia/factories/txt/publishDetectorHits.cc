
// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::publishDetectorHits(GDetectorObservables *detectorHits)
{
	if(ofile == nullptr) return false;
	
	*ofile  << " " << detectorHits->getName() << " observables {" << endl;
	
	vector<string> varNames = detectorHits->getVarName();
	
	for(size_t v=0; v<varNames.size(); v++) {
		*ofile << GVARIABLEFLUSH << varNames[v] << ":";
		
		for(auto dHit: detectorHits->getDObservables()) {
			
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
