#ifndef SECONDFACTORY_H
#define SECONDFACTORY_H

class SecondFactory
{
public:
	virtual void salute() = 0;
	virtual ~SecondFactory() = default;

};


class FirstSecondDerived : SecondFactory
{

public:
	void salute();
};


class SecondSecondDerived : SecondFactory
{

public:
	void salute();
};


#endif // SECONDFACTORY_H
