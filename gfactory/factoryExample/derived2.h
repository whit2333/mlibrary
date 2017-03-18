#ifndef CPPFACTORY_DERIVEDCLASSTWO_H
#define CPPFACTORY_DERIVEDCLASSTWO_H

#include "gfactory.h"

#include <iostream>
using namespace std;

class DerivedClassTwo : public MyBaseClass
{
public:
	DerivedClassTwo(){};
	virtual ~DerivedClassTwo(){};
	
	virtual void doSomething() { cout << "I am class two" << endl; }
	
//	virtual void processEvent() = 0;
};


class p1 : public DerivedClassTwo
{
	virtual void processEvent() { cout << "process two" << endl; }

};

#endif // CPPFACTORY_DERIVEDCLASSONE_H
