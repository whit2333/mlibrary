#include "gfactory.h"


template<class BaseClass>
GFactory<BaseClass> * GFactory<BaseClass>::Instance()
{
	static GFactory<BaseClass> factory;
	return &factory;
}


template<class BaseClass>
void GFactory<BaseClass>::RegisterFactoryFunction(string name, function<BaseClass*(void)> classFactoryFunction)
{
	// register the class factory function
	factoryFunctionRegistry[name] = classFactoryFunction;
}


template<class BaseClass>
shared_ptr<BaseClass> GFactory<BaseClass>::Create(string name)
{
	MyBaseClass * instance = nullptr;
	
	// find name in the registry and call factory method.
	auto it = factoryFunctionRegistry.find(name);
	if(it != factoryFunctionRegistry.end())
		instance = it->second();
	
	// wrap instance in a shared ptr and return
	if(instance != nullptr)
		return std::shared_ptr<BaseClass>(instance);
	else
		return nullptr;
}
