#include "ultrasonicsensorindicator.h"
#include <QDebug>

#define ROV_CHASSIS_IMG_WIDTH 200
#define ROV_CHASSIS_IMG_HEIGHT 484

UltrasonicSensorIndicator::UltrasonicSensorIndicator(QWidget *parent)  : QWidget(parent)
{

}


void UltrasonicSensorIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor baseColor (255, 0, 0, 255);
    painter.setPen(baseColor);
    painter.setBrush(baseColor);

    painter.drawEllipse(QRect(0, 0, this->width(), this->height()));

    QColor basicPieColor (255, 101, 120, 255);
    painter.setPen(basicPieColor);
    painter.setBrush(basicPieColor);

    QRect pieRec((this->width() - 350)/2, (this->height()/2) - ROV_CHASSIS_IMG_HEIGHT, 350,350);
    painter.drawPie(pieRec, 1440 - 42, 84);
}
