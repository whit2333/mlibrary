#include "gfactory.h"
#include "ShapeFactory.h"
#include "Car.h"

#include <iostream>
using namespace std;

int main()
{
	GManager managerA;     // loads known classes Triangle and Box from the base Shape
	GManager managerB(1);  // loads DLL that instantiate derived factories - we only know of the base one in this case "Car"

	// A manages Shapes
	// registering 3 shape classes
	// notice, here we know of them through the header
	managerA.RegisterObjectFactory<Triangle>("triangle");
	managerA.RegisterObjectFactory<Box>("box1");
	managerA.RegisterObjectFactory<Box>("box2");

	// putting A factory in map
	map<string, Shape*> fff;
	fff["triangle"] = managerA.CreateObject<Shape>("triangle");
	fff["box1"]     = managerA.CreateObject<Shape>("box1");
	fff["box2"]     = managerA.CreateObject<Shape>("box2");

	// aShape is same pointer as map element
	Shape* aShape = fff["triangle"];

	// B manages Cars. Notice, we do not need the derived class headers here!
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



