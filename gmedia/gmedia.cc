// gmedia 
#include "gmedia.h"

// pragma todo: pass someting like map<string, bitset> to each detector to decide which data to publish
map<string, bool> GMedia::publishData(vector<GEventData*> *runData) {
	
	map<string, bool> gmediaReport;
	
	// looping over events
	for(auto eventData: (*runData)) {
	
		// start of event
		gmediaReport["startEvent"] = startEvent();
		gmediaReport["header"]     = publishHeader(eventData->getHeader());
		
		// digitized observables: looping over detectors
		for(auto detectorData: eventData->getDetectorsData()) {
			string dnameKey = detectorData->getName() + "TrueInfo";
			gmediaReport[dnameKey] = publishDetectorDigiObservables(detectorData);
		}

		// true observables: looping over detectors
		for(auto detectorData: eventData->getDetectorsData()) {
			string dnameKey = detectorData->getName() + "Data";
			gmediaReport[dnameKey] = publishDetectorTrueObservables(detectorData);
		}
		
		// end of event
		gmediaReport["endEvent"] = endEvent();
		
		evn++;
	}

	return gmediaReport;
}


/*! \fn map<string, GOption> GMedia::defineOptions()
 
 \return defines GMedia specific options
 
 */
map<string, GOption> GMedia::defineOptions()
{
	map<string, GOption> optionsMap;
	
	optionsMap["output"] = GOption("Output filename and format(s)", "na", "output");
	optionsMap["output"].addHelp("Example:\n\n");
	optionsMap["output"].addHelp("-output=\"myout: txt, root\": will write two filenames: myout.txt and myout.root\n\n");
	optionsMap["output"].addHelp("Possible formats (depends on plugin availability):\n");
	optionsMap["output"].addHelp(string(GOPTIONITEM) + "txt \n");
	optionsMap["output"].addHelp(string(GOPTIONITEM) + "root \n");

	optionsMap["outputv"] = GOption("Output Verbosity", 1, "output");
	optionsMap["outputv"].addHelp("Possible values:\n");
	optionsMap["outputv"].addHelp(GVERBOSITY_SILENT_D);
	optionsMap["outputv"].addHelp(GVERBOSITY_SUMMARY_D);
	optionsMap["outputv"].addHelp(GVERBOSITY_DETAILS_D);
	optionsMap["outputv"].addHelp(GVERBOSITY_ALL_D);

	return optionsMap;
}
