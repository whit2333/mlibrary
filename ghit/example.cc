/// \file example.cc

// example instantiating ghit

// gtouchable
#include "gtouchable.h"

// ghit
#include "ghit.h"

//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	GTouchable ctof("ctof", "paddle 22");

	
	// a bitset
	bitset<NHITBITS> hitBitSet("000000");
	
	// hit with null G4Step (not used)
	GHit *newHit = new GHit(&ctof, nullptr, hitBitSet, "scheme");
	
	newHit->addStepInfos(nullptr);
	

	
	return 1;
}

