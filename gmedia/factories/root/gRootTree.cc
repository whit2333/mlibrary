#include "gRootTree.h"

// return observables tree
GRootTree::GRootTree(string tName, vector<string> varNames, vector<GObservables*> observables)
{
	rootTree = new TTree(tName.c_str(), tName.c_str());

	for(size_t v=0; v<varNames.size(); v++) {
		
	}
}



// return header tree with initialzed leafs
GRootTree::GRootTree()
{
	rootTree = new TTree("header", "Event Header");
	
	stringVars["time"]     = new vector<string>;
	intVars["evn"]         = new vector<int>;
	intVars["localG4Evn"]  = new vector<int>;
	intVars["threadID"]    = new vector<int>;
	
	rootTree->Branch("time",       &stringVars["time"]);
	rootTree->Branch("evn",        &intVars["evn"]);
	rootTree->Branch("localG4Evn", &intVars["localG4Evn"]);
	rootTree->Branch("threadID",   &intVars["threadID"]);
}

// clears the maps vectors
bool GRootTree::initTreeForTheEvent()
{
	for(auto v: stringVars) {
		v.second->clear();
	}
	for(auto v: intVars) {
		v.second->clear();
	}
	for(auto v: floatVars) {
		v.second->clear();
	}
	for(auto v: doubleVars) {
		v.second->clear();
	}
}

bool GRootTree::fillTree(GHeader gh, int evn)
{
	stringVars["time"]->clear();
	intVars["evn"]->clear();

	stringVars["time"]->push_back(gh.getTimeStamp());
	intVars["evn"]->push_back(evn);
	
	// PRAGMA TODO: What if we get nothing?
	// can we return this?
	rootTree->Fill();
	
	return true;
}

