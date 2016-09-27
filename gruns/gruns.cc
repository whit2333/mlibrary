// gruns
#include "gruns.h"

// c++
#include <string>
#include <fstream>
#include <random>
using namespace std;

// progress bar
#include "textProgressBar.h"

GRuns::GRuns(GOptions* gopts)
{
	string filename = gopts->getValue("runWeightsFile");
	defaultRunNumber = gopts->getIntValue("runno");
	runNo = defaultRunNumber;
	isNewRun = false;

	// number of events to process
	int neventsToProcess = gopts->getIntValue("N");

	// if no events to process, exit here
	if(neventsToProcess == 0) {
		printSummary(neventsToProcess);
		return;
	}
	// if there is no filename, the weight map contains only one entry
	else if(filename == "na") {
		runWeights[defaultRunNumber] = 1;
		runEvents[defaultRunNumber]  = neventsToProcess;
		printSummary(neventsToProcess);
		return;
	}
	// there is an available filename
	else {
		ifstream in(filename.c_str());
		if(!in) {
			cerr << " !! Error: can't open input file " << filename << ". Check your spelling. Exiting. " << endl;
			exit(1);
		} else {
			// filling weight map
			while (!in.eof()) {
				int run;
				double weight;
				in >> run >> weight;
				runWeights[run] = weight;
				runEvents[run] = 0;
			}
			// distribute events according to weights
			distributeEvents(neventsToProcess);
		}
		in.close();
	}
}

void GRuns::distributeEvents(int nevts)
{
	// now randomizing the run of each event
	TextProgressBar bar(50, " > Distributing events according to run weights ", 0, nevts);

	// generating random number
	// reference: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
	random_device randomDevice;
	mt19937 generator(randomDevice());
	uniform_real_distribution<> randomDistribution(0, 1);

	for(int i=0; i<nevts; i++) {
		double randomNumber = randomDistribution(generator);

		double ww = 0;
		for(const auto &weight : runWeights) {
			ww += weight.second;
			if(randomNumber <= ww) {
				runEvents[weight.first]++;
				break;
			}
		}

		bar.setProgress(i);
	}


	printSummary(nevts);
}

void GRuns::printSummary(int nevts)
{
	cout << " > Runs have " << nevts << " events" << endl;
	for(const auto &weight : runWeights)
		cout << "    - run: " << weight.first << "\t weight: " << runWeights[weight.first] << "\t  n. events: " << runEvents[weight.first] << endl;

}


int GRuns::getRunNumber(int evn)
{
	int dn = evn - startEvent ;

	double nn = 0;

	for(const auto &events : runEvents) {
		nn += events.second;
		// if we're in the next run batch
		if(dn < nn) {
			// check if this is a new run
			if(events.first != runNo) {
				isNewRun = true;
				runNo = events.first;
			} else {
				// not a new run. nothing to do
				isNewRun = false;
			}
			return events.first;
		}
	}

	// default comes from the option map
	runNo = defaultRunNumber;

	return runNo;
}




map<string, GOption> GRuns::defineOptions()
{
	map<string, GOption> optionsMap;

	optionsMap["startEvent"] = GOption("Start Event Number", 1, "run");
	optionsMap["runno"]      = GOption("Run Number", 1, "run");

	// by default, do not process any event
	optionsMap["N"]          = GOption("Number of events to process", 0, "run");

	optionsMap["runWeightsFile"] = GOption("Text filename with run list and weights", "na", "run");
	optionsMap["runWeightsFile"].addHelp("The text file must have two columns, run# and weight.\n");
	optionsMap["runWeightsFile"].addHelp("For example:\n");
	optionsMap["runWeightsFile"].addHelp(" 11 0.1\n");
	optionsMap["runWeightsFile"].addHelp(" 12 0.7\n");
	optionsMap["runWeightsFile"].addHelp(" 13 0.2\n");
	optionsMap["runWeightsFile"].addHelp("Will simulate 10% of events with run number 11 conditions, 70% for run 12 and 20% for run 13.\n");

	return optionsMap;
}



