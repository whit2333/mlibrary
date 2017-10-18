#ifndef  GHIT_H
#define  GHIT_H 1

// geant4
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"

// mlibrary
#include "gtouchable.h"


// GHIT STAGE:
// A stage is an int that defines how much information is being stored in ghit
// PRAGMA TODO: this should be code, activated with & like the binary
// 0: energy deposited, time
// 1: global position, step length
// 2: local position
// 3: track informations: momentum, total energy, vertex, pid, track id
// 4: mother particle track information. This is created after the event


class GHit : public G4VHit
{

	GHit(GTouchable gt, int hitstage = 0, string cSchema = "default");

	inline void* operator new(size_t);
	inline void  operator delete(void*);

	// draws an object at hit location
	void Draw();

private:
	int hitStage;
	
	GTouchable touchableId;

	// only used if pVVisManager exist (interactive mode)
	string colorSchema;

private:
	bool setColorSchema();
	
	// hit data is collected for every step
	vector<double> stepEdep, stepTime;   // stage 0
	
	vector<G4ThreeVector> stepGlobalPos; // stage 1
	vector<double> stepStep;             // stage 1

	// geant4 touchable hierarchy
	vector<int> g4TouchableHierarchyID;
	
public:
	
	
};


typedef G4THitsCollection<GHit> GHitCollection;


// MT definitions, as from:
// https://twiki.cern.ch/twiki/bin/view/Geant4/QuickMigrationGuideForGeant4V10
extern G4ThreadLocal G4Allocator<GHit>* GHitAllocator;

inline void* GHit::operator new(size_t)
{
	if(!GHitAllocator) GHitAllocator = new G4Allocator<GHit>;
	return (void *) GHitAllocator->MallocSingle();
}

inline void GHit::operator delete(void *hit)
{
	GHitAllocator->FreeSingle((GHit*) hit);
}


#endif

