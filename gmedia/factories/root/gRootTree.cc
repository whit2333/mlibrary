#include "gRootTree.h"

// return observables tree
GRootTree::GRootTree(string tName, vector<string> varNames, GObservables* firstDigiObservables)
{
	rootTree = new TTree(tName.c_str(), tName.c_str());

	for(size_t v=0; v<varNames.size(); v++) {
		defineNewVar(varNames[v], firstDigiObservables->getTypeAtIndex(v));
	}
}



// return header tree with initialzed leafs
GRootTree::GRootTree()
{
	rootTree = new TTree("header", "Event Header");
	
	defineNewVar("time",       gstring_t);
	defineNewVar("evn",        gint_t);
	defineNewVar("localG4Evn", gint_t);
	defineNewVar("threadID",   gint_t);
}


// define new variable and
bool  GRootTree::defineNewVar(string varName, GObservableType gt)
{
	switch (gt) {
		case gstring_t:
			stringVars[varName] = new vector<string>;
			rootTree->Branch(varName.c_str(), &stringVars[varName]);
			return true;
		case gint_t:
			intVars[varName] = new vector<int>;
			rootTree->Branch(varName.c_str(), &intVars[varName]);
			return true;
		case gfloat_t:
			floatVars[varName] = new vector<float>;
			rootTree->Branch(varName.c_str(), &floatVars[varName]);
			return true;
		case gdouble_t:
			doubleVars[varName] = new vector<double>;
			rootTree->Branch(varName.c_str(), &doubleVars[varName]);
			return true;

		default:
			return false;
	}
	return false;
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
	return true;
}


bool GRootTree::fillTree(GHeader gh, int evn)
{
	intVars["evn"]->push_back(evn);
	stringVars["time"]->push_back(gh.getTimeStamp());
	intVars["localG4Evn"]->push_back(gh.getG4Evn());
	intVars["threadID"]->push_back(gh.getThreadID());

	// PRAGMA TODO: What if we get nothing?
	// can we return this?
	rootTree->Fill();
	
	return true;
}

bool  GRootTree::fillTree(vector<GObservables*> observables)
{
	
	
	
	// PRAGMA TODO: What if we get nothing?
	// can we return this?
	rootTree->Fill();

	return true;
}

