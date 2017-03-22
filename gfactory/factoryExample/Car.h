#ifndef CAR_H
#define CAR_H

#include "gfactory.h"

class Car
{
public:
	virtual void go() = 0;
	virtual ~Car() = default;
};


static Car* instantiate(const dynamic_lib_handle handle) {
	
	if (handle == nullptr) return nullptr;
	
	void *maker = dlsym(handle , "factory");
	
	if (maker == nullptr) return nullptr;
	
	typedef Car* (*fptr)();
	fptr func = reinterpret_cast<fptr>(reinterpret_cast<void*>(maker));
	
	return func();
}


#endif // CAR_H
