/// \file options.h
/// Defines the goption library.\n
/// A program main argv options are filled into a map<string opts>.
/// Additional options should be added with addOptions pure virtual method.
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

#ifndef GOPTIONS_H
#define GOPTIONS_H


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

	GOptionType type;

	double valueD;    // double value
	string valueS;    // string value

	string title;     // One liner to be displayed for the argument variable.
	string help;      // help to be displayed for the argument variable.

	string category;  // help category -help will group all categories together
	bool repetition;  // false (default): this option is unique in the map

public:
	// if other constructors are present declaring the base is mandatory
	// c++11 allows "default"
	GOption() = default;

	//! Sets a double type option and description
	GOption(double v, string t, string cat = "general", bool rep = false) : valueD(v) {
		type = isDouble;

		valueS = "na";

		setUOption(title, category, rep);
	}

	//! Sets a string type option and description
	GOption(string v, string t, string cat = "general", bool rep = false) : valueS(v) {
		type = isString;

		valueD = -99;

		setUOption(title, category, rep);

	}

	//! Adds lines to the help
	void addHelp(string h) {
		help += h;
	}


	//! overloading the << operator
	friend ostream &operator<<(ostream &stream, GOption);

private:
	void setUOption(string t, string c, bool r){

		category   = c;
		repetition = r;

		// setting default help to option description
		help       = t;

	}

};


/// \class GOptions
/// <b> GOptions </b>\n\n
/// GOptions contains a map of GOption where the key is the option name
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n
class GOptions
{
public:

	//! constructor - ignore is optional
	GOptions(int argc, char *argv[], bool ignore = false);

private:

	//! GOptions map
	map<string, GOption> optionsMap;

	//! finds a configuration file (gcard)
	string findConfigurationFile(int argc, char *argv[]);
	int parseConfigurationFile(string file);
	QDomDocument checkGCard(string file);

private:
	bool ignoreNotFound; ///< if set to 1 do not quit if an option is not found
};


#endif





