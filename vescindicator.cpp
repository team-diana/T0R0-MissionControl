#include "vescindicator.h"
#include <QDebug>

vescIndicator::vescIndicator(QWidget *parent, int id) : QWidget(parent){
    this->id = id;
}

void vescIndicator::paintEvent(QPaintEvent *event){

}

void vescIndicator::setErpm(float _erpm){
    qDebug() << "erpm" << _erpm;
    this->erpm = _erpm;
}
void vescIndicator::setCurrent_motor(float _current_motor){
    qDebug() << "current_motor" << _current_motor;
    this->current_motor = _current_motor;
}
void vescIndicator::setCurrent_input(float _current_input){
    qDebug() << "current_input" << _current_input;
    this->current_input = _current_input;
}
void vescIndicator::setVoltage_input(float _voltage_input){
    qDebug() << "voltage_input" << _voltage_input;
    this->voltage_input = _voltage_input;
}
void vescIndicator::setTemperature_mos1(float _temperature_mos1){
    qDebug() << "temperature_mos1" << _temperature_mos1;
    this->temperature_mos1 = _temperature_mos1;
}
void vescIndicator::setTemperature_motor(float _temperature_motor){
    qDebug() << "temperature_motor" << _temperature_motor;
    this->temperature_motor = _temperature_motor;
}

/*#include "ultrasonicsensorindicator.h"
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
    percentage = 1;
}


void UltrasonicSensorIndicator::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor baseColor (255, 0, 0, 255);
    painter.setPen(baseColor);
    painter.setBrush(baseColor);

    //painter.drawRect(QRect(0, 0, this->width(), this->height()));

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);


    QColor basicPieColor   (254, 203, 47);     // BASIC
    QColor pieColor_gray   (105, 105, 105);    // GRAY
    QColor pieColor_yellow (254, 203, 47);     // YELLOW
    QColor pieColor_red    (222, 61, 45);      // RED
    QColor pieColor_green  (102, 162, 63);     // GREEN
    QColor pieColor_blue   (58, 102, 161);     // BLUE

    painter.setPen(basicPieColor);         // GRAY
    painter.setBrush(basicPieColor);
    QRect pieRec_gray(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    if (!oblique) painter.drawPie(pieRec_gray, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_gray, (direction * 1440) + 720 - 42, 84);

    painter.setPen(pieColor_green);          // GREEN
    painter.setBrush(pieColor_green);
    QRect pieRec_green(0, 0, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    if (!oblique) painter.drawPie(pieRec_green, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_green, (direction * 1440) + 720 - 42, 84);

    painter.setPen(pieColor_yellow);          // YELLOW
    painter.setBrush(pieColor_yellow);
    int startPoint_X_Yellow = (( this->width()  - (this->width()  * SIZECOLORSCALE_YELLOW)) / 2);
    int startPoint_Y_Yellow = (( this->height() - (this->height() * SIZECOLORSCALE_YELLOW)) / 2);
    QRect pieRec_yellow(startPoint_X_Yellow, startPoint_Y_Yellow, SIZECOLORSCALE_YELLOW*ULTRASONIC_PIE_WIDTH, SIZECOLORSCALE_YELLOW*ULTRASONIC_PIE_HEIGHT);
    if (!oblique) painter.drawPie(pieRec_yellow, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_yellow, (direction * 1440) + 720 - 42, 84);

    painter.setPen(pieColor_red);          // RED
    painter.setBrush(pieColor_red);
    int startPoint_X_Red = (( this->width()  - (this->width()  * SIZECOLORSCALE_RED)) / 2);
    int startPoint_Y_Red = (( this->height() - (this->height() * SIZECOLORSCALE_RED)) / 2);
    QRect pieRec_red(startPoint_X_Red, startPoint_Y_Red, SIZECOLORSCALE_RED*ULTRASONIC_PIE_WIDTH, SIZECOLORSCALE_RED*ULTRASONIC_PIE_HEIGHT);
    if (!oblique) painter.drawPie(pieRec_red, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_red, (direction * 1440) + 720 - 42, 84);


    // With the colored scale background cover
    //  with dynamic basic background to display distance.

    int startPoint_X_value = (( this->width()  - (this->width()  * (percentage))) / 2);
    int startPoint_Y_value = (( this->height() - (this->height() * (percentage))) / 2);
    painter.setPen(pieColor_gray);         // GRAY
    painter.setBrush(pieColor_gray);
    QRect pieRec_value(startPoint_X_value, startPoint_Y_value, (percentage*ULTRASONIC_PIE_WIDTH), (percentage*ULTRASONIC_PIE_HEIGHT));
    if (!oblique) painter.drawPie(pieRec_value, (direction * 1440) - 42, 84);
    else painter.drawPie(pieRec_value, (direction * 1440) + 720 - 42, 84);


}


void UltrasonicSensorIndicator::setStatus(int _status)
{
    percentage = (float) _status/100.0;
    qDebug() << "percentage" << percentage;
    this->update();
}
*/
