#ifndef TEXTPROGRESSBAR_H
#define TEXTPROGRESSBAR_H

// c++
#include <string>
using namespace std;

#define TEXTPROGRESSBARNSTEPS 100

class TextProgressBar {

public:
	TextProgressBar(int w, string t, int minimum = 1, int maximum = 100, char s='[', char e=']', char m='=', char a='>') :
	barWidth(w), title(t), min(minimum), max(maximum), start(s), end(e), middle(m), advance(a) {
		dn  = (maximum - minimum + 1) / TEXTPROGRESSBARNSTEPS ;
		idn = minimum;
	}

	void setProgress(int p);

private:
	int barWidth;
	string title;
	int min, max;
	char start, end;
	char middle, advance;

	int dn, idn;
};


#endif
