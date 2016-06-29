#include "options.h"


ostream &operator<<(ostream &stream, GOption gopt)
{
	stream << " > " << gopt.title << " set to ";
	switch(gopt.type) {
		case isString: stream << gopt.valueS ; break;
		case isDouble: stream << gopt.valueD ; break;
	}
	return stream;
}




