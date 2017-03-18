#ifndef  GFACTORY_H
#define  GFACTORY_H


#include <string>
#include <functional>
#include <map>
using namespace std;

class MyBaseClass
{
public:
	virtual void doSomething() = 0;
};


// The factory - implements singleton pattern!
class GFactory
{
public:
	// Get the single instance of the factory
	static GFactory * Instance();
	
	// register a factory function to create an instance of className
	void RegisterFactoryFunction(string name, function<MyBaseClass*(void)> classFactoryFunction);
	
	// create an instance of a registered class
	shared_ptr<MyBaseClass> Create(string name);
	
private:
	// a private ctor
	GFactory(){}
	
	// the registry of factory functions
	map<string, function<MyBaseClass*(void)>> factoryFunctionRegistry;
	
};

template<class T, class BaseClass>
class Registrar {
public:
	Registrar(string className)
	{
		// register the class factory function
		// using a lambda function
		GFactory::Instance()->RegisterFactoryFunction(className,
													  [](void) -> BaseClass * { return new T();});
	}
};





#endif
