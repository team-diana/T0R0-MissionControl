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

	//int panelRightExtreme = BAT_PANEL_WIDTH + BAT_DISPLAY_OFFSET_LEFT + BAT_DISPLAY_OFFSET_RIGHT;
	pbattery1 = new BatteryPanel(this);
	pbattery1->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP, BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);
	pbattery1->show();

	pbattery2 = new BatteryPanel(this);
	pbattery2->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+1*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);
	pbattery2->show();

	pbattery3 = new BatteryPanel(this);
	pbattery3->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+2*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);
	pbattery3->show();

	pbattery4 = new BatteryPanel(this);
	pbattery4->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+3*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);
	pbattery4->show();

	pbattery5 = new BatteryPanel(this);
	pbattery5->setGeometry(BAT_DISPLAY_OFFSET_LEFT, GROUP_PANEL_OFFSET_UP+4*(BAT_PANEL_HEIGHT+PANEL_VERTICAL_SPACER), BAT_PANEL_WIDTH-(PANEL_ORIZONTAL_SPACER/2), BAT_PANEL_HEIGHT);
	pbattery5->show();

	pbattery1->setCharge(9);
	pbattery2->setCharge(25);
	pbattery3->setCharge(46);
	pbattery4->setCharge(67);
	pbattery5->setCharge(88);
	/*
	pbattery6->setCharge(59);
	pbattery7->setCharge(61);
	pbattery8->setCharge(72);
	pbattery9->setCharge(84);
	pbattery10->setCharge(100);
	*/
}

void BatteryDisplay::batteryUpdate(int idCell, QString dataDescription, QString data) {
    int val = data.toInt();
    if (dataDescription == "voltage") {
        switch (idCell) {
            case 1:
                pbattery1->setCharge(val);
                qDebug() << "BATT 1: " << val;
            break;
            case 2:
                pbattery2->setCharge(val);
            break;
            case 3:
                pbattery3->setCharge(val);
            break;
            case 4:
                pbattery4->setCharge(val);
            break;
            case 5:
                pbattery5->setCharge(val);
            break;
        }
    }
}
