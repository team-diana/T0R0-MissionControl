#include "statusdisplay.h"

StatusDisplay::StatusDisplay(QWidget *parent) : QWidget(parent)
{

}

void StatusDisplay::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.fillRect(QRect(0, 0, STATUS_DISPLAY_WIDTH, STATUS_DISPLAY_HEIGHT), QColor(10,10,10,255));

	painter.setPen(QColor(86,193,249));		// Blue vivace
	//painter.setPen(QColor(231,176,64));		// Orange
	//painter.setPen(QColor(186,56,51));		// Red
	//painter.setPen(QColor(109,123,192));		// Purple
	//painter.setPen(QColor(255,255,255));		// White
	painter.drawText(1, 17, "Rover Status");

	painter.setBrush(QColor(0,0,0,0));
	painter.drawRect(0, 0, STATUS_DISPLAY_WIDTH, STATUS_DISPLAY_HEIGHT);

}
