#include "batterydisplay.h"
#include <QtMqtt/QMqttClient>
#include "mqttharbinger.h"

#define BAT_DISPLAY_OFFSET_LEFT 20
#define BAT_DISPLAY_OFFSET_UP 22
#define BAT_DISPLAY_OFFSET_RIGHT 20
#define BAT_DISPLAY_OFFSET_DOWN 22

#define GROUP_PANEL_OFFSET_UP 25
#define GROUP_PANEL_OFFSET_LEFT 2
#define GROUP_PANEL_OFFSET_RIGHT 2
#define PANEL_VERTICAL_SPACER 2
#define PANEL_ORIZONTAL_SPACER 2

BatteryDisplay::BatteryDisplay(QWidget *parent) : QWidget(parent)
{
    pbattery[0] = new BatteryPanel(this);
    pbattery[0]->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP, BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery[1] = new BatteryPanel(this);
    pbattery[1]->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+1*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery[2] = new BatteryPanel(this);
    pbattery[2]->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+2*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery[3] = new BatteryPanel(this);
    pbattery[3]->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+3*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery[4] = new BatteryPanel(this);
    pbattery[4]->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+4*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    /* TEST
    pbattery[0]->setCharge(9);
    pbattery[1]->setCharge(25);
    pbattery[2]->setCharge(46);
    pbattery[3]->setCharge(67);
    pbattery[4]->setCharge(88);
    */
}



void BatteryDisplay::paintEvent(QPaintEvent *)
{

	QPainter painter(this);

	QLinearGradient m_gradient(0,0,0,BAT_DISPLAY_HEIGHT);
	//m_gradient.setColorAt(0.0, QColor(129,152,188,255));
	//m_gradient.setColorAt(1.0, QColor(84,109,136,255));
	m_gradient.setColorAt(0.0, QColor(10, 10, 10, 255));
	m_gradient.setColorAt(1.0, QColor(10, 10, 10, 255));
	painter.fillRect(QRect(0, 0, BAT_DISPLAY_WIDTH, BAT_DISPLAY_HEIGHT), m_gradient);

	painter.setPen(pale_lightblue);
	painter.drawText(1, 17, "Batteries");

	painter.setBrush(QColor(0,0,0,0));
	painter.drawRect(0, 0, BAT_DISPLAY_WIDTH, BAT_DISPLAY_HEIGHT);

    for (int i=0; i<5; i++) pbattery[i]->show();

	//int panelRightExtreme = BAT_PANEL_WIDTH + BAT_DISPLAY_OFFSET_LEFT + BAT_DISPLAY_OFFSET_RIGHT;
}

void BatteryDisplay::batteryChargeUpdate(int idCell, int percentage)
{
    qDebug() << "BATT" << idCell << " [CHARGE %] > " << percentage;

    if (idCell >= 1 && idCell <= 5) pbattery[idCell-1]->setCharge(percentage);
}

void BatteryDisplay::batteryVoltageUpdate(int idCell, float value)
{
    qDebug() << "BATT" << idCell << " [VOLTAGE V] > " << value;
    //if (idCell >= 1 && idCell <= 5)  pbattery[idCell-1]->setVoltage (value);
}

void BatteryDisplay::batteryTemperatureUpdate(int idCell, float value)
{
    qDebug() << "BATT" << idCell << " [TEMPERATURE C] > " << value;
    if (idCell >= 1 && idCell <= 5) pbattery[idCell-1]->setTemperature(value);
}

void BatteryDisplay::batteryCurrentUpdate(int idCell, float value)
{
    qDebug() << "BATT" << idCell << " [CURRENT A] > " << value;
    if (idCell >= 1 && idCell <= 5) pbattery[idCell-1]->setCurrent(value);
}
