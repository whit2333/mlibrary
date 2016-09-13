#ifndef GSTRING_H
#define GSTRING_H

#include <vector>
#include <string>
using namespace std;

namespace gstring
{

	//! a vector of strings from a stringstream, space is delimiter
	vector<string> getStringVectorFromString(string);

 	//! returns a vector of strings from a stringstream, second string is delimiter
	vector<string> getStringVectorFromStringWithDelimiter(string, string);

	//! Removes leading and trailing spaces
	string trimSpacesFromString(string);

	//! Replace all occurences of a char in string with a string
	string replaceCharInStringWithChars(string input, string toReplace, string replacement);

	// adds zeros to fill totDigits
	string fillDigits(string word, string c, int ndigits);
}





#endif