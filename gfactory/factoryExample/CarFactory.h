#ifndef SECONDFACTORY_H
#define SECONDFACTORY_H

#include "Car.h"

class Dodge : public Car
{
public:
	void go();
};

extern "C" Car* CarFactory(void) {
	return static_cast<Car*>(new Dodge);
}

class Ford : Car
{

public:
	void go();
};

// this would have to be in a separate file
//extern "C" Car* CarFactory(void) {
//	return static_cast<Car*>(new Ford);
//}


#endif // SECONDFACTORY_H
