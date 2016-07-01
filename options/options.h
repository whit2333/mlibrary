/// \file options.h
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

#ifndef GOPTIONS_H
#define GOPTIONS_H

// qt
#include <QDomDocument>
#include <QFile>

// c++
#include <string>
#include <map>
#include <set>
#include <iostream>

using namespace std;

//! formatting spaces for the help
#define HELPFILLSPACES  "                           "
#define HELPREPETITION  "__REPETITION__"

//! a GOption can be a double or a string
enum GOptionType {isDouble, isString};  // option type


/// \class GOption
/// <b> GOption </b>\n\n
/// A GOption value can be a double or a string.\n
/// - title  provides a short description\n
/// - help can span multiple lines.\n
/// - canBeRepeated false (default): option is unique. Command line overwrite gcard.
/// - category is used to add sections to the help command.\n
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n
class GOption
{
private:

	GOptionType type; ///< string or double

	double valueD;    ///< double value
	string valueS;    ///< string value

	string title;     ///< One liner to be displayed for the argument variable.
	string help;      ///< help to be displayed for the argument variable.

	string category;     ///< help category -help will group all categories together
	bool canBeRepeated;  ///< false (default): option is unique. Command line overwrite gcard.

public:
	//! default constructor
	GOption() = default;
	//! default copy constructor
	GOption ( const GOption & ) = default;

	//! Sets a double type option and description
	GOption(string t, double v, string cat = "general", bool canRepeat = false) : type(isDouble), valueD(v) {

		valueS = "na";

		setUOption(t, cat, canRepeat);
	}

	//! Sets a string type option and description
	GOption(string t, string v, string cat = "general", bool canRepeat = false) : type(isString), valueS(v) {

		valueD = -99;

		setUOption(t, cat, canRepeat);

	}

	//! modify value. The argument is always a string
	void setValue(string v) {
		switch(type) {
			case isString: valueS = v ;       break;
			case isDouble: valueD = stod(v) ; break;
		}
	}

	//! Adds lines to the help
	void addHelp(string h) {
		// replaces help if it's the title
		if(help == HELPFILLSPACES + title) help = "";
		// adding formatting spaces to match the help alignment
		help += HELPFILLSPACES;
		help += h;
	}


	//! overloading the << operator
	friend ostream &operator<<(ostream &stream, GOption);

	//! gets the category
 	string getCategory() const {return category;}

	//! gets the title
	string getTitle() const {return title;}

	//! gets the help
	string getHelp() const {return help;}

	//! answer can it be repeated question
	bool canItBeRepeated() const {return canBeRepeated;}

	//! gets the value
	string getValue() const {
		switch(type) {
			case isString: return valueS;
			case isDouble: return to_string(valueD);
		}
	}


private:

	//! Sets the common properties
	void setUOption(string t, string c, bool m){


		title         = t;
		category      = c;
		canBeRepeated = m;

		// setting default help to option description
		help       = HELPFILLSPACES + t;

	}

};


/// \class GOptions
/// <b> GOptions </b>\n\n
/// GOptions contains a map of GOption where the key is the option name.\n
/// Multiple keys are handled by adding a __REPETITION__ string to they key.\n
/// A multi_map could be used as well but the merging is controlled by the
/// mergeCard property, thus the complications would be the same.
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n
class GOptions
{
public:

	//! constructor - ignore is optional
	GOptions(int argc, char *argv[], bool ignore = false);

	//! users have to define their own options by implementing defineOptions
	void defineOptions() ;

	//! returns all options matching a key
	vector<GOption> getOptions(string which) {
		vector<GOption> result;

		for(const auto &om : optionsMap) {
			if(om.first.find(which) != string::npos) result.push_back(om.second);
		}

		return result;
	}

private:

	//! GOptions map
	map<string, GOption> optionsMap;
	//! User settings is a subset of the options map keys
	vector<string> userSettings;
	//! User Categories
	set<string> categories;

	//! set to 1 to not quit if an option is not found
	bool ignoreNotFound;


private:

	//! returns the matching list of keys, including repetitions
	vector<string> userDefinedOptions(string which) {
		vector<string> result;
		for(const auto &us : userSettings)
			if(us.find(which) != string::npos) result.push_back(us);

		return result;
	}

	string findConfigurationFile(int argc, char *argv[]);  ///< finds a configuration file (gcard). Returns "na' if not found.
	int parseConfigurationFile(string file);               ///< parse a gcard in the GOptions map
	QDomDocument checkAndParseGCard(string file);          ///< check a gcard and parse it in a QDomDocument
	void checkAndParseCommandLine(int argc, char *argv[]); ///< check and parse the command line options
	string findCLOption(string o, int argc, char *argv[]); ///< finds an option from the command line arguments
	void printUserSettings();                              ///< print all user settings
	void setOptionValue(string key, string value);         ///< set optionsMap[key] value - or add REPETITION option

	// helps
	void printGeneralHelp();                     ///< prints the general help
	void printAvailableHelp(string search);      ///< print available options that match a search. "all" prints all.
	void printCategoryHelp(string cat);          ///< print help options that match a category
	void printOptionDetailedHelp(string opt);    ///< print an option help
	void printHTMLHelp();                        ///< prints all option in HTML format (options.html)

};


#endif





