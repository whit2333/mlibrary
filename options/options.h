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

	//! Sets a double type option and description
	void setOption(double value, string title) {
		type = isDouble;

		valueD = value;
		valueS = "na";

		setUOption(title);
	}

	//! Sets a string type option and description
	void setOption(string value, string title) {
		type = isString;

		valueD = 0;
		valueS = value;

		setUOption(title);

	}

	//! Sets an option category
	void setCategory(string c) {
		category = c;
	}

	//! Adds line to the help
	void addHelp(string h) {
		help += h;
	}

	//! Adds line to the help
	void setRepetition(bool r) {
		repetition = r;
	}

	//! overloading the << operator
	friend ostream &operator<<(ostream &stream, GOption);

private:
	void setUOption(string t) {
		title = t;
		help   = "";

		category = "general";
		repetition = false;

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

	GOptions();


public:
	map<string, GOption> optionsMap;  ///< GOptions map


private:
	int ignoreNotFound; ///< if set to 1 do not quit if an option is not found
};


#endif





