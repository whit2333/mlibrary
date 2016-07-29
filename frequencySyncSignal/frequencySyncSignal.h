#ifndef FREQUENCYSYNCSIGNAL_H
#define FREQUENCYSYNCSIGNAL_H

// c++
#include <string>
#include <vector>
using namespace std;

class oneRFOutput {

};

class FrequencySyncSignal {

	// constructor from string.
	// This will be replaced by a goption later on
	FrequencySyncSignal(string setup);

private:
	double timeWindow;     // total timewindow of one event
	double startTime;      // event start time
	double radioFrequency; // radiofrequency - in GHz
	double radioInterval;  // radiointerval - in ns. It's 1/radioFrequency

	double nRadiofrequency;  // number of multiple signals, defined at construction
	double signalsDistance;  // distance between RF signals

	// output is a 2D vector:
	// The number of Radiofrequency banks is nRadiofrequency
	// The number of Radiofrequency signals within one bank is defined by
	// filling the timewindow based on the radioFrequency
	vector<vector <double > > output;

};



#endif
