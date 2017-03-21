#include "gfactory.h"
#include "firstFactory.h"
#include "secondFactory.h"


int main()
{
	GManager managerA;
	GManager managerB;

	managerA.RegisterObjectFactory<FirstFirstDerived>("a1");
	managerB.RegisterObjectFactory<SecondFirstDerived>("a2");

	auto test  = managerA.CreateObject<FirstFactory>("a1");
	test->Greet();

	for(int i=0; i<5; i++) {
		auto test   = managerA.CreateObject<FirstFactory>("a1");
		auto test2  = managerB.CreateObject<SecondFactory>("a2");


		test->Greet();
		test2->salute();


		managerA.DestroyObject(test);
		managerB.DestroyObject(test2);
	}
}



