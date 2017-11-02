#ifndef  GDATA_H
#define  GDATA_H  1

// c++
#include <vector>
#include <string>
using namespace std;

// mlibrary
#include "ghit.h"
#include "goptions.h"

// these variables are integrate over the time window
// each hit is mapped onto one instance of this class
class GHitDataIntegrated
{
private:
    vector<double> doubleVar;
    vector<int> intVar;
    vector<string> stringVar;
};

// these variables are integrate over the time window
// each hit is mapped onto one instance of this class
class GHitDataAllSteps
{
private:
    vector<double> doubleVar;
    vector<int> intVar;
    vector<string> stringVar;
    vector<int> stepIndex;
};


// base class for a single hit data information
class GDetectorData
{
public:
    bool fillTrueInformation(GHitsCollection *ghc);
    
private:
    vector<string> variableName;
    vector<string> variableDescription;
    
    // this vector is used to order the variables
    // it is a sequence of integers.
    // If the integer value is smaller than 1000, it indicates a "double" variable
    // If the integer is a multiple of 1000, it indicates an "int" variable
    // If the integer is a multiple of 1000000, it indicates a "string" variable
    // for example:
    // 1 2 1000 3 2000 3000
    // indicate an order of types:
    // double double int double int int
    vector<int>    variableIntegerIdentifier;
    
    vector<GHitDataIntegrated> dataIntegrated;
    vector<GHitDataAllSteps> dataAllSteps;
  
    string detectorName;
};


class GData
{
private:
    vector<GDetectorData> detectorData;
    
public:
    // GSetup options - defined in utilities.cc
    static map<string, GOption> defineOptions();

};

#endif
