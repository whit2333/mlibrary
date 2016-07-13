#ifndef TEXTPROGRESSBAR_H
#define TEXTPROGRESSBAR_H

// c++
#include <string>
using namespace std;

class TextProgressBar {

public:
	TextProgressBar(int w, string t, char s='[', char e=']', char m='=', char a='>') : barWidth(w), title(t), start(s), end(e), middle(m), advance(a) {
		
	}

	void setProgress(int p);



private:
	int barWidth;
	string title;
	char start, end;
	char middle, advance;


};


#endif
