#ifndef GMEDIATXTFACTORY_H
#define GMEDIATXTFACTORY_H 1

// gmedia
#include "gmedia.h"


class GMediaTxtFactory : public GMedia
{
public:
	GMediaTxtFactory() {ofile = nullptr;}
	
	bool openConnection();
	bool publishHeader(vector<GEventData*> *runData);
	bool closeConnection();

private:
	ofstream *ofile;
};



#endif // GMEDIATXTFACTORY_H
