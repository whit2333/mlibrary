/// \file options.h
/// Defines the goption library.\n
/// A program main argv options are filled into a map<string opts>.
/// Additional options should be added with addOptions pure virtual method.
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
#include <iostream>

using namespace std;

//! a GOption can be a double or a string
enum GOptionType {isDouble, isString};  // option type


/// \class GOption
/// <b> GOption </b>\n\n
/// A GOption value can be a double or a string.\n
/// A "title" provides a short description, the help can span multiple lines.\n
/// Set repetition to true (false is default) if you want to allow multiple instance of an option.\n
/// A category is used to add sections to the help command.\n
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

	string category;  ///< help category -help will group all categories together
	bool mergeGCard;  ///< false (default): command line will overwrite the gcard - will merge if true

public:
	// if other constructors are present declaring the base is mandatory
	// c++11 allows "default"
	GOption() = default;
	// default copy constructor
	GOption ( const GOption & ) = default;

	//! Sets a double type option and description
	GOption(double v, string t, string cat = "general", bool merge = false) : valueD(v) {
		type = isDouble;

		valueS = "na";

		setUOption(title, category, merge);
	}

	//! Sets a string type option and description
	GOption(string v, string t, string cat = "general", bool merge = false) : valueS(v) {
		type = isString;


		valueD = -99;

		setUOption(title, category, merge);

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
		help += h;
	}


	//! overloading the << operator
	friend ostream &operator<<(ostream &stream, GOption);

private:

	//! Sets the common properties
	void setUOption(string t, string c, bool m){

		category   = c;
		mergeGCard = m;

		// setting default help to option description
		help       = t;

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

private:

	//! GOptions map
	map<string, GOption> optionsMap;
	//! User settings is a subset of the options map keys
	vector<string> userSettings;

	bool ignoreNotFound; ///< if set to 1 do not quit if an option is not found


private:

	string findConfigurationFile(int argc, char *argv[]); ///< finds a configuration file (gcard). Returns "na' if not found.
	int parseConfigurationFile(string file);              ///< parse a gcard in the GOptions map
	QDomDocument checkAndParseGCard(string file);         ///< check a gcard and parse it in a QDomDocument
	void printUserSettings();                             ///< print all user settings


	//! adds an option to the map
	void addOption(string okey, GOption gopt) {
		optionsMap[okey] = gopt;
	}


};


#endif





