#include "radiodisplay.h"


RadioDisplay::RadioDisplay(QWidget *parent) : QWidget(parent)
{

}



void RadioDisplay::paintEvent(QPaintEvent *)
{

	QPainter painter(this);

	QLinearGradient m_gradient(0,0,0,RADIO_DISPLAY_HEIGHT);

	m_gradient.setColorAt(0.0, QColor(10, 10, 10, 255));
	m_gradient.setColorAt(1.0, QColor(10, 10, 10, 255));
	painter.fillRect(QRect(0, 0, RADIO_DISPLAY_WIDTH, RADIO_DISPLAY_HEIGHT), m_gradient);

    painter.setPen(QColor(240, 169, 2, 255));
	painter.drawText(1, 17, "Communication");

	painter.setBrush(QColor(0,0,0,0));
	painter.drawRect(0, 0, RADIO_DISPLAY_WIDTH, RADIO_DISPLAY_HEIGHT);
}
