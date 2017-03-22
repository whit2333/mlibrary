#ifndef SECONDFACTORY_H
#define SECONDFACTORY_H

class Car
{
public:
	virtual void go() = 0;
	virtual ~Car() = default;
};


class Dodge : Car
{

public:
	void go();
};


class Ford : Car
{

public:
	void go();
};


#endif // SECONDFACTORY_H
