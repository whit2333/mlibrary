#ifndef GMEDIATXTFACTORY_H
#define GMEDIATXTFACTORY_H 1

#include "gmedia.h"

class GMediaTxtFactory : public GMedia
{
public:
	GMediaTxtFactory() {;}
	
	bool publishHeader(vector<GEventData*> *runData);
};

extern "C" GMedia* GMediaFactory(void) {
	return static_cast<GMedia*>(new GMediaTxtFactory);
}


#endif // GMEDIATXTFACTORY_H
