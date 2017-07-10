#ifndef G4NATIVESETUPFACTORY_H
#define G4NATIVESETUPFACTORY_H 1

// g4volume
#include "../g4SetupFactory.h"

// system factory
class G4NativeSetupFactory : G4SetupFactory
{
public:
	bool loadG4Setup(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s) {
		
		int verbosity = gopt->getInt("g4volumev");
		
		if(verbosity > 1) {
			G4cout << g4setupLogHeader << " Building geant4 volumes." << endl;
		}

		bool sbuild = buildSolid(gopt, s, g4s);
		bool lbuild = buildLogical(gopt, s, g4s);
		bool pbuild = buildPhysical(gopt, s, g4s);
		
		if(verbosity > 2) {
			string vname = s->getName();
			string solid = sbuild ? " solid build, "    : " solid not build, ";
			string logic = lbuild ? " logical build, "  : " logical not not build, ";
			string physi = pbuild ? " physical build. " : " physical not build. ";
			G4cout << " - g4setup: volume <" << vname << "> " << solid << logic << physi << endl;
		}
		
		if(sbuild && lbuild && pbuild) {
			return true;
		} else {
			return false;
		}
	}

private:
	// PRAGMA TODO: is GOptions necessary?
	bool buildSolid(   GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s) ;
	bool buildLogical( GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s);
	bool buildPhysical(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s);

	// solid
	vector<string> descriptionsOfParameters(GVolume *s); // returns description of geant4 constructor parameters
	vector<double> checkAndReturnParameters(GVolume *s); // checks and returns the number of parameters matches the geant4 constructor
};


#endif
