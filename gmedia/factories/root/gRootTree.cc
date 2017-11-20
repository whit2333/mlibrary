#include "gRootTree.h"

// return tree with initialzed leafs
GRootTree::GRootTree(string tName, vector<string> varNames, vector<GObservables*> observables)
{
	rootTree = new TTree(tName.c_str(), tName.c_str());

	for(size_t v=0; v<varNames.size(); v++) {
		
	}
}



// return tree with initialzed leafs
GRootTree::GRootTree(GHeader gh)
{
	rootTree = new TTree("Header", "Event Header");
	
	stringVars["time"]     = new vector<string>;
	intVars["evn"]         = new vector<int>;
	intVars["localG4Evn"]  = new vector<int>;
	intVars["threadID"]    = new vector<int>;
	
	rootTree->Branch("time",       &stringVars["time"]);
	rootTree->Branch("evn",        &intVars["evn"]);
	rootTree->Branch("localG4Evn", &intVars["localG4Evn"]);
	rootTree->Branch("threadID",   &intVars["threadID"]);

}
