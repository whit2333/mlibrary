// txt gmedia
#include "gmediaTxtFactory.h"

bool GMediaTxtFactory::openConnection()
{
	ofile = new ofstream(outputFileName);
	
	
	// PRAGMA: need to check if file opened successfully
	return true;
}

bool GMediaTxtFactory::closeConnection()
{
	ofile->close();
	delete ofile;

	
	// PRAGMA: need to check if file closed successfully
	return true;
}



