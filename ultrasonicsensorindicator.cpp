#include "ultrasonicsensorindicator.h"
#include <QDebug>

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

}
