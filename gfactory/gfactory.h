#ifndef  GFACTORY_H
#define  GFACTORY_H

// c++
#include <map>
#include <string>
#include <iostream>
using namespace std;

// dynamic loading
#include "gdl.h"

class GFactoryBase {
public:
	virtual void* Create() = 0;
};


template <class T>
class GFactory : public GFactoryBase
{
	virtual void* Create() override {
		return new T();
	}
};

//

class GManager
{
public:
	// Before instantiating the wanted class we need to register
	// it (as Derived) in the manager first
	// Derived is the derived class, i.e. "Triangle" : "Shape"
	// This implies that the client knows about the derived class (through header)
	// We can register the Derived the map<string, GFactoryBase*> through a GFactory<Derived>
	template <class Derived> void RegisterObjectFactory(string name) {
		factoryMap[name] = new GFactory<Derived>();
		cout << " Registering " << name << " factory. Factory database size is now: " << factoryMap.size() << endl;
	}

	// After registering we can create the object
	// Notice that Base here is the base class, using polymorphism
	// (a call to a member function will cause a different function to
	// be executed depending on the type of object that invokes the function.
	template <class Base> Base* CreateObject(string name) const {
		auto factory = factoryMap.find(name);
		if(factory == factoryMap.end())
			return nullptr;

		cout << " Creating factory " << name << endl;
		return static_cast<Base*>(factory->second->Create());
	}

	void registerDL(string name) {

	}

	template <class T> T* LoadObjectFromLibrary(string name) const {
		
	thisLib = dynamic_lib("./lib" + name + ".dylib");
//		dynamic_lib thisLib("./lib" + name + ".dylib");
//		dynamic_lib *thisLib = new dynamic_lib("./lib" + name + ".dylib");

		cout << " manager loaded with " << thisLib.handle << endl;

		// will return nullptr if handle is null
		return T::instantiate(thisLib.handle);

	}


	template <class T> void DestroyObject(T* object) {
		delete object;
	}


private:
	map<string, GFactoryBase*> factoryMap;
	dynamic_lib thisLib;
//	map<string, GFactoryBase*> factoryMap;
};

#endif
