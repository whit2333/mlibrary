#ifndef GMEDIAROOTFACTORY_H
#define GMEDIAROOTFACTORY_H 1

// gmedia
#include "gmedia.h"


class GMediaROOTFactory : public GMedia
{
public:
	GMediaROOTFactory()  {}
	
	
private:
	ofstream *rootfile;
};



#endif // GMEDIATXTFACTORY_H
