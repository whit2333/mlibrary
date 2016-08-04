// frequencySyncSignal framework
#include "frequencySyncSignal.h"

// c++
#include <random>


// remove later
#include <iostream>

// building RF from the start time
oneRFOutput::oneRFOutput(double timeWindow, double startTime, double radioPeriod, double radioInterval)
{

	// generating random number between -timeWindow and timeWindow
	random_device randomDevice;
	mt19937 generator(randomDevice());
	uniform_real_distribution<> randomDistribution(-timeWindow/radioPeriod, timeWindow/radioPeriod);

	double firstRF = startTime + radioPeriod*(int)randomDistribution(generator);

	while(firstRF<0 || firstRF>timeWindow)
		firstRF = startTime + radioPeriod*(int)randomDistribution(generator);

	fillRFValues(firstRF, timeWindow, radioInterval);


}

// building RF from existing RFs
oneRFOutput::oneRFOutput(vector<double> values, double rfsDistance, double timeWindow, double radioInterval)
{
	double thatFirstRf = values.front();

	double firstRF = thatFirstRf - rfsDistance;
	// this RF is rfsDistance away from thatFirstRf.
	if(firstRF < 0 || firstRF > timeWindow)
		 firstRF = thatFirstRf + rfsDistance;

	if(firstRF < 0 || firstRF > timeWindow) {
		cout << "  !! error: RF value is outside the timewindow." << endl;
	}

	fillRFValues(firstRF, timeWindow, radioInterval);


}

void oneRFOutput::fillRFValues(double firstRF, double timeWindow, double radioInterval)
{
	double putRF = firstRF;
	// adding earlier RFs
	while(putRF>0) {
		rfValue.push_back(putRF);
		putRF -= radioInterval;
	}

	// adding later RFs
	putRF = firstRF + radioInterval;
	while(putRF<timeWindow) {
		rfValue.push_back(putRF);
		putRF += radioInterval;
	}

	// sorting vector - adding to ids
	sort(rfValue.begin(), rfValue.end());

	// adding the id
	for(int n = 0; n<rfValue.size(); n++) {
		rfID.push_back(n+1);
	}

}


//! overloading "<<" to print this class
ostream &operator<<(ostream &stream, FrequencySyncSignal s)
{
	stream << " Time Window: "   << s.timeWindow;
	stream << " Event Start Time: "   << s.startTime << endl;
	stream << " Radio Frequency: "   << s.radioFrequency << " MHz - Period is " << radioPeriod << "ns" << endl;

	return stream;
}




