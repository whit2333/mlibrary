#include "ctofRoutinesExample.h"

bool CTofRoutineExample::loadConstants()
{
	var1    = 2.0;
	var2[0] = 1;
	var2[0] = 2;

	var3.push_back(3.0);
	var3.push_back(4.0);
	var3.push_back(5.0);
	var3.push_back(6.0);

	var4 = "hello";

	cout << " Constants loaded for ctof!" << endl;

	return true;
}
