#ifndef GROOTTREE_H
#define GROOTTREE_H 1


// ROOT
#include "TTree.h"

class GRootTree
{
public:
	GRootTree() : leafsAreInitialized(false) {}
	bool areLeafsInitialized() {return leafsAreInitialized;}
	
private:
	TTree *rootTree;
	
	// variable maps
	map<string, vector<int>* >    intVars;
	map<string, vector<float>* >  floatVars;
	map<string, vector<double>* > doubleVars;
	map<string, vector<string>* > stringVars;
	
	bool leafsAreInitialized;
	
private:
	void initializeLeafs();
};



#endif // GROOTTREE_H
