#ifndef FREQUENCYSYNCSIGNAL_H
#define FREQUENCYSYNCSIGNAL_H

// c++
#include <string>
#include <vector>
using namespace std;

class oneRFOutput {
public:
	oneRFOutput(double timeWindow, double startTime, double radioPeriod, double radioInterval);

private:
	vector<double> rfID;
	vector<double> rfValue;
};

class FrequencySyncSignal {

	// constructor from string.
	// This will be replaced by a goption later on
	FrequencySyncSignal(string setup);

private:
	double timeWindow;     // total timewindow of one event - in ns
	double startTime;      // event start time
	double radioFrequency; // radiofrequency - in GHz
	double radioPeriod;    // period - in ns. It's 1/radioFrequency
	double radioInterval;  // interval between RF bunches

	vector<int> rfsDistance; // distance (in number of radioInterval) between multiple RF signals

	// output is a 2D vector:
	// The number of Radiofrequency banks is nRadiofrequency
	// The number of Radiofrequency signals within one bank is defined by
	// filling the timewindow based on the radioFrequency
	vector<oneRFOutput> output;


public:
	vector<oneRFOutput> getOutput() {return  output;}
};



#endif
