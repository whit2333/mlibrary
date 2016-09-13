// gstring
#include "gstring.h"

// c++
#include <sstream>

//! returns a vector of strings from a stringstream, space is delimeter
vector<string> gstring::getStringVectorFromString(string input)
{
	vector<string> pvalues;
	stringstream plist(input);
	while(!plist.eof()) {
		string tmp;
		plist >> tmp;
		string toPut = trimSpacesFromString(tmp);
		if(toPut != "")
			pvalues.push_back(toPut);
	}

	return pvalues;
}


//! Trims Both leading and trailing spaces
string gstring::trimSpacesFromString(string in)
{
	string out;

	size_t leapos = in.find_first_not_of(" \t"); // Find the first character position after excluding leading blank spaces
	size_t endpos = in.find_last_not_of(" \t");  // Find the first character position from reverse af

	// if all spaces or empty return an empty string
	if(( leapos == string::npos) || ( endpos == string::npos))
		out = "";
	else
		out = in.substr( leapos, endpos-leapos+1 );

	return out;
}

//! returns a vector of strings from a stringstream, x (one char) is delimiter
vector<string> gstring::getStringVectorFromStringWithDelimiter(string input, string x)
{
	vector<string> pvalues;

	string tmp;
	for(unsigned int i=0; i<input.size(); i++) {

		if(input[i] != x[0]) {
			tmp += input[i];
		} else {
			pvalues.push_back(tmp);
			tmp = "";
		}

		// end of line
		if(i==input.size() - 1) {
			pvalues.push_back(tmp);
		}
	}

	return pvalues;
}


//! Replace all occurences of specific chars in string with a string
string gstring::replaceCharInStringWithChars(string input, string toReplace, string replacement)
{

	string output = "";

	for(unsigned int k=0; k<input.size(); k++) {

		int replace = 0;

		for(unsigned int j=0; j<toReplace.size(); j++) {
			// found common char, replacing it with replacement
			if(input[k] == toReplace[j]) {
				output.append(replacement);
				replace = 1;
			}
		}
		if(!replace) output += input[k];
	}

	return output;
}

#include <iostream>
using namespace std;

string gstring::fillDigits(string word, string c, int ndigits)
{
	string filled;

	int toFill = ndigits - (int) word.size();

	for(int d=0; d<toFill; d++) {
		filled += c;
	}

	filled += word;

	return filled;
}








