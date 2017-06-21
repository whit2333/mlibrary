#ifndef G4SYSTEMFACTORY_H
#define SG4YSTEMFACTORY_H 1

// mlibrary
#include "goptions.h"

// gVolume
#include "g4System.h"


// system factory
class G4SetupFactory
{
public:
	// returns true if the system could be built
	// returns false if dependencies are not met
	virtual bool loadG4Setup(GOptions* gopt, G4Setup *s) = 0;
	virtual ~G4SetupFactory() = default;

};

#endif
