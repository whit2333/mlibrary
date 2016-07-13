// progress Bar
#include "textProgressBar.h"

// c++
#include <iostream>

void TextProgressBar::setProgress(int p)
{
	if(p<0 || p > 100) return;

	cout << title << start ;

	int pos = p*barWidth/100;
	for (int i = 0; i < barWidth; ++i)
	{
		if      (i < pos)  cout << middle;
		else if (i == pos) cout << advance;
		else cout << " ";
	}
	cout << end << p << " %\r";
	cout.flush();
}
