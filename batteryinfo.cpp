#include "batteryinfo.h"
#include <QDebug>

BatteryInfo::BatteryInfo(QWidget *parent) : QWidget(parent)
{
    voltage = 99.9;
    temperature = 99.9;
    current = 99.9;
    //in_use = false;
}


void BatteryInfo::paintEvent(QPaintEvent *)
{

	QPainter painter(this);
    painter.setPen(QColor(10,10,10,255));
    painter.setBrush(QColor(10,10,10,255));
    painter.drawRect(0, 0, this->width(), this->height());

    qDebug() << "CURRENT " << current;
    painter.setPen(QColor(222, 61, 25));// 255,0,0,255));
	QString temperatureValueString;
	temperatureValueString.sprintf("%3.1f °C", temperature);
    painter.drawText(QRect(0, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignVCenter, temperatureValueString);

    // Separator char
    //painter.setPen(QColor(255,255,255, 255));
    //painter.drawText(QRect(38, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignVCenter, "|");

	QString ampereValueString;
    ampereValueString.sprintf("%4.1f A", current);
	painter.setPen(QColor(205,150,10, 255));
    painter.drawText(QRect(73, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignVCenter, ampereValueString);

}


void BatteryInfo::setTemperature(float _temperature)
{
    this->temperature = _temperature;
    this->update();
}

void BatteryInfo::setCurrent(float _current)
{
    this->current = _current;
    this->update();
}

/*
void BatteryInfo::setInUse(bool status)
{
    in_use = true;
    this->update();
}
*/
