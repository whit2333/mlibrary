#ifndef CPPFACTORY_DERIVEDCLASSTWO_H
#define CPPFACTORY_DERIVEDCLASSTWO_H

#include "gfactory.h"

#include <iostream>
using namespace std;

class DerivedClassTwo : public MyBaseClass2
{
public:
	DerivedClassTwo(){};
	virtual ~DerivedClassTwo(){};
	
	virtual void doSomethingElse() { cout << "I am class two" << endl; }
	
};


#endif // CPPFACTORY_DERIVEDCLASSONE_H
