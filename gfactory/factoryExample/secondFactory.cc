#include "secondFactory.h"
#include "gfactory.h"

#include <iostream>
using namespace std;

void FirstSecondDerived::salute() {
	cout << "factory two number one it works! " << std::endl;
}


void SecondSecondDerived::salute() {
	cout << "factory two number two it works! " << std::endl;
}

