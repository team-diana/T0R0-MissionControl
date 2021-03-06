#include "odometrydisplay.h"
#include <QCoreApplication>
#include <QDebug>

/***
	Displays odometry information of the rover.
*/

OdomDisplay::OdomDisplay(QWidget *parent) : QWidget(parent)
{
    x=0, y=0, z=0, pitch=0, roll=0, yaw=0;
}

OdomDisplay::~OdomDisplay()
{

}

void OdomDisplay::paintEvent(QPaintEvent *)
{

	QPainter painter(this);

	QLinearGradient m_gradient(0,0,0,ODOM_DISPLAY_HEIGHT);

	m_gradient.setColorAt(0.0, QColor(10, 10, 10, 255));
	m_gradient.setColorAt(1.0, QColor(10, 10, 10, 255));
	painter.fillRect(QRect(0, 0, ODOM_DISPLAY_WIDTH, ODOM_DISPLAY_HEIGHT), m_gradient);

    QColor theme (205, 106, 255);
    painter.setPen(theme);
	painter.drawText(1, 17, "Odometry");

	painter.setBrush(QColor(0,0,0,0));
	painter.drawRect(0, 0, ODOM_DISPLAY_WIDTH, ODOM_DISPLAY_HEIGHT);

	QString ValueString;

	ValueString.begin();
    // qDebug() << "Odometry: X " << x;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(10, 35, 135, 20), Qt::AlignLeft, "X");
    ValueString.sprintf("%5.3f", x);
    painter.drawText(QRect(65, 35, 220, 65), Qt::AlignLeft, ValueString);

	ValueString.begin();
    // qDebug() << "Odometry: Y " << y;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(10, 55, 135, 20), Qt::AlignLeft, "Y");
    ValueString.sprintf("%5.3f", y);
    painter.drawText(QRect(65, 55, 220, 65), Qt::AlignLeft, ValueString);

	ValueString.begin();
    // qDebug() << "Odometry: Z " << z;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(10, 75, 135, 20), Qt::AlignLeft, "Z");
    ValueString.sprintf("%5.3f", z);
    painter.drawText(QRect(65, 75, 220, 65), Qt::AlignLeft, ValueString);

	ValueString.begin();
    // qDebug() << "Odometry: Pitch " << pitch;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(175, 35, 135, 20), Qt::AlignLeft, "Pitch");
    ValueString.sprintf("%5.3f", pitch);
    painter.drawText(QRect(250, 35, 220, 65), Qt::AlignLeft, ValueString);

	ValueString.begin();
    // qDebug() << "Odometry: Roll " << roll;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(175, 55, 135, 20), Qt::AlignLeft, "Roll");
    ValueString.sprintf("%5.3f", roll);
    painter.drawText(QRect(250, 55, 220, 65), Qt::AlignLeft, ValueString);

	ValueString.begin();
    // qDebug() << "Odometry: Yaw " << yaw;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(175, 75, 135, 20), Qt::AlignLeft, "Yaw");
    ValueString.sprintf("%5.3f", yaw);
    painter.drawText(QRect(250, 75, 220, 65), Qt::AlignLeft, ValueString);
}

void OdomDisplay::odometryUpdate(QString type, float value)
{
	if (type == "x") this->setX(value);
	else if (type == "y") this->setY(value);
	else if (type == "z") this->setZ(value);
	else if (type == "pitch") this->setPitch(value);
	else if (type == "roll") this->setRoll(value);
	else if (type == "yaw") this->setYaw(value);
}

void OdomDisplay::setX(float value)
{
    this->x = value;
	this->update();
}

void OdomDisplay::setY(float value)
{
    this->y = value;
	this->update();
}

void OdomDisplay::setZ(float value)
{
    this->z = value;
	this->update();
}

void OdomDisplay::setPitch(float value)
{
    this->pitch = value;
	this->update();
}

void OdomDisplay::setRoll(float value)
{
    this->roll = value;
	this->update();
}

void OdomDisplay::setYaw(float value)
{
    this->yaw = value;
	this->update();
}
