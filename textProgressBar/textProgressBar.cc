// progress Bar
#include "textProgressBar.h"

// c++
#include <iostream>

void TextProgressBar::setProgress(int p)
{
	// step too small
	if(p < indexStep) return;

	// step too small
	if(singleStep == 0) return;

	// outside boundaries
	if(p < min || p > max) return;


	indexStep += singleStep;

	cout  << title << startBarChar ;

	// progress is between 1 and 100
	int progress = indexStep/singleStep;

	// pos is relative position within the bar
	int pos = progress*barWidth/TEXTPROGRESSBARNSTEPS;

	for (int i = 0; i < barWidth; ++i) {
		if      (i < pos)  cout << middleBarChar;
		else if (i == pos) cout << advanceBarChar;
		else cout << " ";
	}
	cout << endBarChar << " " << progress << " %\r" ;

	if(progress == TEXTPROGRESSBARNSTEPS) cout << endl;

	cout.flush();
}
