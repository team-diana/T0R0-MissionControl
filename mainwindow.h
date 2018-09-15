#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "config.h"

#include "mqttharbinger.h"

#include "allsystemsdisplay.h"
#include "autosysdisplay.h"
#include "batteryindicator.h"
#include "batterypanel.h"
#include "batterydisplay.h"
#include "imagebutton.h"
#include "map2d.h"
#include "odometrydisplay.h"
#include "radiodisplay.h"
#include "rovershow.h"
#include "startbutton.h"
#include "statusdisplay.h"
#include "scientificdisplay.h"
#include "scientificindicator.h"
#include "ultrasonicdisplay.h"
#include "vescdisplay.h"

#include <QLabel>

#include <QString>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();\

public slots:

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    bool connected;

    MqttHarbinger *m_mqttHarbinger;

    QLabel *pixlabel;

    // Custom elements
    AllSysDisplay *allsysdisplay;
    AutoSysDisplay *autosysdisplay;
    BatteryDisplay *batterydisplay;
    BatteryPanel *batterypanel1;
    Map2d *map2d;
    OdomDisplay *odomDisplay;
    RadioDisplay *radiodisplay;
    RoverShow *rover;
    ScientificDisplay *scienceDisplay;
    StartButton *start_button;
    StatusDisplay *statusdisplay;
    UltrasonicDisplay *usDisplay;
    VescDisplay *vescDisplay;

};

#endif // MAINWINDOW_H
