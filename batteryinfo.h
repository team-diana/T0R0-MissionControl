#ifndef BATTERYINFO_H
#define BATTERYINFO_H

#include <QWidget>
#include <QPainter>
#include <QFont>
//#include "batteryindicator.h"

#define NEUTRAL 0
#define WARNING 1
#define ALERT 2

#define BAT_TEMP_WIDTH 150
#define BAT_TEMP_HEIGHT 20

class BatteryInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryInfo(QWidget *parent = nullptr);

    void setTemperature(float _temperature);
    void setCurrent(float _current);

signals:

public slots:


private:
    float voltage, temperature, current;
    bool in_use;

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // BATTERYINFO_H
