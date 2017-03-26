/******************************************************************************
Copyright (C) 2013 by Hugh Bailey <obs.jim@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include <time.h>
#include <stdio.h>
#include <wchar.h>
#include <chrono>
#include <ratio>
#include <string>
#include <sstream>
#include <mutex>
#include <util/bmem.h>
#include <util/dstr.h>
#include <util/platform.h>
#include <util/profiler.hpp>
#include <obs-config.h>
#include <obs.hpp>

#include <QPixmap>
#include <QSplashScreen>
#include <QThread>

#include "qt-wrappers.hpp"
#include "splash.hpp"
#include "crash-report.hpp"
#include "platform.hpp"

#include <fstream>

#include <curl/curl.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <signal.h>
#endif


using namespace std;

class I : public QThread
{
public:
	static void sleep(unsigned long secs) {
		QThread::sleep(secs);
	}
};

Splash::Splash()
{
	blog(LOG_INFO, "Loading splash");
	QPixmap pixmap =
		QPixmap::fromImage(QImage(":/res/images/splash.png"));
	QSplashScreen splash(pixmap);

	blog(LOG_INFO, "Loaded splash");

	splash.show();
	splash.showMessage(QObject::tr("Loading..."),
		Qt::AlignLeft | Qt::AlignTop, Qt::black);

	// Splash page is shown for 5 seconds
	I::sleep(5);
}

Splash::~Splash()
{

}
