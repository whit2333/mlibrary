#ifndef FREQUENCYSYNCSIGNAL_H
#define FREQUENCYSYNCSIGNAL_H

// c++
#include <string>
#include <vector>
using namespace std;

class oneRFOutput {
public:
	oneRFOutput(double timeWindow, double startTime, double radioPeriod, double radioInterval);
	oneRFOutput(vector<double> values, double rfsDistance, double timeWindow, double radioInterval);

	vector<double> getValues() { return rfValue;}
private:
	vector<double> rfID;
	vector<double> rfValue;

private:
	void fillRFValues(double firstRF, double timeWindow, double radioInterval);

	friend ostream &operator<<(ostream &stream, oneRFOutput);


};

class FrequencySyncSignal {

public:
	// constructor from string.
	// This will be replaced by a goption later on
	FrequencySyncSignal(string setup);

private:
	// these quantities are kept here for documentation
	// to build RFoutputs they do not need to be members
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

	//! overloading the << operator
	friend ostream &operator<<(ostream &stream, FrequencySyncSignal);

};



#endif
