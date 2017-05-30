// gvolume
#include "systemTextFactory.h"


// c++
#include <iostream>
using namespace std;


void GSystemTextFactory::loadSystem(GOptions* gopt) {
	cout << " Factory car ford it works! " << std::endl;
	
	loadMaterial();
	loadGeometry();
}

void GSystemTextFactory::loadMaterial() {
	cout << " Factory mat ford it works! " << std::endl;
}

void GSystemTextFactory::loadGeometry() {
	cout << " Factory geo ford it works! " << std::endl;
}

