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

#define ULTRASONIC_PIE_FRONT_SPACING (CHASSIS_WIDTH/4)
#define ULTRASONIC_PIE_SIDE_SPACING (CHASSIS_HEIGHT/6)

UltrasonicDisplay::UltrasonicDisplay(QWidget *parent) : QWidget(parent)
{
    //usIndicator = new UltrasonicSensorIndicator (this);

    //battIndicator->setCharge(charge);

    //for (int i=0; i<18; i++) usIndicator[i] = new UltrasonicSensorIndicator(this);

    // FRONT ULTRASONIC SENSORs
    for (int i=0; i<=2; i++)   usIndicator[i] = new UltrasonicSensorIndicator(this, 1);

    // REAR ULTRASONIC SENSORs
    for (int i=7; i<=9; i++)   usIndicator[i] = new UltrasonicSensorIndicator(this, 3);

    // LEFT ULTRASONIC SENSORs
    for (int i=10; i<=13; i++) usIndicator[i] = new UltrasonicSensorIndicator(this, 2);

    // RIGHT ULTRASONIC SENSORs
    for (int i=3; i<=6; i++)   usIndicator[i] = new UltrasonicSensorIndicator(this, 0);

    // OBLIQUE ULTRASONIC SENSORs
    for (int i=14; i<=17; i++) usIndicator[i] = new UltrasonicSensorIndicator(this, i-14, 1);

    //usIndicator[0]->setGeometry(500, 900, 100, 100);
}

void UltrasonicDisplay::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor basicColor (10, 10, 10, 255); // (80, 101, 120, 255);
    painter.setPen(basicColor);
    painter.setBrush(basicColor);

    painter.drawRect(0,0, this->width(), this->height());

    QColor frameColor (45, 229, 171, 255);
    painter.fillRect(QRect(0, 0, this->width(), this->height()), basicColor);

    painter.setPen(QColor(252, 252, 255, 255));
    painter.drawText(QRect(1, 1, this->width()-1, 25), Qt::AlignHCenter, "Ultrasonic Sensor Map");

    QPen borderpen(QColor(48, 118, 230, 255));
    borderpen.setWidth(3);
    painter.setPen(borderpen);
    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, this->width(), this->height());

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


    int roverImageStartX = (ULTRASONIC_WIDTH - ROVIMG_WIDTH) /2;
    int roverImageStartY = (ULTRASONIC_HEIGHT - ROVIMG_HEIGHT) /2;
    // FRONT ULTRASONIC SENSORs
    int frontStartingPointX = roverImageStartX + CHASSIS_X0;
    int frontStartingPointY = roverImageStartY + CHASSIS_Y0 - CHASSIS_HEIGHT +15;
    //qDebug() << roverImageStartX << " | " << frontStartingPointX << " | " << CHASSIS_WIDTH;
    for (int i=0; i<=2; i++)
    {
        usIndicator[i]->setGeometry(frontStartingPointX + ((i+1)*ULTRASONIC_PIE_FRONT_SPACING) - 175, frontStartingPointY, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    }

    // REAR ULTRASONIC SENSORs
    int rearStartingPointX = frontStartingPointX;
    int rearStartingPointY = roverImageStartY + CHASSIS_Y1 - CHASSIS_HEIGHT;
    for (int i=7; i<=9; i++)
    {
        usIndicator[i]->setGeometry(rearStartingPointX + ((i-6)*ULTRASONIC_PIE_FRONT_SPACING) - 175, rearStartingPointY, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    }

    // LEFT ULTRASONIC SENSORs
    int leftStartingPointX = frontStartingPointX - (ULTRASONIC_PIE_WIDTH/2);
    int leftStartingPointY = frontStartingPointY;
    for (int i=10; i<=13; i++)
    {
        if (i<=11) usIndicator[i]->setGeometry(leftStartingPointX, leftStartingPointY + ((i-9)*ULTRASONIC_PIE_SIDE_SPACING), ULTRASONIC_PIE_WIDTH,ULTRASONIC_PIE_HEIGHT);
        else usIndicator[i]->setGeometry(leftStartingPointX, leftStartingPointY + ((i-8)*ULTRASONIC_PIE_SIDE_SPACING), ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);

    }

    // RIGHT ULTRASONIC SENSORs
    int rightStartingPointX = roverImageStartX + CHASSIS_X1 - (ULTRASONIC_PIE_WIDTH/2);
    int rightStartingPointY = frontStartingPointY;
    for (int i=3; i<=6; i++)
    {
        if (i<=4) usIndicator[i]->setGeometry(rightStartingPointX, rightStartingPointY + ((i-2)*ULTRASONIC_PIE_SIDE_SPACING), ULTRASONIC_PIE_WIDTH,ULTRASONIC_PIE_HEIGHT);
        else usIndicator[i]->setGeometry(rightStartingPointX, rightStartingPointY + ((i-1)*ULTRASONIC_PIE_SIDE_SPACING), ULTRASONIC_PIE_WIDTH,ULTRASONIC_PIE_HEIGHT);

    }

    usIndicator[14]->setGeometry(rightStartingPointX, rightStartingPointY, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    usIndicator[15]->setGeometry(leftStartingPointX, leftStartingPointY, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    usIndicator[16]->setGeometry(leftStartingPointX, rearStartingPointY, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);
    usIndicator[17]->setGeometry(rightStartingPointX, rearStartingPointY, ULTRASONIC_PIE_WIDTH, ULTRASONIC_PIE_HEIGHT);

    //usIndicator[0]->show();
    //int i;
    //for (i=0; i<=13; i++)    // Frontal Ultrasonic Sensor
    //{
      //  usIndicator[i]->show();
    //}
}

void UltrasonicDisplay::ultrasonicSensorStatusUpdate (int sensorID, int status)
{
    qDebug() << "ULTRASONIC" << sensorID << " [STATUS] > " << status;
    if(sensorID < SENSOR_QUANTITY) usIndicator[sensorID]->setStatus(status);
}
