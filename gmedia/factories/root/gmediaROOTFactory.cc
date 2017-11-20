// txt gmedia
#include "gmediaROOTFactory.h"

GRootTree* GMediaROOTFactory::getGRootTree(GHeader gh)
{
	// tree not found, initializing it
	if(gRootTrees->find(treeName) == gRootTrees->end()) {
		(*gRootTrees)[treeName] = new GRootTree(gh);
	}
	
	// return initialized tree
	return (*gRootTrees)[treeName];
	
}

GRootTree* GMediaROOTFactory::getGRootTree(string treeName, vector<string> varNames, vector<GObservables*> observables)
{
	// tree not found, initializing it
	if(gRootTrees->find(treeName) == gRootTrees->end()) {
		(*gRootTrees)[treeName] = new GRootTree(treeName, varNames, observables);
	}
	
	// return initialized tree
	return (*gRootTrees)[treeName];
	
}



// tells the DLL how to create a GMediaFactory
extern "C" GMedia* GMediaFactory(void) {
	return static_cast<GMedia*>(new GMediaROOTFactory);
}
