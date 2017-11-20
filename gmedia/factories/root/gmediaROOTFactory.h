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
	GMediaROOTFactory() : gRootTrees(nullptr) {}
	
private:
	// open and close the output media
	bool openConnection();
	bool closeConnection();

	// start and end each event
	bool startEvent();
	bool endEvent();

	// write the header
	bool publishHeader(GHeader gh);
	
	// write digitized observables
	bool publishDetectorDigiObservables(GDetectorObservables *detectorHits);
	
	// write true observables
	bool publishDetectorTrueObservables(GDetectorObservables *detectorHits);

private:
	TFile *rootfile;
	map<string, GRootTree*> *gRootTrees;
	
	// return header tree from map. If not there, initialize it.
	GRootTree *getGRootTree(GHeader gh);

	// return observables tree from map. If not there, initialize it.
	GRootTree *getGRootTree(string treeName, vector<string> varNames, vector<GObservables*> observables);
	
};



#endif // GMEDIAROOTFACTORY_H
