/// \file example.cc

// example on how to use the frequencySyncSignal library

// frequencySyncSignal framework
#include "frequencySyncSignal.h"

// remove later
#include <iostream>

//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	if(argc != 5) {
		cout << " incorrect number of arguments " << endl;
		return 1;
	} else {
		double timeWindow    = stod(argv[1]);  // total timewindow of one event - in ns
		double startTime     = stod(argv[2]);  // event start time
		double radioPeriod   = stod(argv[3]);  // period - in ns. It's 1/radioFrequency
		double radioInterval = stod(argv[4]);  // interval between RF bunches

		cout << " > timeWindow: " << timeWindow << endl;
		cout << " > startTime: " << startTime << endl;
		cout << " > radioPeriod: " << radioPeriod << endl;
		cout << " > radioInterval: " << radioInterval << endl;

		oneRFOutput oro(timeWindow, startTime, radioPeriod, radioInterval);

	}
}

