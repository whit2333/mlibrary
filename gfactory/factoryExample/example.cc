#include "gfactory.h"
#include "ShapeFactory.h"
#include "Car.h"

#include <iostream>
using namespace std;

int main()
{
	GManager managerA;
	GManager managerB;

	// A manages FirstFactory
	// registering 3 derived classes from FirstFactory
	managerA.RegisterObjectFactory<Triangle>("triangle");
	managerA.RegisterObjectFactory<Box>("box1");
	managerA.RegisterObjectFactory<Box>("box2");

	// B manages SecondFactory
	// registering one derived class from SecondFactory
//	managerB.RegisterObjectFactory<Dodge>("dodge");
//	managerB.RegisterObjectFactory<Ford>("ford");


	// putting factory in map
	map<string, Shape*> fff;
	fff["triangle"] = managerA.CreateObject<Shape>("triangle");
	fff["box1"]     = managerA.CreateObject<Shape>("box1");
	fff["box2"]     = managerA.CreateObject<Shape>("box2");


	// aShape is same pointer as map element
	Shape* aShape = fff["triangle"];

	map<string, Car*> ggg;
	ggg["dodge"] = managerB.CreateObject<Car>("dodge");

	for(int i=0; i<2; i++) {


		aShape->Area();
		fff["triangle"]->Area();
		fff["box1"]->Area();

		ggg["dodge"]->go();

		cout << fff["triangle"] << " " << aShape << endl;

	}

}



