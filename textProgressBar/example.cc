/// \file example.cc

// example on how to use the text progress bar library

// text progress bar
#include "textProgressBar.h"

// c++
#include <iostream>
using namespace std;


//! example of main declaring GOptions
int main(int argc, char* argv[])
{
	
	TextProgressBar bar(20, "  index progress: ");

	int bprogress = 0;
	for(int i=0; i<1000000001; i++) {
		if(i%10000000 == 0)
		{
			bar.setProgress(bprogress);
			bprogress++;
		}
	}

	return 1;
}

