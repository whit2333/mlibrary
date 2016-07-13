// progress Bar
#include "textProgressBar.h"

// c++
#include <iostream>

void TextProgressBar::setProgress(int p)
{
	if(p < min || p > max) return;

	if(p < idn) return;

	else {
		idn += dn;
	}

	cout  << title << start ;

	// progress is between 1 and 100
	int progress = idn/dn;

	// pos is relative position within the bar
	int pos = progress*barWidth/TEXTPROGRESSBARNSTEPS;
	for (int i = 0; i < barWidth; ++i)
	{
		if      (i < pos)  cout << middle;
		else if (i == pos) cout << advance;
		else cout << " ";
	}
	cout << end << progress << " %\r" ;

	if(progress == TEXTPROGRESSBARNSTEPS) cout << endl;

	cout.flush();
}
