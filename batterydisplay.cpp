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
    pbattery1 = new BatteryPanel(this);
    pbattery1->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP, BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery2 = new BatteryPanel(this);
    pbattery2->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+1*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery3 = new BatteryPanel(this);
    pbattery3->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+2*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery4 = new BatteryPanel(this);
    pbattery4->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+3*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    pbattery5 = new BatteryPanel(this);
    pbattery5->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+4*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);

    /* TEST
    pbattery1->setCharge(9);
    pbattery2->setCharge(25);
    pbattery3->setCharge(46);
    pbattery4->setCharge(67);
    pbattery5->setCharge(88);
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

    pbattery1->show();
    pbattery2->show();
    pbattery3->show();
    pbattery4->show();
    pbattery5->show();




	//int panelRightExtreme = BAT_PANEL_WIDTH + BAT_DISPLAY_OFFSET_LEFT + BAT_DISPLAY_OFFSET_RIGHT;

	/*
	pbattery6->setCharge(59);
	pbattery7->setCharge(61);
	pbattery8->setCharge(72);
	pbattery9->setCharge(84);
	pbattery10->setCharge(100);
	*/
}

void BatteryDisplay::batteryChargeUpdate(int idCell, int percentage)
{
    qDebug() << "BATT" << idCell << " [CHARGE %] > " << percentage;
    switch (idCell)
    {
        case 1:
            pbattery1->setCharge(percentage);
            pbattery1->update();
        break;
        case 2:
            pbattery2->setCharge(percentage);
            pbattery2->update();
        break;
        case 3:
            pbattery3->setCharge(percentage);
            pbattery3->update();
        break;
        case 4:
            pbattery4->setCharge(percentage);
            pbattery4->update();
        break;
        case 5:
            pbattery5->setCharge(percentage);
            pbattery5->update();
        break;
    }

}

void BatteryDisplay::batteryVoltageUpdate(int idCell, float value)
{
    qDebug() << "BATT" << idCell << " [VOLTAGE V] > " << value;
    switch (idCell)
    {
        case 1:
            //pbattery1->setCharge(percentage);
        break;
        case 2:
            //pbattery2->setCharge(percentage);
        break;
        case 3:
            //pbattery3->setCharge(percentage);
        break;
        case 4:
            //pbattery4->setCharge(percentage);
        break;
        case 5:
            //pbattery5->setCharge(percentage);
        break;
    }

}

void BatteryDisplay::batteryTemperatureUpdate(int idCell, float value)
{
    qDebug() << "BATT" << idCell << " [TEMPERATURE C] > " << value;
    switch (idCell)
    {
        case 1:
            pbattery1->setTemperature(value);
        break;
        case 2:
            pbattery2->setTemperature(value);
        break;
        case 3:
            pbattery3->setTemperature(value);
        break;
        case 4:
            pbattery4->setTemperature(value);
        break;
        case 5:
            pbattery5->setTemperature(value);
        break;
    }

}

void BatteryDisplay::batteryCurrentUpdate(int idCell, float value)
{
    qDebug() << "BATT" << idCell << " [CURRENT A] > " << value;
    switch (idCell)
    {
        case 1:
            pbattery1->setCurrent(value);
        break;
        case 2:
            pbattery2->setCurrent(value);
        break;
        case 3:
            pbattery3->setCurrent(value);
        break;
        case 4:
            pbattery4->setCurrent(value);
        break;
        case 5:
            pbattery5->setCurrent(value);
        break;
    }

}
