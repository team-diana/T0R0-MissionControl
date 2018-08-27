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
}


void BatteryPanel::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

	//painter.setBrush(QColor(190,190,190,50));			// Colored backgroud for DEBUG pourpouses
	//painter.drawRect(0, 0, BAT_PANEL_WIDTH, BAT_PANEL_HEIGHT);

    battIndicator = new BatteryIndicator(this);
    battIndicator->setGeometry(BAT_PANEL_OFFSET_LEFT, BAT_PANEL_OFFSET_UP, BAT_PANEL_OFFSET_RIGHT, BAT_PANEL_OFFSET_DOWN);
    battIndicator->show();

    battInfo = new BatteryInfo(this);
    battInfo->setGeometry(BAT_PANEL_OFFSET_LEFT + BAT_PANEL_OFFSET_RIGHT - 45, BAT_PANEL_OFFSET_UP, BAT_TEMP_WIDTH, BAT_TEMP_HEIGHT);
    battInfo->show();

    battIndicator->setCharge(charge);

}

void BatteryPanel::setCharge(int _charge)
{
	charge = _charge;
}
