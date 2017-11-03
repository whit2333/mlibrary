// gruns
#include "gruns.h"

// c++
#include <string>
#include <fstream>
#include <random>
using namespace std;

// progress bar
#include "textProgressBar.h"

GRuns::GRuns(GOptions* gopts, map<string, GDynamic*> *gDigi) : gDigitizationGlobal(gDigi)
{
	verbosity     = gopts->getInt("grunv");
	nEventsBuffer = gopts->getInt("nEventsBuffer");

	int neventsToProcess = gopts->getInt("n");
	// nothing to do here
	if(neventsToProcess == 0) return;
	
	string filename = gopts->getString("runWeightsFile");
	
	// no filename, using run number from options,
	// number of events from options
	if(filename == "na" && neventsToProcess > 0 ) {
		runEvents[gopts->getInt("runno")]  = neventsToProcess;
		return;
	} else {
		// there is an available filename
		ifstream in(filename.c_str());
		if(!in) {
			cerr << GRUNERRMSGITEM << " Error: can't open run weights input file " << filename << ". Check your spelling. Exiting. " << endl;
			exit(1);
		} else {
			if(verbosity > 0) {
				cout << endl << GRUNLOGMSGITEM " Loading run weights from " << filename << endl;
			}
			// filling weight map
			while (!in.eof()) {
				int run;
				double weight;
				in >> run >> weight;
				listOfRuns.push_back(run);
				runWeights[run] = weight;
				runEvents[run] = 0;
			}
			// distribute events according to weights
			distributeEvents(neventsToProcess);
		}
		in.close();
		if(verbosity == 3) {
			printRunsDetails(neventsToProcess);
		}
	}
}

void GRuns::distributeEvents(int nevts)
{
	// now randomizing the run of each event
	TextProgressBar bar(50, string(GRUNLOGMSGITEM) + " Distributing events according to run weights ", 0, nevts);
	
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
}

void GRuns::printRunsDetails(int neventsToProcess)
{
	int ntot = 0;
	cout << GRUNLOGMSGITEM << " GRuns initialized with " << neventsToProcess << " events distributed among " << runWeights.size() << " runs:" << endl;
	if(verbosity > GVERBOSITY_SILENT) {
		
		for(const auto &weight : runWeights) {
			cout << GRUNLOGMSGITEM << GRUNLOGMSGITEM << " run: " << weight.first << "\t weight: " << runWeights[weight.first] << "\t  n. events: " << runEvents[weight.first] << endl;
			ntot += runEvents[weight.first];
		}
	}
}

// sums number of events across all runs
int GRuns::getTotalNumberOfEvents()
{
	int n = 0;
	
	for(auto rEvents : runEvents) {
		n += rEvents.second;
	}
	
	return n;
}


// this will:
// initiate all available gdynamic plugins for each run
// run beamOn for each run
// log on screen infos if enough verbosity
int GRuns::processEvents()
{
	G4UImanager *g4uim   = G4UImanager::GetUIpointer();
	
	for(auto &run : runEvents) {
		
		int runNumber = run.first;
		int nevents   = run.second;
		
		if(verbosity > GVERBOSITY_SILENT) {
			cout << GRUNLOGMSGITEM << " Starting Run Number ∙" << runNumber << "∙,  processing " << nevents << " events." << endl;
		}

		
		// loads the constants
		// PRAGMA TODO: pass variation to this routine
		for(auto gDigi: (*gDigitizationGlobal)) {
			// protecting against plugin not loaded
			if(gDigi.second) {
				gDigi.second->loadConstants(runNumber, "default");
				
				// instantiates pointer to GSensitivePars
				gDigi.second->loadSensitivePars(runNumber, "default");
				
				if(verbosity > GVERBOSITY_SILENT) {
					showDigitizationParameters(gDigi.first,
											   gDigi.second->showConstants(),
											   gDigi.second->showParameters());
				}
				
			}
		}
		
		// running max nEventsBuffer events
		int nEventsLeftToProcess = nevents;
		while(nEventsLeftToProcess > 0) {
			if(nEventsLeftToProcess > nEventsBuffer) {
				g4uim->ApplyCommand("/run/beamOn " + to_string(nEventsBuffer));
				nEventsLeftToProcess = nEventsLeftToProcess - nEventsBuffer;
			} else {
				g4uim->ApplyCommand("/run/beamOn " + to_string(nEventsLeftToProcess));
				nEventsLeftToProcess = 0;
			}
		}
		
		
		if(verbosity > GVERBOSITY_SILENT) {
			cout << GRUNLOGMSGITEM << " Run Number ∙" << runNumber << "∙ done with " << nevents << " events." << endl << endl;
		}
	}
	cout << endl;
	
	return 1;
}

// show digitization constants and parameters
void GRuns::showDigitizationParameters(string system, vector<string> digiConstants, vector<string> digiPars)
{
	for(auto dc: digiConstants) {
		cout << "  " << GRUNLOGMSGITEM << " " << system << ": " << dc << endl;
	}
	for(auto dp: digiPars) {
		cout << "  " << GRUNLOGMSGITEM << " " << system << ": " << dp << endl;
	}
}





