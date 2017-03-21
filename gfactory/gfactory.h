#ifndef  GFACTORY_H
#define  GFACTORY_H

// c++
#include <map>
#include <string>
using namespace std;

class GFactoryBlock {
public:
	virtual void* Create() = 0;
};


template <class T>
class GFactory : public GFactoryBlock
{
	virtual void* Create() override
	{
		return new T();
	}
};


class GManager
{
public:
	template <class T> void RegisterObjectFactory(string name) {
		factoryMap[name] = new GFactory<T>();
	}

	template <class T> T* CreateObject(string name) const;
//	template <class T> T* CreateObject(string name) const {
//		auto factory = factoryMap.find(name);
//		if(factory == factoryMap.end())
//			return nullptr;
//
//		return static_cast<T*>(factory->second->Create());
//	}

	template <class T> void DestroyObject(T* object) {
		delete object;
	}


private:
	map<string, GFactoryBlock*> factoryMap;
};


#include "gfactory.cc"

#endif
