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
	GRootTree();
	
	// return observables tree with initialzed leafs
	GRootTree(string tName, vector<string> varNames, GObservables* firstDigiObservables);

	bool initTreeForTheEvent();
	
	// filling trees
	bool fillTree(GHeader gh, int evn);
	bool fillTree(vector<string> varNames, vector<GObservables*> observables);

	bool defineNewVar(string varName, GObservableType gt);
	
private:
	TTree *rootTree;
	
	// variable maps
	map<string, vector<int>* >    intVars;
	map<string, vector<float>* >  floatVars;
	map<string, vector<double>* > doubleVars;
	map<string, vector<string>* > stringVars;
	
};

#endif // GROOTTREE_H
