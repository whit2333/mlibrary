#ifndef  GHIT_H
#define  GHIT_H 1

// geant4
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4Step.hh"

// mlibrary
#include "gtouchable.h"

// c++
#include <bitset>

// GHIT Bitset:
//
// 1st bit: energy deposited, time
// 2nd bit: global position, step length
// 3rd bit: local position
// 4th bit: track informations: momentum, total energy, vertex, pid, track id
// 5th bit: mother particle track information. This is created after the event
// 6th bit: meta information: magnetic field. process id name that created the particle


class GHit : public G4VHit
{

	GHit(GTouchable *gt, const G4Step* thisStep, string hbs = "000000", string cSchema = "default");

	inline void* operator new(size_t);
	inline void  operator delete(void*);

	// add information to the hit
	addStepInfos(const G4Step* thisStep);
	
	// draws an object at hit location
	void Draw();

private:
	bitset<6> hitBitSet;
	
	GTouchable touchableId;

	// only used if pVVisManager exist (interactive mode)
	string colorSchema;

private:
	bool setColorSchema();
	
	// hit data is collected for every step
	vector<double> stepEdep, stepTime;   // bit 1
	
	vector<G4ThreeVector> stepGlobalPos; // bit 2
	vector<double> stepStep;             // bit 2

	// geant4 touchable hierarchy
	vector<int> g4TouchableHierarchyID;
	
public:
	
	
};


typedef G4THitsCollection<GHit> GHitsCollection;


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

