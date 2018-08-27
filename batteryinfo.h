#ifndef BATTERYINFO_H
#define BATTERYINFO_H

#include <QWidget>
#include <QPainter>
#include <QFont>
//#include "batteryindicator.h"

#define NEUTRAL 0
#define WARNING 1
#define ALERT 2

#define BAT_TEMP_WIDTH 200
#define BAT_TEMP_HEIGHT 20

class BatteryInfo : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryInfo(QWidget *parent = 0);

signals:

public slots:


private:
    int temperature;
    bool in_use;

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // BATTERYINFO_H
