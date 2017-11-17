// txt gmedia
#include "gmediaROOTFactory.h"

bool GMediaROOTFactory::openConnection()
{
	const char *fileWithExtension = string(outputFileName + ".root").c_str();
	rootfile = new TFile(fileWithExtension, "RECREATE");
	
	// PRAGMA: need to check if file opened successfully
	return true;
}

bool GMediaROOTFactory::closeConnection()
{

	rootfile->Close();
	delete rootfile;

	// PRAGMA: need to check if file closed successfully
	return true;
}



