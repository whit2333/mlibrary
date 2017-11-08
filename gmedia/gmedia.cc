// gmedia 
#include "gmedia.h"

bool GMedia::publishData(vector<GEventData*> *runData) {
	
	bool headerPublished = publishHeader(runData);
	
	
	bool summary = headerPublished + false;
	
	return summary;
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

	return optionsMap;
}
