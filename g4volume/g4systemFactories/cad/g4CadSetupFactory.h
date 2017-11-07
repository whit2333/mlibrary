#ifndef G4CADSETUPFACTORY_H
#define G4CADSETUPFACTORY_H 1

// g4volume
#include "../g4SetupFactory.h"

// system factory
class G4CadSetupFactory : G4SetupFactory
{
public:
	bool loadG4Setup(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s) {
		
		int verbosity = gopt->getInt("g4volumev");
		
		if(verbosity > GVERBOSITY_SUMMARY) {
			G4cout << g4setupLogHeader << " Importing cad volumes." << G4endl;
		}
		
		bool sbuild = buildSolid(gopt, s, g4s);
		bool lbuild = buildLogical(gopt, s, g4s);
		bool pbuild = buildPhysical(gopt, s, g4s);
		
		if(verbosity == GVERBOSITY_ALL) {
			string vname = s->getName();
			string solid = sbuild ? " solid build, "    : " solid not build, ";
			string logic = lbuild ? " logical build, "  : " logical not not build, ";
			string physi = pbuild ? " physical build. " : " physical not build. ";
			G4cout << g4setupLogHeader << " volume <" << vname << "> " << solid << logic << physi << G4endl;
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
	
};


#endif
