#include "batterytempindicator.h"

BatteryTemperatureIndicator::BatteryTemperatureIndicator(QWidget *parent) : QWidget(parent)
{
    //temperature = 100;
    //in_use = false;
}


void BatteryTemperatureIndicator::paintEvent(QPaintEvent *)
{
	QPainter painter;

	//painter.drawText(QRect(0, 0, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT), Qt::AlignCenter, 35.2);
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
