// gdata
#include "gobservables.h"

// the functions are overloaded instead of templated


void GObservables::addObservable(int var, string varName, string desc, string saveAs)
{
	addObservableDescription(varName, desc);

	if(saveAs == "int") {
		gtypes.push_back(intVar.size()*GINTINDEXMULTIPLIER);
		intVar.push_back(var);
	} else {
		throw "Variable type does not match an int";
	}
}


void GObservables::addObservable(float var, string varName, string desc, string saveAs)
{
	addObservableDescription(varName, desc);

	if(saveAs == "float") {
		gtypes.push_back(floatVar.size()*GFLOINDEXMULTIPLIER);
		floatVar.push_back(var);
	} else {
		throw "Variable type does not match a float";
	}
}

void GObservables::addObservable(double var, string varName, string desc, string saveAs)
{
	addObservableDescription(varName, desc);
	
	if(saveAs == "double") {
		gtypes.push_back(doubleVar.size()*GDBLINDEXMULTIPLIER);
		doubleVar.push_back(var);
	} else {
		throw "Variable type does not match a double";
	}
}

void GObservables::addObservable(string var, string varName, string desc, string saveAs)
{
	addObservableDescription(varName, desc);

	if(saveAs == "string") {
		gtypes.push_back(stringVar.size()*GSTRINDEXMULTIPLIER);
		stringVar.push_back(var);
	} else {
		throw "Variable type does not match a string";
	}
}


void GObservables::addObservableDescription(string name, string desc)
{
	// only add name, description if variable is not found
	if(find(begin(varName), end(varName), name) == end(varName)) {
		
		varName.push_back(name);
		varDesc.push_back(desc);
	}
}


int GObservables::getVariableIndex(int forIndex)
{
	int gindex = gTypeIndex[forIndex];
	if(gindex/GSTRINDEXMULTIPLIER > 0) {
		return gindex/GSTRINDEXMULTIPLIER;
	} else if(gindex/GDBLINDEXMULTIPLIER > 0) {
		return gindex/GDBLINDEXMULTIPLIER;
	} else if(gindex/GFLOINDEXMULTIPLIER > 0) {
		return gindex/GFLOINDEXMULTIPLIER;
	} else {
		return gindex;
	}
}




