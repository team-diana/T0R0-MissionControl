#ifndef BATTERYPANEL_H
#define BATTERYPANEL_H

#include "batteryindicator.h"
#include "batteryinfo.h"
#include <QWidget>
#include <QPainter>

#define BAT_PANEL_POSX 500
#define BAT_PANEL_POSY 300
#define BAT_PANEL_WIDTH 332
#define BAT_PANEL_HEIGHT 49

//#define COL_SPACER 10
//#define ROW_SPACER 10

class BatteryPanel : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryPanel(QWidget *parent = nullptr);
signals:

public slots:
	void setCharge(int charge);
    void setTemperature(float _temperature);
    void setCurrent(float _current);

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
	int charge;
    float voltage, temperature, current;
    BatteryIndicator *battIndicator;
    BatteryInfo *battInfo;
};

#endif // BATTERYPANEL_H
