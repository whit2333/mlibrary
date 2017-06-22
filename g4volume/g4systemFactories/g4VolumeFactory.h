#ifndef G4SETUPFACTORY_H
#define G4SETUPFACTORY_H 1

// mlibrary
#include "goptions.h"

// g4volume
#include "g4volume.h"


// G4SetupFactory factory
class G4SetupFactory
{
public:
	// returns true if the system could be built
	// returns false if dependencies are not met
	virtual bool loadG4Setup(GOptions* gopt, G4Setup *s) = 0;
	virtual ~G4SetupFactory() = default;


};

#endif
