#include "options.h"


ostream &operator<<(ostream &stream, GOption gopt)
{
	stream << " > " << gopt.title << " set to ";
	switch(gopt.type) {
		case isString: stream << gopt.valueS ; break;
		case isDouble: stream << gopt.valueD ; break;
	}
	return stream;
}




GOptions::GOptions(int argc, char *argv[], bool ignore) : ignoreNotFound(ignore)
{

	// default verbosity
	GOption verbo(0.0, "Verbosity");
	optionsMap["verbosity"] = verbo;


	// parse configuration file
	parseConfigurationFile(findConfigurationFile(argc, argv));


}

//! finds a configuration file (gcard)
string GOptions::findConfigurationFile(int argc, char *argv[])
{
	// finds gcard file as one of the argument
	// extension is .gcard
	for(int i=1;i<argc;i++)
	{
		string arg = argv[i];
		size_t pos = arg.find(".gcard");
		if(pos != string::npos) return arg;
	}
	// finds gcard file as one of the options
	for(int i=1;i<argc;i++)
	{
		string arg = argv[i];
		size_t pos = arg.find("gcard=");
		if(pos != string::npos) return arg.substr(pos+6);
	}

	return "na";
}



int GOptions::parseConfigurationFile(string file)
{
	if(file == "na") return 0;



	cout << " Parsing configuration file: " << file << endl;


	return 1;
}

int QDomDocument::checkGCard(string file)
{
	QDomDocument domDocument;

	QFile gcard(file.c_str());

	if( !gcard.exists() )
	{
		cout << " >>  gcard: " << file <<" not found. Exiting." << endl;
		exit(0);
	}

	// opening gcard and filling domDocument
	if(!domDocument.setContent(&gcard))
	{
		cout << " >>  gcard format for file <" << file << "> is wrong - check XML syntax. Exiting." << endl;
		exit(0);
	}
	gcard.close();
}




