#ifndef  GOBSERVABLES_H
#define  GOBSERVABLES_H  1

// c++
#include <vector>
#include <string>
using namespace std;

enum GObservableType { gint_t, gfloat_t, gdouble_t, gstring_t};

// Collection of variables mapped to each hit.
// They can integrate the steps in the hit (index = 0 to number of variables)
// or contain all the steps (index = 0 to number of variables*nsteps)
class GObservables
{
public:
	GObservables(){}
	
private:
	vector<float> floatVar;
	vector<double> doubleVar;
	vector<int> intVar;
	vector<string> stringVar;
	

	vector<string> varName;
	vector<string> varDescription;

	vector<GObservableType> gtypes;

	// api to fill infos
public:
	// add a variable.
	void addObservable(double var, string varName, string desc, string saveAs);
	void addObservable(int var, string varName, string desc, string saveAs);
	void addObservable(string var, string varName, string desc, string saveAs);
	void addObservable(float var, string varName, string desc, string saveAs);
	
	// add variable description
	void addObservableDescription(string n, string desc, string saveAs);

};


#endif
