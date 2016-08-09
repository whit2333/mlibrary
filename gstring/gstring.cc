// gstring
#include "gstring.h"

// c++
#include <sstream>

// returns a vector of strings from a stringstream, space is delimeter
vector<string> gstring::getStringVectorFromString(string input)
{
	vector<string> pvalues;
	stringstream plist(input);
	while(!plist.eof())
	{
		string tmp;
		plist >> tmp;
		pvalues.push_back(trimSpacesFromString(tmp));
	}

	return pvalues;
}


// Trims Both leading and trailing spaces
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