#ifndef WINDOW_H
#define WINDOW_H

/*
#include "library/joystick.h"
#include "library/joypad.h"
#include "library/rovershow.h"
#include "library/startbutton.h"
#include "library/batteryindicator.h"
#include "library/batterypanel.h"
#include "library/batterydisplay.h"
#include "library/statusdisplay.h"
#include "library/imagebutton.h"
#include "keypress.h"
*/
#include <QLabel>
#include <QKeyEvent>
#include <QString>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class Window : public QWidget
{
  	Q_OBJECT

public:
    explicit Window(QRect screen, QWidget *parent = 0);
    ~Window();

public slots:

protected:
  	void keyPressEvent(QKeyEvent *e);

private:
    bool connected;

    // Custom elements
/*
  			StartButton *start_button;
    RoverShow *rover;
    BatteryPanel *batterypanel1;
  	BatteryDisplay *batterydisplay;
  	StatusDisplay *statusdisplay;
  	*/
    QLabel *pixlabel;
  	//KeyPress *key_press_event;
};

#endif // WINDOW_H
