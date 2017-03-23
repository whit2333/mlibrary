#include "gfactory.h"
#include "ShapeFactory.h"
#include "Car.h"

#include <iostream>
using namespace std;

int main()
{
	GManager managerA;  // loads known classes Triangle and Box from the base Shape
	GManager managerB;  // loads DLL that instantiate derived factories - we only know of the base one in this case "Car"

	// A manages FirstFactory
	// registering 3 shape classes
	// notice, here we know of them through the header
	managerA.RegisterObjectFactory<Triangle>("triangle");
	managerA.RegisterObjectFactory<Box>("box1");
	managerA.RegisterObjectFactory<Box>("box2");

	// B manages SecondFactory
	// registering one derived class from SecondFactory
//	managerB.RegisterObjectFactory<Dodge>("dodge");
//	managerB.RegisterObjectFactory<Ford>("ford");


	// opening dl
//	dynamic_lib thisLib("./libdodgeFactory.dylib");
//	auto test = Car::instantiate(thisLib.handle);
//	cout << " TEST " <<  test << " " << typeid(test).name() <<  endl;
//	test->go();

	// putting factory in map
	map<string, Shape*> fff;
	fff["triangle"] = managerA.CreateObject<Shape>("triangle");
	fff["box1"]     = managerA.CreateObject<Shape>("box1");
	fff["box2"]     = managerA.CreateObject<Shape>("box2");


	// aShape is same pointer as map element
	Shape* aShape = fff["triangle"];

	managerB.registerDL("dodgeFactory");
	managerB.registerDL("fordFactory");
	
	map<string, Car*> ggg;
	ggg["dodge"] = managerB.LoadObjectFromLibrary<Car>("dodgeFactory");
	ggg["ford"]  = managerB.LoadObjectFromLibrary<Car>("fordFactory");
	Car* aCar = ggg["ford"];

	for(int i=0; i<2; i++) {

		aShape->Area();
		fff["triangle"]->Area();
		fff["box1"]->Area();

		ggg["dodge"]->go();
		ggg["ford"]->go();

		cout << " Shape pointers: " << fff["triangle"] << " " << aShape << endl;
		cout << " Car pointers: " << ggg["ford"] << " " << aCar << endl;

	}

	// why this need to be cleared here?
	managerB.clearDLMap();

	
	
	
}



