#ifndef CTOFROUTINEEXAMPLE
#define CTOFROUTINEEXAMPLE 1


#include "gDynamic.h"


class CTofRoutineExample : GDynamic {
	
};

extern "C" GDynamic* GDynamicFactory(void) {
	return static_cast<GDynamic*>(new CTofRoutineExample);
}


#endi
