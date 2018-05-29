#ifndef BATTERYINDICATOR_H
#define BATTERYINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>
//#include "batteryindicator.h"

#define FULLCHARGE 100
#define GOODCHARGE 75
#define MEDCHARGE 50
#define LOWCHARGE 25
#define NOTCHARGE 0

#define BAT_WIDTH 140
#define BAT_HEIGHT 20

class BatteryIndicator : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryIndicator(QWidget *parent = 0);

signals:

public slots:
    void setCharge(int charge);
    void setInUse(bool status);

private:
    int charge;
    bool in_use;

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // BATTERYINDICATOR_H
