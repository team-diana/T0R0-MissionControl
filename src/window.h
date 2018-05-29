#ifndef WINDOW_H
#define WINDOW_H

#include "library/rovershow.h"
#include "library/startbutton.h"
#include "library/batteryindicator.h"
#include "library/batterypanel.h"
#include "library/batterydisplay.h"
#include "library/statusdisplay.h"
#include "library/imagebutton.h"
#include "library/autosysdisplay.h"
#include "library/radiodisplay.h"
#include "library/allsystemsdisplay.h"

#include <QLabel>

#include <QString>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class Window : public QWidget
{
	Q_OBJECT

public:
    explicit Window(QRect screen, QWidget *parent = 0);

public slots:

protected:
	//void keyPressEvent(QKeyEvent *k) Q_DECL_OVERRIDE;

private:
    bool connected;

    // Custom elements
	AllSysDisplay *allsysdisplay;
    StartButton *start_button;
    RoverShow *rover;
    BatteryPanel *batterypanel1;
	BatteryDisplay *batterydisplay;
	StatusDisplay *statusdisplay;
    QLabel *pixlabel;
	AutoSysDisplay *autosysdisplay;
	RadioDisplay *radiodisplay;
	//KeyPress *key_press_event;
};

#endif // WINDOW_H
