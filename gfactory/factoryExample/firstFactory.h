#ifndef FIRSTFACTORY_H
#define FIRSTFACTORY_H

#include <string>
using namespace std;

class FirstFactory
{
public:
	virtual void Greet() = 0;
	virtual ~FirstFactory() = default;

};


class FirstFirstDerived : FirstFactory
{

public:
	void Greet();
};


class SecondFirstDerived : FirstFactory
{

public:
	void Greet();
};


#endif // FIRSTFACTORY_H
