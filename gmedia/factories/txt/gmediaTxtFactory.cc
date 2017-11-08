// txt gmedia
#include "gmediaTxtFactory.h"

// tells the DLL how to create a GMediaFactory
extern "C" GMedia* GMediaFactory(void) {
	return static_cast<GMedia*>(new GMediaTxtFactory);
}
