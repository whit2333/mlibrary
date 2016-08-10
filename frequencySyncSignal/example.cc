/// \file example.cc

// example on how to use the frequencySyncSignal library

// frequencySyncSignal framework
#include "frequencySyncSignal.h"

// remove later
#include <iostream>

//! example of main declaring GOptions
//! Example of argument for 1 RF signal: "200 12.1 0.5 80"
//! Example of argument for 2 RF signals: "200 12.1 0.5 80 40"
//! Example of argument for 3 RF signals: "200 12.1 0.5 80 40 22"
int main(int argc, char* argv[])
{

	FrequencySyncSignal rfs(argv[1]);

	cout << rfs << endl;

}

