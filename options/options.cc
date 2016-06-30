/// \file options.cc
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n
#include "options.h"


//! overloading "<<" to print this class
ostream &operator<<(ostream &stream, GOption gopt)
{
	switch(gopt.type) {
		case isString: stream << "\"" << gopt.valueS << "\""; break;
		case isDouble: stream << "< " << gopt.valueD << " >"; break;
	}
	stream << " (" << gopt.title << ")";
	return stream;
}


//! constructor - ignore is optional
GOptions::GOptions(int argc, char *argv[], bool ignore) : ignoreNotFound(ignore)
{

	defineOptions();

	// fill the categories set
	for (const auto &om : optionsMap) {
		if(categories.find(om.second.getCategory()) == categories.end())
			categories.insert(om.second.getCategory());
	}

	//! parse configuration file
	parseConfigurationFile(findConfigurationFile(argc, argv));

	//! now parse command line arguments
	checkAndParseCommandLine(argc, argv);

	// now print the user settings
	printUserSettings();
}

/*! \fn string GOptions::findConfigurationFile(int argc, char *argv[])

Finds a configuration file (gcard). Returns "na' if not found.
 
 \param argc, argv the program arguments
 \return The filename if a gcard was found. "na" otherwise
 */
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



/*! \fn int GOptions::parseConfigurationFile(string file)

Parse a configuration file into the GOptions map
 \param file the filename
 \return 1 if a file could be parsed. 0 if no file was found

 */
int GOptions::parseConfigurationFile(string file)
{
	if(file == "na") return 0;

	// this will fail if gcard not valid or not existing
	QDomDocument domDocument = checkAndParseGCard(file);

	// initializing count map to zero
	map<string, int> count;
	for (const auto &om : optionsMap)
		count[om.first] = 0;

	QDomNodeList options = domDocument.firstChildElement().elementsByTagName("option");
	for(int i = 0; i < options.count(); i++)
	{
		QDomNode elm = options.at(i);
		if(elm.isElement())
		{
			QDomElement e = elm.toElement();
			string option = e.attribute("name").toStdString();
			string value  = e.attribute("value").toStdString();

			// now checking that the xml option matches the GOption map
			// if ignoreNotFound is true then we don't care
			int matches = ignoreNotFound ? 1 : 0;

			for (auto &om : optionsMap) {
				// looking for a valid option. If a two instances of the same option exist
				if(option == om.first) {
					matches++;
					count[om.first] += 1;

					// first time option is found, modify its value
					if(count[om.first] == 1) {
						userSettings.push_back(om.first);
						om.second.setValue(value);
					} else {
						// new option is created with key same as the first one but
						// with the string __REPETITION__# appended
						string newKey = om.first + "__REPETITION__" + to_string(count[om.first]);
						optionsMap[newKey] = GOption(om.second);
						optionsMap[newKey].setValue(value);
					}
					// option is found, we can break from the GOption map loop
					break;
				}
			}
			// option was not found. if ignoreNotFound is 1 matches is 1.
			if(matches < 2) {
				cout << "  !! Attention: the gcard <" << file << "> option " << option
					  << " is not known to this system. Please check your spelling." << endl;
			}
			// option was not found. ignoreNotFound is 0
			if(matches == 0) exit(0);
		}

	}

	cout << " Configuration file: " << file << " parsed into options map." << endl;


	return 1;
}

/*! \fn  GOptions::checkAndParseCommandLine(int argc, char *argv[])

 - Checks commands line options for special directives such as -h, -help, etc
 - Parse commands line options to the options map

 */
void GOptions::checkAndParseCommandLine(int argc, char *argv[])
{
	if(findOption("-h",     argc, argv) == "yes") printGeneralHelp();
	if(findOption("-help",  argc, argv) == "yes") printGeneralHelp();
	if(findOption("--help", argc, argv) == "yes") printGeneralHelp();

	if(findOption("-help-all", argc, argv) == "yes") printAvailableOptions("all");

	// category help


}


/*! \fn  GOptions::checkAndParseGCard(string file)

 - Checks if the gcard is valid
 - Exits if the gcard has wrong format or doesn't exist
 - Parse the gcard onto a QDomDocument

 \param file the filename
 \return the QDomDocument

 */
QDomDocument GOptions::checkAndParseGCard(string file)
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

	return domDocument;
}



/*! \fn  GOptions::printUserSettings(string file)

 - Loops over the user settings and print on screen.

 */
void GOptions::printUserSettings()
{
	if(userSettings.size())
	{
		cout << " > Selected User Options: " << endl;
		for (auto &s : userSettings) {
			cout <<  "   - " ;
			cout.width(20);
			cout.fill('.');
			cout << left << s << ": " << optionsMap[s] << endl;
		}
	}
}

/*! \fn GOptions::findOption(string o, int argc, char *argv[])

 - finds an option from the command line arguments

 */
string GOptions::findOption(string o, int argc, char *argv[])
{
	string found = "no";
	for(int i=1; i<argc; i++) {
		string argument = argv[i];
		if(argument == o) found = "yes";
	}
	return found;
}


/*! \fn  GOptions::printGeneralHelp()

 - Print the general help and exit

 */
void GOptions::printGeneralHelp()
{
	cout << endl;
	cout <<  "    Usage:" <<  endl << endl ;
	cout <<  "   > -h, -help, --help: print this message and exit. "    << endl;
	cout <<  "   > -help-all:  print all available options and exit. "  << endl << endl;
	cout <<  "   > Available categories "  << endl;

	for(const auto &c : categories)
	{
		cout << "     -help-" ;
		cout.width(15);
		cout.fill('.');
		cout << left << c << ":  " << c << " related options" << endl;
	}
	cout << endl;
	exit(0);


}


/*! \fn  GOptions::printAvailableOptions(string search)

 - Print available options which description matches search
 - "all" will print all available options.

 */
void GOptions::printAvailableOptions(string search)
{
	cout << " > Available Options: " << endl;
	for (const auto &om : optionsMap) {
		if(search == "all" || om.second.getTitle().find(search) != string::npos)
		cout <<  "   - " ;
		cout.width(20);
		cout.fill('.');
		cout << left << om.first << ": " << om.second.getTitle() << ". Default set to: " <<  om.second.getValue() << endl;
	}

	exit(0);
}




