#include "batterytempindicator.h"

BatteryTemperatureIndicator::BatteryTemperatureIndicator(QWidget *parent) : QWidget(parent)
{
    //temperature = 100;
    //in_use = false;
}


void BatteryTemperatureIndicator::paintEvent(QPaintEvent *)
{

	QPainter painter(this);
	painter.setPen(QColor(255,0,0, 255));
	painter.setBrush(QColor(255,0,0, 255));
	float temperature = 25.4;
	float ampere = 11.4;

	QString temperatureValueString;
	temperatureValueString.sprintf("%3.1f °C", temperature);
	painter.drawText(QRect(0, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignCenter, temperatureValueString);

	painter.setPen(QColor(255,255,255, 255));
	painter.drawText(QRect(38, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignCenter, "|");

	QString ampereValueString;
	ampereValueString.sprintf("%4.1f A", ampere);
	painter.setPen(QColor(205,150,10, 255));
	painter.drawText(QRect(73, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignCenter, ampereValueString);

}

/*
void BatteryTemperatureIndicator::setCharge(int _temperature)
{
    this->temperature = _temperature;
    this->update();
}

void BatteryTemperatureIndicator::setInUse(bool status)
{
    in_use = true;
    this->update();
}
*/
