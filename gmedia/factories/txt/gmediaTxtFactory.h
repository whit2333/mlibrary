#ifndef GMEDIATXTFACTORY_H
#define GMEDIATXTFACTORY_H 1

// gmedia
#include "gmedia.h"

#define GVARIABLEFLUSH "  "

class GMediaTxtFactory : public GMedia
{
public:
	GMediaTxtFactory() {ofile = nullptr;}
	
private:
	bool openConnection();
	bool publishHeader(vector<GEventData*> *runData);
	bool publishDetectorHits(GDetectorObservables *detectorHits);
	bool publishDetectorTrueInfosHits(GDetectorObservables *detectorHits);
	bool closeConnection();

private:
	ofstream *ofile;
};



#endif // GMEDIATXTFACTORY_H
