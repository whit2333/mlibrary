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

}





#endif