#include "gSystem.h"

void GSetup::registerFactory(string factoryType)
{
	if(factoryType == "text") {
		// factory not found, registering it in the manager and loading it into the map
		if(systemFactory.find(factoryType) == systemFactory.end()) {
			gSystemManager.RegisterObjectFactory<GSystemTextFactory>(factoryType);
			systemFactory[factoryType] = gSystemManager.CreateObject<GSystemFactory>(factoryType);
		}
	}
	
}
