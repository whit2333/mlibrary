#include "gfactory.h"
#include "firstFactory.h"
#include "secondFactory.h"

#include <iostream>
using namespace std;

int main()
{
	GManager managerA;
	GManager managerB;

	// A manages FirstFactory
	// registering 3 derived classes from FirstFactory
	managerA.RegisterObjectFactory<FirstFirstDerived>("a11");
	managerA.RegisterObjectFactory<SecondFirstDerived>("a12");
	managerA.RegisterObjectFactory<SecondFirstDerived>("a2");

	// B manages SecondFactory
	// registering one derived class from SecondFactory
	managerB.RegisterObjectFactory<FirstSecondDerived>("a2");


	// creating one factory
	auto test  = managerA.CreateObject<FirstFactory>("a11");
	test->Greet();

	// putting factory in map
	map<string, FirstFactory*> fff;
	fff["a1"] = test;

	// aaa is same pointer
	FirstFactory* aaa = fff["a1"];

	for(int i=0; i<5; i++) {


		fff["a1"]->Greet();

		cout << fff["a1"] << " " << aaa << endl;

	}
	managerA.DestroyObject(test);

}



