// g4volume
#include "g4CadSetupFactory.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

// geant4
#include "G4VSolid.hh"

// cadmesh
#include "CADMesh.hh"

bool G4CadSetupFactory::buildSolid(GOptions* gopt, GVolume *s, map<string, G4Volume*> *g4s)
{
	int    verbosity = gopt->getInt("g4volumev");
	string logVolume = gopt->getString("logVolume");
	string vname = s->getName();

	bool depVerbosity = (verbosity == GVERBOSITY_ALL) || (vname == logVolume);

	// check dependencies first
	if(!checkSolidDependencies(depVerbosity, s, g4s)) return false;

	// if the g4volume doesn't exist, create one and add it to the map
	G4Volume *thisG4Volume = nullptr;

	// check if g4s already exists
	if(g4s->find(vname) != g4s->end()) {
		thisG4Volume = (*g4s)[vname];
		// if the solid is already built, nothing to do
		if(thisG4Volume->getSolid() != nullptr) return true;
	} else {
		thisG4Volume = new G4Volume();
		// adding volume to the map
		(*g4s)[vname] = thisG4Volume;
	}

	// importing mesh
        auto cmesh = CADMesh::TessellatedMesh::FromPLY((char *) s->getImportedFile().c_str());
	//CADMesh *cmesh = new CADMesh( (char *) s->getImportedFile().c_str() ) ;
	cmesh->SetScale(mm);
	cmesh->SetReverse(false);

	
	thisG4Volume->addSolid(cmesh->GetSolid(), verbosity);
	
	return true;
}





