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
using namespace std;

/// \class aopt
/// <b> aopt </b>\n\n
/// Option class.\n
/// - arg:  double assigned to argument.
/// - args: string assigned to argument.
/// - name: name to be displayed for the argument variable.
/// - help: help for the argument variable.
/// - type: 0 = number, 1 = string
class aopt
{
public:
	int    type;  ///< 0 = number, 1 = string
	double  arg;  ///< double assigned to argument.
	string args;  ///< string assigned to argument.

	string shortHelp;  ///< One liner to be displayed for the argument variable.
	string help;       ///< help to be displayed for the argument variable.
	string category;   ///< help category -help will group all categories together

	int    shareWithGcard;  ///< if this is set to 1: then this option can be shared with the gcard
	                        ///< if this is set to 0: command line will always overwrite the gcard (default)

	aopt() {shareWithGcard = 0;}

public:
	void printSetting();            ///< print the option setting on screen
	//	void printHTML(ofstream hf);    ///< print the option as an <tr> entry in a HTML <table>
};


/// \class goptions
/// <b> goptions </b>\n\n
/// This is the general options class.
/// It contains a map of opt where the key is
/// the option string given at command line or gcard\n
class goptions
{
public:

	goptions();


	~goptions(){;}
	//
	//	virtual void setGoptions();                 ///< Function to fill optMap
	//
	//	void setOptions();                          ///< Define option Map
	//
	//	void scanGcard(string file);                ///< Scan option file for options
	//
	//	int setOptMap(int argc, char **args);       ///< Sets map from command line arguments
	//	int setOptMap(int argc, char **args, int i) ///< Sets map from command line arguments - include ignoreNotFound
	//	{
	//		ignoreNotFound = i;
	//		return setOptMap(argc, args);
	//	}
	//
	//	// Returns a map<string, string> with the key and value (stringified value if it's a number)
	//	map<string, string> getOptMap();
	//
	//	// gets a vector of options matching a name
	//	vector<aopt> getArgs(string name);
	//
	//	// print help in html format
	//	void printHtml();


public:
	map<string, aopt> optMap;  ///< Options map


private:
	int ignoreNotFound; ///< if set to 1 do not quit if an option is not found
};


#endif





