#ifndef  GFACTORY_H
#define  GFACTORY_H

// c++
#include <map>
#include <string>
#include <iostream>
using namespace std;

class GFactoryBlock {
public:
	virtual void* Create() = 0;
};


template <class T>
class GFactory : public GFactoryBlock
{
	virtual void* Create() override {
		return new T();
	}
};


class GManager
{
public:
	template <class T> void RegisterObjectFactory(string name) {
		factoryMap[name] = new GFactory<T>();
		cout << " Registering " << name << " factory. Factory database size is now: " << factoryMap.size() << endl;
	}

	template <class T> T* CreateObject(string name) const {
		auto factory = factoryMap.find(name);
		if(factory == factoryMap.end())
			return nullptr;

		cout << " Creating factory " << name << endl;
		return static_cast<T*>(factory->second->Create());
	}

	template <class T> void DestroyObject(T* object) {
		delete object;
	}


private:
	map<string, GFactoryBlock*> factoryMap;
};

// plugin loading functions
#include <dlfcn.h>

typedef void* dynamic_lib_handle;

static dynamic_lib_handle load_lib(const string& path);
static void close_lib(dynamic_lib_handle handle);

struct dynamic_lib {
	dynamic_lib_handle  handle;
	string			path;
	
	dynamic_lib(string p) : path(p), handle(nullptr) {}
	
	~dynamic_lib() {
		if (handle != nullptr)
			close_lib(handle);
	}
};


static dynamic_lib_handle load_lib(const string& path) {
	cout << "Trying to open: " << path << std::endl;
	return dlopen(path.data() , RTLD_NOW); // get a handle to the lib, may be nullptr.
	// RTLD_NOW ensures that all the symbols are resolved immediately. This means that
	// if a symbol cannot be found, the program will crash now instead of later.
}

static void close_lib(dynamic_lib_handle handle) {
	dlclose(handle);
}

#endif
