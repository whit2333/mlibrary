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

class MyBaseClass2
{
public:
	virtual void doSomethingElse() = 0;
};


// The factory - implements singleton pattern!
template<class BaseClass>
class GFactory
{
public:
	// Get the single instance of the factory
	static GFactory<BaseClass> * Instance();
	
	// register a factory function to create an instance of className
	void RegisterFactoryFunction(string name, function<BaseClass*(void)> classFactoryFunction);
	
	// create an instance of a registered class
	shared_ptr<BaseClass> Create(string name);
	
private:
	// a private ctor
	GFactory<BaseClass>(){}
	
	// the registry of factory functions
	map<string, function<BaseClass*(void)>> factoryFunctionRegistry;
};

template<class T, class BaseClass>
class Registrar {
public:
	Registrar(string className)
	{
		// register the class factory function
		// using a lambda function
		GFactory<BaseClass>::Instance()->RegisterFactoryFunction(className,
													  [](void) -> BaseClass * { return new T();});
	}
};





#endif
