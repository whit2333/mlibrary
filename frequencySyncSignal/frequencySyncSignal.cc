// frequencySyncSignal framework
#include "frequencySyncSignal.h"

// c++
#include <random>


// remove later
#include <iostream>


oneRFOutput::oneRFOutput(double timeWindow, double startTime, double radioPeriod, double radioInterval)
{

	// generating random number between -timeWindow and timeWindow
	random_device randomDevice;
	mt19937 generator(randomDevice());
	uniform_real_distribution<> randomDistribution(-timeWindow/radioPeriod, timeWindow/radioPeriod);

	double firstRF = startTime + radioPeriod*(int)randomDistribution(generator);

	while(firstRF<0 || firstRF>timeWindow)
		firstRF = startTime + radioPeriod*(int)randomDistribution(generator);

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

	// sorting vector.
	sort(rfValue.begin(), rfValue.end());
	for(auto &v : rfValue) {
		cout << "after " << v << endl;
	}
	
}


