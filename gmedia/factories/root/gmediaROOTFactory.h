#ifndef GMEDIAROOTFACTORY_H
#define GMEDIAROOTFACTORY_H 1

// gmedia
#include "gmedia.h"
#include "gRootTree.h"

// ROOT
#include "TFile.h"

class GMediaROOTFactory : public GMedia
{
public:
	GMediaROOTFactory() {}
	
private:
	// open and close the output media
	bool openConnection();
	bool closeConnection();

	// start and end each event
	bool startEvent();
	bool endEvent();

private:
	TFile *rootfile;
	map<string, GRootTree> gRootTrees;
	
	
};



#endif // GMEDIAROOTFACTORY_H
