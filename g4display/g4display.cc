// g4display 
#include "g4display.h"

// mlibrary
#include "gstring.h"
using namespace gstring;

// geant4
#include "G4UImanager.hh"

#define minWindowSize 100
#define maxWindowSize 10000

vector<string> availableG4Viewers = {
	"OGLSQt",
	"OGLIQt" } ;

/*! \fn G4Display::G4Display(GOptions* goptsG4Display)

 class constructor

 \param gopts GOptions can come from this library or user can define new ones

 */
G4Display::G4Display(GOptions* gopts)
{
	vector<string> viewOptions = gopts->getStringVectorValue("g4view");

	string gViewOptions = "/vis/open " + getViewerFromOption(viewOptions) + " " + getGeoFromOption(viewOptions) + getPosFromOption(viewOptions);

	G4UImanager* UIM = G4UImanager::GetUIpointer();

	if(UIM) {
		UIM->ApplyCommand("/vis/scene/create GHall");

		UIM->ApplyCommand(gViewOptions);
//		UIM->ApplyCommand("/vis/viewer/set/autoRefresh 1");
//		UIM->ApplyCommand("/vis/scene/add/trajectories");
//		UIM->ApplyCommand("/vis/viewer/set/backgrounda .8 .9 .98 1");


	} else {
		cout << " No UIManager found. " << endl;
	}

}

string G4Display::getViewerFromOption(vector<string> opt)
{
	for(auto &o: opt) {
		if(find(availableG4Viewers.begin(), availableG4Viewers.end(), trimSpacesFromString(o)) != availableG4Viewers.end()) {
			return o;
		}
	}

	return defaultGViewerDriver;
}

string G4Display::getGeoFromOption(vector<string> opt)
{
	for(auto &o: opt) {
		if(o.find("x") != string::npos) {
			vector<string> possibleGeo = getStringVectorFromStringWithDelimiter(o, "x");
			if(possibleGeo.size() == 2) {
				int w = stoi(possibleGeo[0]);
				int h = stoi(possibleGeo[1]);
				if(w > minWindowSize && w < maxWindowSize && h > minWindowSize && h < maxWindowSize) {
					return o;
				} else {
					cout << "  Warning: viewer size <" << o << "> not recognized. Using default: " << defaultGViewerSize << endl;
				}
			}
		}
	}
	return defaultGViewerSize;
}

string G4Display::getPosFromOption(vector<string> opt)
{
	for(auto &o: opt) {
		if(o.find("+") != string::npos) {
			vector<string> possibleGeo = getStringVectorFromStringWithDelimiter(o, "+");
			if(possibleGeo.size() == 2) {
				int w = stoi(possibleGeo[0]);
				int h = stoi(possibleGeo[1]);
				if(w > 0 && w < maxWindowSize && h > 0 && h < maxWindowSize) {
					return o;
				} else {
					cout << "  Warning: viewer position <" << o << "> not recognized. Using default: " << defaultGViewerPos << endl;
				}
			}
		}
	}
	return defaultGViewerPos;
}
