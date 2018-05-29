#include "autosysdisplay.h"


AutoSysDisplay::AutoSysDisplay(QWidget *parent) : QWidget(parent)
{

}



void AutoSysDisplay::paintEvent(QPaintEvent *)
{

	QPainter painter(this);

	QLinearGradient m_gradient(0,0,0,AUTOSYS_DISPLAY_HEIGHT);

	m_gradient.setColorAt(0.0, QColor(10, 10, 10, 255));
	m_gradient.setColorAt(1.0, QColor(10, 10, 10, 255));
	painter.fillRect(QRect(0, 0, AUTOSYS_DISPLAY_WIDTH, AUTOSYS_DISPLAY_HEIGHT), m_gradient);

	painter.setPen(QColor(112, 115, 194, 255));
	painter.drawText(1, 17, "Autonomous System");

	painter.setBrush(QColor(0,0,0,0));
	painter.drawRect(0, 0, AUTOSYS_DISPLAY_WIDTH, AUTOSYS_DISPLAY_HEIGHT);
}
