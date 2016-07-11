/// \mainpage
/// \section Overview
/// The splash framework will show a splash screen on screen
/// with optional messages overeimposed on top of it

/// \file gsplash.h
/// \author \n Maurizio Ungaro
/// \author mail: ungaro@jlab.org\n\n\n

#ifndef GSPLASH_H
#define GSPLASH_H

// options
#include "options.h"

// Qt
#include <QSplashScreen>
#include <QtWidgets>

// c++
#include <string>

class GSplash
{
public:
	GSplash(GOptions* gopt);

private:
	bool  qt;
	string header;

	QPixmap       *gsplashPic ;
	QSplashScreen *gsplash ;

public:
	void message(string);

};

#endif


