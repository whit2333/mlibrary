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
	GManager(int v = 0) : verbosity(v) {}
	
public:
	// Before instantiating the wanted class we need to register
	// it (as Derived) in the manager first
	// Derived is the derived class, i.e. "Triangle" : "Shape"
	// This implies that the client knows about the derived class (through header)
	// We can register the Derived the map<string, GFactoryBase*> through a GFactory<Derived>
	template <class Derived> void RegisterObjectFactory(string name) {
		factoryMap[name] = new GFactory<Derived>();
		if(verbosity > 0) {
			cout << " GManager: Registering " << name << " factory.";
			cout << " Factory database size is now: " << factoryMap.size() << endl;
		}
	}
	
	// After registering we can create the object
	// Notice that Base here is the base class, using polymorphism
	// (a call to a member function will cause a different function to
	// be executed depending on the type of object that invokes the function.
	template <class Base> Base* CreateObject(string name) const {
		auto factory = factoryMap.find(name);
		if(factory == factoryMap.end())
			return nullptr;
		if(verbosity > 0) {
			cout << " GManager: Creating factory " << name << endl;
		}
		return static_cast<Base*>(factory->second->Create());
	}
	
	// setting file name depending on OS
	void registerDL(string name) {
		dlMap[name] = new dynamic_lib("./lib" + name + ".dylib");
		if(verbosity > 0) {
			cout << " GManager: Loading DL " << name << endl;
		}
	}
	
	template <class T> T* LoadObjectFromLibrary(string name) {
		// will return nullptr if handle is null
		
		if(verbosity > 0) {
			cout << " GManager: Creating factory " << name << endl;
		}
		return T::instantiate(dlMap[name]->handle);
	}
	
	
	template <class T> void destroyObject(T* object) {
		delete object;
	}
	
	void clearDLMap() {
		for(auto &i : dlMap) {
			delete i.second;
		}
	}
	
	
private:
	map<string, GFactoryBase*> factoryMap;
	// the reason to keep this map is to keep the pointers in memory
	// for some reason declaring a dynamic_lib local variable in LoadObjectFromLibrary
	// scope does not work
	map<string, dynamic_lib*> dlMap;
	
	int verbosity;
};

#endif
