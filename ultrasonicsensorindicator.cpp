#include "ultrasonicsensorindicator.h"
#include <QDebug>

#define ROV_CHASSIS_IMG_WIDTH 200
#define ROV_CHASSIS_IMG_HEIGHT 484

#define SIZECOLORSCALE_YELLOW 0.58
#define SIZECOLORSCALE_RED    0.3

UltrasonicSensorIndicator::UltrasonicSensorIndicator(QWidget *parent, int _direction, bool _oblique)  : QWidget(parent)
{
    direction = _direction;
    oblique = _oblique;
    status = -1;
}


void UltrasonicSensorIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor baseColor (255, 0, 0, 255);
    painter.setPen(baseColor);
    painter.setBrush(baseColor);

    //painter.drawRect(QRect(0, 0, this->width(), this->height()));


    QColor basicPieColor   (254, 203, 47);     // BASIC
    QColor pieColor_gray   (105, 105, 105);    // GRAY
    QColor pieColor_yellow (254, 203, 47);     // YELLOW
    QColor pieColor_red    (222, 61, 45);      // RED
    QColor pieColor_green  (102, 162, 63);     // GREEN
    QColor pieColor_blue   (58, 102, 161);     // BLUE

    painter.setPen(basicPieColor);         // GRAY
    painter.setBrush(basicPieColor);
    QRect pieRec_gray(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_WIDTH);
    if (!oblique) painter.drawPie(pieRec_gray, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_gray, (direction * 1440) + 720 - 42, 84);

    painter.setPen(pieColor_green);          // GREEN
    painter.setBrush(pieColor_green);
    QRect pieRec_green(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_WIDTH);
    if (!oblique) painter.drawPie(pieRec_green, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_green, (direction * 1440) + 720 - 42, 84);

    painter.setPen(pieColor_yellow);          // YELLOW
    painter.setBrush(pieColor_yellow);
    int startPoint_X_Yellow = (( this->width()  - (this->width()  * SIZECOLORSCALE_YELLOW)) / 2);
    int startPoint_Y_Yellow = (( this->height() - (this->height() * SIZECOLORSCALE_YELLOW)) / 2);
    QRect pieRec_yellow(startPoint_X_Yellow, startPoint_Y_Yellow, SIZECOLORSCALE_YELLOW*ULTRASONIC_PIE_WIDTH, SIZECOLORSCALE_YELLOW*ULTRASONIC_PIE_WIDTH);
    if (!oblique) painter.drawPie(pieRec_yellow, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_yellow, (direction * 1440) + 720 - 42, 84);

    painter.setPen(pieColor_red);          // RED
    painter.setBrush(pieColor_red);
    int startPoint_X_Red = (( this->width()  - (this->width()  * SIZECOLORSCALE_RED)) / 2);
    int startPoint_Y_Red = (( this->height() - (this->height() * SIZECOLORSCALE_RED)) / 2);
    QRect pieRec_red(startPoint_X_Red, startPoint_Y_Red, SIZECOLORSCALE_RED*ULTRASONIC_PIE_WIDTH, SIZECOLORSCALE_RED*ULTRASONIC_PIE_WIDTH);
    if (!oblique) painter.drawPie(pieRec_red, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_red, (direction * 1440) + 720 - 42, 84);


    // switch (status)
    // {
    //     case 0: // GRAY
    //         basicPieColor = QColor(105, 105, 105);
    //         break;
    //
    //     case 1: // RED
    //         basicPieColor = QColor(222, 61, 45);
    //         break;
    //
    //     case 2: // YELLOW
    //         basicPieColor = QColor(254, 203, 47);
    //         break;
    //
    //     case 3: // GREEN
    //         painter.setPen(pieColor_blue);
    //         painter.setBrush(pieColor_blue);
    //
    //         QRect pieRec(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_WIDTH);
    //         if (!oblique) painter.drawPie(pieRec, (direction * 1440) - 42, 84);
    //         else painter.drawPie(pieRec, (direction * 1440) + 720 - 42, 84);
    //         break;
    //
    //     case 4: // BLUE
    //         painter.setPen(pieColor_blue);
    //         painter.setBrush(pieColor_blue);
    //
    //         QRect pieRec(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_WIDTH);
    //         if (!oblique) painter.drawPie(pieRec, (direction * 1440) - 42, 84);
    //         else painter.drawPie(pieRec, (direction * 1440) + 720 - 42, 84);
    //         break;
    //
    //     default:
    //         break;
    // }







}


void UltrasonicSensorIndicator::setStatus(int _status)
{
    status = _status;
    this->update();
}
//void setDirection( int direction);
//void setOblique(bool oblique);
