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


#endif // SECONDFACTORY_H
