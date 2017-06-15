// g4display 
#include "g4display.h"

/*! \fn G4Display::G4Display(GOptions* goptsG4Display)

 class constructor

 \param gopts GOptions can come from this library or user can define new ones

 */
G4Display::G4Display(GOptions* gopts)
{
	vector<string> viewOptions = gopts->getStringVectorValue("g4view");
}
