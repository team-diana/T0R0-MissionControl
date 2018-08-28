#include "ultrasonicdisplay.h"
#include <QLabel>
#include <QDebug>
#define ROVIMG_WIDTH 230
#define ROVIMG_HEIGHT 374

#define CHASSIS_X0 51
#define CHASSIS_Y0 89
#define CHASSIS_X1 179
#define CHASSIS_Y1 282

#define CHASSIS_WIDTH  (CHASSIS_X1 - CHASSIS_X0)
#define CHASSIS_HEIGHT (CHASSIS_Y1 - CHASSIS_Y0)

#define ULTRASONIC_PIE_WIDTH 350
#define ULTRASONIC_PIE_HEIGHT 350

#define ULTRASONIC_PIE_FRONT_SPACING (CHASSIS_WIDTH/4)

UltrasonicDisplay::UltrasonicDisplay(QWidget *parent) : QWidget(parent)
{
    //usIndicator = new UltrasonicSensorIndicator (this);

    //battIndicator->setCharge(charge);

    //for (int i=0; i<18; i++) usIndicator[i] = new UltrasonicSensorIndicator(this);

    int centerImageWidth = (this->width() - 350)/2;


    int roverImageStartX = (ULTRASONIC_WIDTH - ROVIMG_WIDTH) /2;
    int roverImageStartY = (ULTRASONIC_HEIGHT - ROVIMG_HEIGHT) /2;

    // FRONT ULTRASONIC SENSORs
    int frontStartingPointX = roverImageStartX + CHASSIS_X0;
    int frontStartingPointY = roverImageStartY + CHASSIS_Y0 - CHASSIS_HEIGHT +15;
    qDebug() << roverImageStartX << " | " << frontStartingPointX << " | " << CHASSIS_WIDTH;
    for (int i=4; i<=6; i++)
    {
        usIndicator[i] = new UltrasonicSensorIndicator(this, 1);
        usIndicator[i]->setGeometry(frontStartingPointX + ((i-3)*ULTRASONIC_PIE_FRONT_SPACING) - 175, frontStartingPointY, ULTRASONIC_PIE_WIDTH,ULTRASONIC_PIE_HEIGHT);
    }

    // REAR ULTRASONIC SENSORs
    int rearStartingPointX = frontStartingPointX;
    int rearStartingPointY = roverImageStartY + CHASSIS_Y1 - CHASSIS_HEIGHT;
    for (int i=13; i<=15; i++)
    {
        usIndicator[i] = new UltrasonicSensorIndicator(this, 3);
        usIndicator[i]->setGeometry(rearStartingPointX + ((i-12)*ULTRASONIC_PIE_FRONT_SPACING) - 175, rearStartingPointY, ULTRASONIC_PIE_WIDTH,ULTRASONIC_PIE_HEIGHT);
    }

    int rearStartingPointX = frontStartingPointX;
    int rearStartingPointY = roverImageStartY + CHASSIS_Y1 - CHASSIS_HEIGHT;
    for (int i=13; i<=15; i++)
    {
        usIndicator[i] = new UltrasonicSensorIndicator(this, 3);
        usIndicator[i]->setGeometry(rearStartingPointX + ((i-12)*ULTRASONIC_PIE_FRONT_SPACING) - 175, rearStartingPointY, ULTRASONIC_PIE_WIDTH,ULTRASONIC_PIE_HEIGHT);
    }

    //usIndicator[0]->setGeometry(500, 900, 100, 100);
}

void UltrasonicDisplay::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor basicColor (80, 101, 120, 255);
    painter.setPen(basicColor);
    painter.setBrush(basicColor);

    painter.drawRect(0,0, this->width(), this->height());

    QLabel *pixlabel = new QLabel(this);
    QPixmap pixrover(":/Images/rover_up-230x374.png");
    pixlabel->setPixmap(pixrover.scaled(ROVIMG_WIDTH, ROVIMG_HEIGHT, Qt::KeepAspectRatio));
    pixlabel->setGeometry( (this->width() - ROVIMG_WIDTH) /2 , (this->height() - ROVIMG_HEIGHT) /2, ROVIMG_WIDTH, ROVIMG_HEIGHT );
    pixlabel->show();

    QColor basicPieColor (254, 203, 47);
    painter.setPen(basicPieColor);
    painter.setBrush(basicPieColor);

    QRect pieRec((this->width() - 350)/2, (this->height()/2) - ROVIMG_HEIGHT+80, 350,350);
    //painter.drawPie(pieRec, 1440 - 42, 84);

    //usIndicator[0]->show();
    int i;
    for (i=4; i<=6; i++)    // Frontal Ultrasonic Sensor
    {
        //usIndicator[i+1]->show();
    }
}
