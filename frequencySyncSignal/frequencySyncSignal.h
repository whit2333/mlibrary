#ifndef FREQUENCYSYNCSIGNAL_H
#define FREQUENCYSYNCSIGNAL_H

// c++
#include <string>
#include <vector>
using namespace std;

class FrequencySyncSignal {

	// constructor from string.
	// This will be replaced by a goption later on
	FrequencySyncSignal(string setup);

private:
	double timeWindow;
	double startTime;
	double radioFrequency;
	double radioInterval;
	double signalsDistance;

};



#endif
