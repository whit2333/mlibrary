
// txt gmedia
#include "gmediaTxtFactory.h"


bool GMediaTxtFactory::publishDetectorHits(GDetectorObservables *detectorHits)
{
	if(ofile == nullptr) return false;
	
	*ofile  << " " << detectorHits->getName() << " observables {" << endl;
	
	for(auto dHit: detectorHits->getDObservables()) {
		
		for(size_t v=0; v<dHit->getNumberOfObservables(); v++) {
			
			*ofile << GVARIABLEFLUSH << dHit->getVarNameAtIndex(v) << ":";
			*ofile << " v " <<  dHit->getVarDescAtIndex(v) << " ";
			switch(dHit->getTypeAtIndex(v)) {
				case gint_t:
					*ofile << dHit->getIntVarAtIndex(v) << endl;
					break;
				case gfloat_t:
					*ofile << dHit->getFloatVarAtIndex(v) << endl;
					break;
				case gdouble_t:
					*ofile << dHit->getDoubleVarAtIndex(v) << endl;
					break;
				case gstring_t:
					*ofile << dHit->getIntVarAtIndex(v) << endl;
					break;
			}
		}
	}
	
	*ofile  << " }" << endl;
	
	return true;
}
