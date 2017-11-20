#ifndef GROOTTREE_H
#define GROOTTREE_H 1

// c++
#include <map>
using namespace std;

// ROOT
#include "TTree.h"

// mlibrary
#include "gdata.h"

class GRootTree
{
public:
	// return header tree with initialzed leafs
	GRootTree(GHeader gh);
	
	// return observables tree with initialzed leafs
	GRootTree(string tName, vector<string> varNames, vector<GObservables*> digiObservables);

private:
	TTree *rootTree;
	
	// variable maps
	map<string, vector<int>* >    intVars;
	map<string, vector<float>* >  floatVars;
	map<string, vector<double>* > doubleVars;
	map<string, vector<string>* > stringVars;
	
	
};

#endif // GROOTTREE_H
