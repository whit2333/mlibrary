// gemc
#include "ghit.h"

// geant4
#include "G4VVisManager.hh"

// MT definitions, as from:
// https://twiki.cern.ch/twiki/bin/view/Geant4/QuickMigrationGuideForGeant4V10
G4ThreadLocal G4Allocator<GHit>* GHitAllocator = 0;

GHit::GHit(GTouchable *gt, const G4Step* thisStep, string hbs, string cScheme) : G4VHit(),
touchableId(gt),
hitBitSet(hbs),
colorSchema(cScheme)
{
	// build hit information based on the 
}


// add information to the hit
void GHit::addStepInfos(const G4Step* thisStep)
{
	
}


void GHit::Draw()
{
	G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

	if(pVVisManager) {
		setColorSchema();
		
	}
}


// sets marker type, size, open or filled, its color based on its energy deposited
bool GHit::setColorSchema()
{
	
	return false;
}



