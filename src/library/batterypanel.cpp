#include "batterypanel.h"

#define BAT_PANEL_OFFSET_LEFT ((BAT_PANEL_WIDTH - BAT_WIDTH) / 2)
#define BAT_PANEL_OFFSET_RIGHT BAT_WIDTH
//#define BAT_PANEL_OFFSET_UP ((BAT_PANEL_HEIGHT - BAT_HEIGHT) / 2)
#define BAT_PANEL_OFFSET_UP 15
#define BAT_PANEL_OFFSET_DOWN BAT_HEIGHT

BatteryPanel::BatteryPanel(QWidget *parent) : QWidget(parent)
{
	charge = 0;
}


void BatteryPanel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

	//painter.setBrush(QColor(190,190,190,50));			// Colored backgroud for DEBUG pourpouses
	//painter.drawRect(0, 0, BAT_PANEL_WIDTH, BAT_PANEL_HEIGHT);

    battery = new BatteryIndicator(this);
    battery->setGeometry(BAT_PANEL_OFFSET_LEFT, BAT_PANEL_OFFSET_UP, BAT_PANEL_OFFSET_RIGHT, BAT_PANEL_OFFSET_DOWN);
    battery->show();

	temperature = new BatteryTemperatureIndicator(this);
    temperature->setGeometry(BAT_PANEL_OFFSET_LEFT, BAT_PANEL_OFFSET_UP, BAT_PANEL_OFFSET_RIGHT, BAT_PANEL_OFFSET_DOWN);
    temperature->show();

    battery->setCharge(charge);

}

void BatteryPanel::setCharge(int _charge)
{
	charge = _charge;
}
