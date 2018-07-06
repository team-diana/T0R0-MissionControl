#include "rovershow.h"

RoverShow::RoverShow(QWidget *parent) : QWidget(parent)
{
    left_free = true;
    right_free = true;
    front_free = true;
    back_free = true;
}

void RoverShow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //painter.drawImage(0,0, "/home/francesco/catkin_ws/src/t0r0_driving_gui/src/Rover_up.01_resized.png");


    //QLabel *pixlabel = new QLabel(this);
    //QPixmap mypix(":/img/rover_up-357x580.png");
    //QPixmap mypix(":/img/rover_up-357x580.png");
    //painter.drawPixmap(0,0,600,600, mypix);
    //ui->label->setPixmap(mypix);
    //pixlabel->setPixmap("/home/francesco/catkin_ws/src/t0r0_driving_gui/Images/rover_up-357x580.png");
    //pixlabel->show();

    /*
    // Draw rover box
    painter.setPen(QColor(100, 100, 100));
    painter.setBrush(QColor(100, 100, 100));
    painter.drawRect(this->width() / 2 - 150, this->height() / 2 - 200, 300, 400);
    painter.setBrush(QColor(100, 100, 100));
    painter.drawRect(this->width() / 2 - 146, this->height() / 2 - 196, 292, 392);

    // Draw right obstacle gradient
    painter.setPen(Qt::NoPen);
    QLinearGradient grad(QPointF(this->width() / 2 + 150, this->height() / 2), QPointF(this->width() / 2 + 170, this->height() / 2));
    if(right_free)
        grad.setColorAt(0, QColor(100, 200, 100));
    else
        grad.setColorAt(0, QColor(200, 100, 100));
    grad.setColorAt(1, QColor(0, 0, 0));
    painter.setBrush(grad);
    painter.drawRect(this->width() / 2 + 151, this->height() / 2 - 200, 20, 401);

    // Draw left obstacle gradient
    grad = QLinearGradient(QPointF(this->width() / 2 - 150, this->height() / 2), QPointF(this->width() / 2 - 170, this->height() / 2));
    if(left_free)
        grad.setColorAt(0, QColor(100, 200, 100));
    else
        grad.setColorAt(0, QColor(200, 100, 100));
    grad.setColorAt(1, QColor(0, 0, 0));
    painter.setBrush(grad);
    painter.drawRect(this->width() / 2 - 170, this->height() / 2 - 200, 20, 401);

    // Draw front obstacle gradient
    grad = QLinearGradient(QPointF(this->width() / 2, this->height() / 2 - 220), QPointF(this->width() / 2, this->height() / 2 - 200));
    if(front_free)
        grad.setColorAt(1, QColor(100, 200, 100));
    else
        grad.setColorAt(1, QColor(200, 100, 100));
    grad.setColorAt(0, QColor(0, 0, 0));
    painter.setBrush(grad);
    painter.drawRect(this->width() / 2 - 150, this->height() / 2 - 220, 300, 20);

    // Draw back obstacle gradient
    grad = QLinearGradient(QPointF(this->width() / 2, this->height() / 2 + 200), QPointF(this->width() / 2, this->height() / 2 + 220));
    if(back_free)
        grad.setColorAt(0, QColor(100, 200, 100));
    else
        grad.setColorAt(0, QColor(200, 100, 100));
    grad.setColorAt(1, QColor(0, 0, 0));
    painter.setBrush(grad);
    painter.drawRect(this->width() / 2 - 150, this->height() / 2 + 201, 300, 20);
    */
}

void RoverShow::signalRightObstacle(bool obstacle)
{
    right_free = !obstacle;
    this->update();
}

void RoverShow::signalLeftObstacle(bool obstacle)
{
    left_free = !obstacle;
    this->update();
}

void RoverShow::signalFrontObstacle(bool obstacle)
{
    front_free = !obstacle;
    this->update();
}

void RoverShow::signalBackObstacle(bool obstacle)
{
    back_free = !obstacle;
    this->update();
}
