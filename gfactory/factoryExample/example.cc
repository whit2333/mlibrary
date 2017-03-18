#include "gfactory.h"


int main(int argc, char** argv)
{
	auto instanceOne = GFactory::Instance()->Create("one");
	auto instanceTwo = GFactory::Instance()->Create("two");
	
	instanceOne->doSomething();
	instanceTwo->doSomething();
	
	//instanceTwo->processEvent();
	
	return 0;
}
