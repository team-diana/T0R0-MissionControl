#include "ultrasonicdisplay.h"
#include <QLabel>

#define ROVIMG_WIDTH 230
#define ROVIMG_HEIGHT 374

UltrasonicDisplay::UltrasonicDisplay(QWidget *parent) : QWidget(parent)
{
    usIndicator = new UltrasonicSensorIndicator (this);
    usIndicator->setGeometry(500, 900, 100, 100);
    //battIndicator->setCharge(charge);
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
    pixlabel->setGeometry( (this->width() / 2) - (ROVIMG_WIDTH/2) , (this->height() / 2) - (ROVIMG_HEIGHT/2), ROVIMG_WIDTH, ROVIMG_HEIGHT );
    pixlabel->show();
    //pixlabel->setGeometry( (this->width() - ROVIMG_WIDTH) /2, (this->height() - ROVIMG_HEIGHT) /2, ROVIMG_WIDTH, ROVIMG_HEIGHT );

}
