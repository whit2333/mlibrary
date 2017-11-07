// gdata
#include "gobservables.h"

// the functions are overloaded instead of templated

void GObservables::addObservable(double var, string varName, string desc, string saveAs)
{
	if(saveAs == "double") {
		doubleVar.push_back(var);
		addObservableDescription(varName, desc, saveAs);
	} else {
		throw "Variable " + varName + " type does not match a double";
	}
}

void GObservables::addObservable(int var, string varName, string desc, string saveAs)
{
	if(saveAs == "int") {
		intVar.push_back(var);
		addObservableDescription(varName, desc, saveAs);
	} else {
		throw "Variable " + varName + " type does not match an int";
	}

}

void GObservables::addObservable(string var, string varName, string desc, string saveAs)
{
	if(saveAs == "string") {
		stringVar.push_back(var);
		addObservableDescription(varName, desc, saveAs);
	} else {
		throw "Variable " + varName + " type does not match a string";
	}

}

void GObservables::addObservable(float var, string varName, string desc, string saveAs)
{
	if(saveAs == "float") {
		floatVar.push_back(var);
		addObservableDescription(varName, desc, saveAs);
	} else {
		throw "Variable " + varName + " type does not match a float";
	}

}


void GObservables::addObservableDescription(string name, string desc, string saveAs)
{
	// only add description if variable is not found
	if(find(begin(varName), end(varName), name) == end(varName)) {
		
		varName.push_back(name);
		
		varDescription.push_back(desc);
		if(saveAs == "float") {
			gtypes.push_back(gfloat_t);
		} else if(saveAs == "double") {
			gtypes.push_back(gdouble_t);
		} else if(saveAs == "int") {
			gtypes.push_back(gint_t);
		} else if(saveAs == "string") {
			gtypes.push_back(gstring_t);
		}
	}
}
