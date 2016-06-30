// example on how to use the options

// options
#include "options.h"

// c++
#include "iostream"
using namespace std;


void GOptions::defineOptions()
{
	cout << " e";


}

int main(int argc, char* argv[])
{
	
	GOptions *gopts = new GOptions(argc, argv, 1);


	cout << " Hello World" << endl;




	return 1;

}

