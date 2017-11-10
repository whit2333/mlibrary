#ifndef  GOBSERVABLES_H
#define  GOBSERVABLES_H  1

// c++
#include <vector>
#include <string>
using namespace std;

enum GObservableType { gint_t, gfloat_t, gdouble_t, gstring_t};

#define GMULTIPLIER 100
#define GSTARTINDEX 1
#define GINTINDEXMULTIPLIER GSTARTINDEX
#define GFLOINDEXMULTIPLIER GSTARTINDEX*GMULTIPLIER
#define GDBLINDEXMULTIPLIER GSTARTINDEX*GMULTIPLIER*GMULTIPLIER
#define GSTRINDEXMULTIPLIER GSTARTINDEX*GMULTIPLIER*GMULTIPLIER*GMULTIPLIER

// Collection of variables mapped to each hit.
// They can integrate the steps in the hit (index = 0 to number of variables)
// or contain all the steps (index = 0 to number of variables*nsteps)
class GObservables
{
public:
	GObservables() : descriptionAssigned(false) {
		intVar.clear();
		floatVar.clear();
		doubleVar.clear();
		stringVar.clear();
	}
	
private:
	bool descriptionAssigned;
	vector<string> varName;
	vector<string> varDesc;

	// available types
	vector<int> intVar;
	vector<float> floatVar;
	vector<double> doubleVar;
	vector<string> stringVar;


	// index of the variable multiplied by its type multiplier
	vector<int> gTypeIndex;
	// to retrieve type quickly
	vector<GObservableType> gType;

	int getVariableIndex(int forIndex);
	
public:
	// clear the name and description. We do not need to carry those
	bool getDescriptionAssigned() {return descriptionAssigned;}
	void clearNamesAndDescriptions();
	vector<string> getName() {return varName;}
	vector<string> getDesc() {return varDesc;}

	// add variable value
	void addObservable(double var, string varName, string desc, string saveAs);
	void addObservable(int var, string varName, string desc, string saveAs);
	void addObservable(string var, string varName, string desc, string saveAs);
	void addObservable(float var, string varName, string desc, string saveAs);
	
	// add variable name, description
	void addObservableDescription(string n, string desc);
	
	int    getIntVarAtIndex(   int i) {return intVar[   getVariableIndex(i)];}
	float  getFloatVarAtIndex( int i) {return floatVar[ getVariableIndex(i)];}
	double getDoubleVarAtIndex(int i) {return doubleVar[getVariableIndex(i)];}
	string getStringVarAtIndex(int i) {return stringVar[getVariableIndex(i)];}

	size_t getNumberOfObservables() {return gTypeIndex.size();}
	
	GObservableType getTypeAtIndex(int i) {return gType[i];}
};


#endif
