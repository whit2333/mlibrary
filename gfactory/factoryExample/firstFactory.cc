#include "firstFactory.h"
#include "gfactory.h"

#include <iostream>
using namespace std;

void FirstFirstDerived::Greet() {
	cout << "factory one number one it works! " << std::endl;
}


void SecondFirstDerived::Greet() {
	cout << "factory two number two it works! " << std::endl;
}

