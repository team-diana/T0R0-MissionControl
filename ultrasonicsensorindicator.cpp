#include "ultrasonicsensorindicator.h"
#include <QDebug>

#define ROV_CHASSIS_IMG_WIDTH 200
#define ROV_CHASSIS_IMG_HEIGHT 484

UltrasonicSensorIndicator::UltrasonicSensorIndicator(QWidget *parent, int _direction, bool _oblique)  : QWidget(parent)
{
    direction = _direction;
    oblique = _oblique;
    status = 0;
}


void UltrasonicSensorIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor baseColor (255, 0, 0, 255);
    painter.setPen(baseColor);
    painter.setBrush(baseColor);

    //painter.drawRect(QRect(0, 0, this->width(), this->height()));


    QColor basicPieColor (254, 203, 47);
    switch (status)
    {
        case 0:
            basicPieColor = QColor(105, 105, 105);    // GRAY
            break;

        case 1:
            basicPieColor = QColor(222, 61, 45);     // RED
            break;

        case 2:
            basicPieColor = QColor(254, 203, 47);    // YELLOW
            break;

        case 3:
            basicPieColor = QColor(102, 162, 63);    // GREEN
            break;

        case 4:
            basicPieColor = QColor(58, 102, 161);    // BLUE
            break;
    }



    painter.setPen(basicPieColor);
    painter.setBrush(basicPieColor);

    QRect pieRec(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_WIDTH);
    if (!oblique) painter.drawPie(pieRec, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec, (direction * 1440) + 720 - 42, 84);
}
