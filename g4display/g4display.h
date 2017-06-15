#ifndef  G4DISPLAY_H
#define  G4DISPLAY_H

// mlibrary
#include "goptions.h"

// c++
#include <string>

class G4Display {

public:
	G4Display(GOptions* gopt);

public:
	// G4Display options
	static map<string, GOption> defineOptions();


};


#endif
