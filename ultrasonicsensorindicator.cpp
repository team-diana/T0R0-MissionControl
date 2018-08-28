#include "ultrasonicsensorindicator.h"
#include <QDebug>

#define ROV_CHASSIS_IMG_WIDTH 200
#define ROV_CHASSIS_IMG_HEIGHT 484

UltrasonicSensorIndicator::UltrasonicSensorIndicator(QWidget *parent, int _direction)  : QWidget(parent)
{
    direction = _direction;
}


void UltrasonicSensorIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor baseColor (255, 0, 0, 255);
    painter.setPen(baseColor);
    painter.setBrush(baseColor);

    //painter.drawRect(QRect(0, 0, this->width(), this->height()));

    QColor basicPieColor (254, 203, 47);
    painter.setPen(basicPieColor);
    painter.setBrush(basicPieColor);

    QRect pieRec(0, 0, 350,350);
    painter.drawPie(pieRec, (direction * 1440) - 42, 84);
}
