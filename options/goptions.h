/// \mainpage
/// \section Overview
/// The options framework provides command line and xml parsing of user
/// defined options.\n
/// The command line options have the format:\n
/// <pre> -KEY=VALUE </pre>
/// where Value can be a number or a string.\n
/// The corresponding XML syntax is:\n
/// <pre>  \<option name="KEY" value="Value"/> </pre>
///
/// \section User Interface
/// The users creates his/her own options by filling the optionsMap in a function: \n
/// <pre> map<string, GOption> GOptions::defineOptions()</pre>
/// and then calling the GOptions constructor with command line arguments and defineOptions().
/// The GOption constructor has the format
/// <pre> GOption("title", defaultValue, category, canBerepated):</pre>
///
/// \param title is a short description of the option
/// \param defaultValue is the default value of the option. It can be a double or a string
/// \param category(optional) is a string used to group options in categories
/// \param canBerepated (optional) is "true" or "false". If true options can be repeated. Default: false.
///
/// \section Example
/// An example of defineOptions() is in example.cc: \include example.cc
/// Running <i>example -h</i> will produce the following log:
/// ~~~~
///
/// Usage:
///
/// > -h, -help, --help: print this message and exit.
/// > -help-all:  print all available options and exit.
/// > -help-html:  print all available options in HTML format (options.html) and exit.
///
/// > Available categories
///   -help-general........:  general related options
///   -help-process........:  process related options
///   -help-time...........:  time related options
///
/// ~~~~


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
#include <sstream>
using namespace std;

//! formatting spaces for the help
#define HELPFILLSPACES  "                           "
//! repeated option internal additional string
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

	//! gets the double value
	double getDoubleValue() const {return valueD;}

	//! gets the Int value
	int getIntValue() const {return (int) valueD;}

	//! gets the bool value - it must be a double type
	bool getBoolValue() const {
		if(valueD == 0)
			return false;
		return true;
	}
	
	//! gets the generic string value
	string getValue() const {
		switch(type) {
			case isString: return valueS;
			case isDouble: return to_string(valueD);
		}
	}

	// get a vector of strings from the valueS
	vector<string> getValues() const {
		vector<string> values;

		stringstream plist(valueS);
		while(!plist.eof()) {
			string tmp;
			plist >> tmp;
			values.push_back(tmp);
		}
		return values;
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
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n
class GOptions
{
public:
	//! constructor - ignore is optional
	GOptions(int argc, char *argv[], map<string, GOption> optionsMap, bool ignore = false);

	//! returns repetitive options matching a key
	vector<GOption> getOptions(string which) {
		vector<GOption> result;

		for(const auto &om : optionsMap) {
			if(om.first.find(which) != string::npos) result.push_back(om.second);
		}
		return result;
	}

	//! returns the option matching a key
	GOption getOption(string which) {
		return optionsMap[which];
	}

	//! gets the options values
	double getDoubleValue(string optionKey);
	int getIntValue(string optionKey);
	bool getBoolValue(string optionKey);
	string getStringValue(string optionKey);
	string getValue(string optionKey);
	vector<string> getValues(string optionKey);


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




