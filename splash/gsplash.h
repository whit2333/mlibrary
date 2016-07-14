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
#include "goptions.h"

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
	bool  gui;
	string header;
	QSplashScreen *splash;

public:
	~GSplash();
	void message(string);
	void finish(QMainWindow *window) {if(splash != NULL) splash->finish(window);}

	// gsplash options
	static map<string, GOption> defineOptions();
};

#endif


