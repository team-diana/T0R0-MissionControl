#include "batterypanel.h"

//#define BAT_PANEL_OFFSET_LEFT ((BAT_PANEL_WIDTH - BAT_WIDTH) / 2)
#define BAT_PANEL_OFFSET_LEFT 0
#define BAT_PANEL_OFFSET_RIGHT BAT_WIDTH
//#define BAT_PANEL_OFFSET_UP ((BAT_PANEL_HEIGHT - BAT_HEIGHT) / 2)
#define BAT_PANEL_OFFSET_UP 15
#define BAT_PANEL_OFFSET_DOWN BAT_HEIGHT

BatteryPanel::BatteryPanel(QWidget *parent) : QWidget(parent)
{
	charge = 0;

    battIndicator = new BatteryIndicator(this);
    battIndicator->setGeometry(BAT_PANEL_OFFSET_LEFT, BAT_PANEL_OFFSET_UP, BAT_PANEL_OFFSET_RIGHT, BAT_PANEL_OFFSET_DOWN);
    battIndicator->setCharge(charge);

    battInfo = new BatteryInfo(this);
    battInfo->setGeometry(BAT_PANEL_OFFSET_LEFT + BAT_PANEL_OFFSET_RIGHT + 15, BAT_PANEL_OFFSET_UP, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT);
}


void BatteryPanel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

	//painter.setBrush(QColor(190,190,190,50));			// Colored backgroud for DEBUG pourpouses
	//painter.drawRect(0, 0, BAT_PANEL_WIDTH, BAT_PANEL_HEIGHT);

    battIndicator->show();
    battInfo->show();
}

void BatteryPanel::setCharge(int _charge)
{
	charge = _charge;
    battIndicator->setCharge(charge);
}

void BatteryPanel::setTemperature(float _temperature)
{
    temperature = _temperature;
    battInfo->setTemperature(temperature);
}

void BatteryPanel::setCurrent(float _current)
{
    current = _current;
    battInfo->setCurrent(current);
}
