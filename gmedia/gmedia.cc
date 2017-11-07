// gmedia 
#include "gmedia.h"

bool GMedia::publishData(vector<GEventData*> *runData) {
	
	bool headerPublished = publishHeader(runData);
	
	
	bool summary = headerPublished + false;
	
	return summary;
}
