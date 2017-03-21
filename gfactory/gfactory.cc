// #include "gfactory.h"


template <class T> T* GManager::CreateObject(string name) const
{
	auto factory = factoryMap.find(name);
	if(factory == factoryMap.end())
		return nullptr;

	return static_cast<T*>(factory->second->Create());
}
