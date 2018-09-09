#include "mainwindow.h"
#include <QKeyEvent>
#include <QCoreApplication>
#include <QDebug>


// Constructor
MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    //this->setGeometry(0, 0, screen.width(), screen.height());   // -50
    this->setGeometry(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    // set black background
    QPalette pal = palette();

    // Set backgroud color
    pal.setColor(QPalette::Background, QColor(14,14,14,255));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // Show Rover Image at the center of the Window
    //QLabel *pixlabel = new QLabel(this);
    //QPixmap pixrover(":/Images/rover_up-230x374.png");
    //pixlabel->setPixmap(pixrover.scaled(ROVIMG_WIDTH, ROVIMG_HEIGHT, Qt::KeepAspectRatio));
    //pixlabel->setGeometry( (this->width() - ROVIMG_WIDTH) /2, (this->height() - ROVIMG_HEIGHT) /2, ROVIMG_WIDTH, ROVIMG_HEIGHT );

    // Show Team D.I.A.N.A. logo at bottom-right
    QLabel *pixlogo = new QLabel(this);
    QPixmap pixmaplogo(":/Images/diana-logo-193x90.png");
    pixlogo->setPixmap(pixmaplogo.scaled(193, 90, Qt::KeepAspectRatio));
    pixlogo->setGeometry( 50, this->height() - 120, 193, 90 );

    connected = false;

    m_mqttHarbinger = new MqttHarbinger(this);

    // Custom elements
    start_button = new StartButton(this);
    start_button->setGeometry(this->width() / 2 - 100, this->height() - 100, 200, 100);

    batterydisplay = new BatteryDisplay(this);
    batterydisplay->setGeometry(BAT_DISPLAY_POSX, BAT_DISPLAY_POSY, BAT_DISPLAY_WIDTH + 2, BAT_DISPLAY_HEIGHT + 2);

    //statusdisplay = new StatusDisplay(this);
    //statusdisplay->setGeometry(STATUS_DISPLAY_POSX, STATUS_DISPLAY_POSY, STATUS_DISPLAY_WIDTH + 2, STATUS_DISPLAY_HEIGHT + 2);
    //statusdisplay->setGeometry(STATUS_DISPLAY_POSX, (this->height() - STATUS_DISPLAY_HEIGHT) / 2, STATUS_DISPLAY_WIDTH + 2, STATUS_DISPLAY_HEIGHT + 2);

    autosysdisplay = new AutoSysDisplay(this);
    autosysdisplay->setGeometry(AUTOSYS_DISPLAY_POSX, AUTOSYS_DISPLAY_POSY, AUTOSYS_DISPLAY_WIDTH + 2, AUTOSYS_DISPLAY_HEIGHT + 2);

   // radiodisplay = new RadioDisplay(this);
   // radiodisplay->setGeometry(RADIO_DISPLAY_POSX, RADIO_DISPLAY_POSY, RADIO_DISPLAY_WIDTH + 2, RADIO_DISPLAY_HEIGHT + 2);
    map2d = new Map2d(this);
    map2d->setGeometry(MAP2D_POSX, MAP2D_POSY, MAP2D_WIDTH, MAP2D_HEIGTH);

    allsysdisplay = new AllSysDisplay(this);
    allsysdisplay->setGeometry( ((this->width() / 2) - (ALLSYS_DISPLAY_WIDTH / 2)), ALLSYS_DISPLAY_POSY, ALLSYS_DISPLAY_WIDTH + 2, ALLSYS_DISPLAY_HEIGHT + 2);

    usDisplay = new UltrasonicDisplay(this);
    usDisplay->setGeometry( (this->width() / 2) - (ULTRASONIC_WIDTH/2), (this->height() / 2) - (ULTRASONIC_HEIGHT/2), ULTRASONIC_WIDTH, ULTRASONIC_HEIGHT);

    scienceDisplay = new ScientificDisplay(this);
    scienceDisplay->setGeometry(SCIENTIFIC_DISPLAY_POSX, SCIENTIFIC_DISPLAY_POSY, SCIENTIFIC_DISPLAY_WIDTH + 2, SCIENTIFIC_DISPLAY_HEIGHT + 2);

    vescDisplay = new VescDisplay(this);
    vescDisplay->setGeometry(VESC_DISPLAY_POSX, VESC_DISPLAY_POSY, VESC_DISPLAY_WIDTH + 2, VESC_DISPLAY_HEIGHT + 2);


    connect(m_mqttHarbinger, &MqttHarbinger::batteryChargeEvent,          batterydisplay, &BatteryDisplay::batteryChargeUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::batteryVoltageEvent,         batterydisplay, &BatteryDisplay::batteryVoltageUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::batteryTemperatureEvent,     batterydisplay, &BatteryDisplay::batteryTemperatureUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::batteryCurrentEvent,         batterydisplay, &BatteryDisplay::batteryCurrentUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::ultrasonicSensorStatusEvent, usDisplay,      &UltrasonicDisplay::ultrasonicSensorStatusUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::vescErpmEvent,               vescDisplay,    &VescDisplay::vescErpmUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::vescCurrent_motorEvent,      vescDisplay,    &VescDisplay::vescCurrent_motorUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::vescCurrent_inputEvent,      vescDisplay,    &VescDisplay::vescCurrent_inputUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::vescVoltage_inputEvent,      vescDisplay,    &VescDisplay::vescVoltage_inputUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::vescTemperature_mos1Event,   vescDisplay,    &VescDisplay::vescTemperature_mos1Update);
    connect(m_mqttHarbinger, &MqttHarbinger::vescTemperature_motorEvent,  vescDisplay,    &VescDisplay::vescTemperature_motorUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_cargoBayTemperatureEvent,   scienceDisplay, &ScientificDisplay::cargoBayTemperatureUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_cargoBayHumidityEvent,      scienceDisplay, &ScientificDisplay::cargoBayHumidityUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_cargoBayWeightEvent,        scienceDisplay, &ScientificDisplay::cargoBayWeightUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_drillWeightEvent,           scienceDisplay, &ScientificDisplay::drillWeightUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_proximityArmSensorEvent,    scienceDisplay, &ScientificDisplay::proximityArmSensorUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_proximityTurretSensorEvent, scienceDisplay, &ScientificDisplay::proximityTurretSensorUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::scientific_proximityEndEffectorEvent,  scienceDisplay,  &ScientificDisplay::proximityEndEffectorUpdate);
    connect(m_mqttHarbinger, &MqttHarbinger::position_change_event,                       map2d,          &Map2d::addPoint);
    connect(scienceDisplay,  &ScientificDisplay::cargoBayButtonPressedUpdate,       m_mqttHarbinger, &MqttHarbinger::cargoBayButtonPressed);
}

MainWindow::~MainWindow(){
}

void MainWindow::keyPressEvent (QKeyEvent *k) {
    switch ( tolower(char(k->key())) ) {
            case 'r':                               // reload
                qDebug("Pressed R");//void keyPressEvent(QKeyEvent *k) Q_DECL_OVERRIDE;
                update();
                break;
            case 'q':                               // quit//void keyPressEvent(QKeyEvent *k) Q_DECL_OVERRIDE;
              qDebug("Pressed Q: Quitting application");
              QCoreApplication::quit();
                break;
        }
}
