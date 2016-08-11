// frequencySyncSignal framework
#include "frequencySyncSignal.h"

// c++
#include <random>
#include <iostream>

// gstring
#include "gstring.h"
using namespace gstring;

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
ostream &operator<<(ostream &stream, oneRFOutput s)
{
	for(unsigned j=0; j< s.rfID.size(); j++) {
		stream << "  - RFID: "   << s.rfID[j] << "   RF Value: " << s.rfValue[j] << endl;

	}

	return stream;

}

//! overloading "<<" to print this class
ostream &operator<<(ostream &stream, FrequencySyncSignal s)
{
	stream << " Time Window: "   << s.timeWindow;
	stream << ", event Start Time: "   << s.startTime << endl;
	stream << " Radio Frequency: "   << s.radioFrequency << " MHz: Period is " << s.radioPeriod << "ns" << endl;
	stream << " Distance between RF buckets "   << s.radioInterval << " ns" << endl;

	for(unsigned i=0; i<s.rfsDistance.size(); i++) {
		stream << " RF signal n. <" << i+2 << "> is " <<  s.rfsDistance[i] << " ns away." << endl;
	}

	for(unsigned i=0; i<s.output.size(); i++) {
		stream << " > RF Output n. " << i+1 << ":" << endl;
		stream << s.output[i] ;
	}

	return stream;
}


FrequencySyncSignal::FrequencySyncSignal(string setup)
{

	unsigned long numberOfArguments = 4;

	// setup is a string with at least 6 entries.
	// any entry after that will add an additional RFOutput
	vector<string> parsedSetup = getStringVectorFromString(setup);
	if(parsedSetup.size() < numberOfArguments) {
		cout << " !! Error: FrequencySyncSignal initializer incomplete: >" << setup << "< has not enough parameters, at least "
		<<  numberOfArguments << " needed. Exiting" << endl;
		exit(0);
	}

	timeWindow     = stod(parsedSetup[0]);
	startTime      = stod(parsedSetup[1]);
	radioFrequency = stod(parsedSetup[2]);
	radioPeriod    = 1.0/radioFrequency; // GHz > ns
	radioInterval  = stod(parsedSetup[3]);


	// do nothing if timewindow is 0
	if(timeWindow ==0) {
		cout << " ! Warning: timewindow is set to 0. No RF output." << endl;
		return;
	}
	// first RF
	output.push_back(oneRFOutput(timeWindow, startTime, radioPeriod, radioInterval));

	// other signals
	if(parsedSetup.size() > numberOfArguments) {
		vector<double> values = output[0].getValues();
		unsigned long remainingNRF = parsedSetup.size() - numberOfArguments;
		for(unsigned i=0; i<remainingNRF; i++) {
			rfsDistance.push_back(stod(parsedSetup[numberOfArguments+i]));
			output.push_back(oneRFOutput(values, rfsDistance[i], timeWindow, radioInterval));
		}
	}
}
















