// gruns
#include "gruns.h"

// c++
#include <string>
#include <fstream>
#include <random>
using namespace std;

GRuns::GRuns(GOptions* gopts)
{
	string filename = gopts->getValue("runWeightsFile");
	defaultRunNumber = gopts->getIntValue("runno");

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
			while (!in.eof())
			{
				int run;
				double weight;
				in >> run >> weight;
				runWeights[run] = weight;
				runEvents[run] = 0;
			}
			// distribute events according to weights
			distributeEvents(neventsToProcess);
		}
	}
}

void GRuns::distributeEvents(int nevts)
{
	// now randomizing the run of each event
	for(int i=0; i<nevts; i++)
	{
		// generating random number
		// reference: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
		random_device rd;
		mt19937 gen(rd());
		uniform_real_distribution<> dis(0, 1);
		double randomNumber = dis(gen);

		double ww = 0;
		for(const auto &weight : runWeights)
		{
			ww += weight.second;
			if(randomNumber <= ww)
			{
				runEvents[weight.first]++;
				break;
			}
		}
	}
	printSummary(nevts);
}

void GRuns::printSummary(int nevts)
{
	cout << " > Runs have " << nevts << " events" << endl;
	for(const auto &weight : runWeights)
		cout << "    - run: " << weight.first << "\t weight: " << runWeights[weight.first] << "\t  n. events: " << runEvents[weight.first] << endl;

}
