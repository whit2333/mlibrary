// gmedia 
#include "gmedia.h"

map<string, bool> GMedia::publishData(vector<GEventData*> *runData) {
	
	map<string, bool> gmediaReport;
	
	gmediaReport["headerPublished"]  = publishHeader(runData);
		
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
	optionsMap["output"].addHelp("-output=\"myout, txt, root\": will write two filenames: myout.txt and myout.root\n\n");
	optionsMap["output"].addHelp("Possible formats:\n");
	optionsMap["output"].addHelp(string(GOPTIONITEM) + "txt \n");
	optionsMap["output"].addHelp(string(GOPTIONITEM) + "root \n");
	optionsMap["output"].addHelp(string(GOPTIONITEM) + "csv \n");

	optionsMap["outputv"] = GOption("Output Verbosity", 1, "output");
	optionsMap["outputv"].addHelp("Possible values:\n");
	optionsMap["outputv"].addHelp(GVERBOSITY_SILENT_D);
	optionsMap["outputv"].addHelp(GVERBOSITY_SUMMARY_D);
	optionsMap["outputv"].addHelp(GVERBOSITY_DETAILS_D);
	optionsMap["outputv"].addHelp(GVERBOSITY_ALL_D);

	
	return optionsMap;
}
