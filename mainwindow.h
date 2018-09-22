#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "config.h"

#include "mqttharbinger.h"

#include "rovershow.h"
#include "startbutton.h"
#include "batteryindicator.h"
#include "batterypanel.h"
#include "batterydisplay.h"
#include "statusdisplay.h"
#include "imagebutton.h"
#include "autosysdisplay.h"
#include "radiodisplay.h"
#include "allsystemsdisplay.h"
#include "ultrasonicdisplay.h"
#include "vescdisplay.h"
#include "scientificdisplay.h"
#include "scientificindicator.h"
#include "map2d.h"

#include <QLabel>

#include <QString>

#define XPOS_BATTGROUP 0
#define YPOS_BATTGROUP 0

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

protected:
    void keyPressEvent(QKeyEvent *e);

private:
    bool connected;

    MqttHarbinger *m_mqttHarbinger;

    // Custom elements
    UltrasonicDisplay *usDisplay;
    AllSysDisplay *allsysdisplay;
    StartButton *start_button;
    RoverShow *rover;
    BatteryPanel *batterypanel1;
    BatteryDisplay *batterydisplay;
    StatusDisplay *statusdisplay;
    QLabel *pixlabel;
    AutoSysDisplay *autosysdisplay;
    RadioDisplay *radiodisplay;
    VescDisplay *vescDisplay;
    ScientificDisplay *scienceDisplay;
    Map2d *map2d;

};

#endif // MAINWINDOW_H
