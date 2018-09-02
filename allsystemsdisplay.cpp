#include "allsystemsdisplay.h"


AllSysDisplay::AllSysDisplay(QWidget *parent) : QWidget(parent)
{

}



void AllSysDisplay::paintEvent(QPaintEvent *)
{

	QPainter painter(this);

	QLinearGradient m_gradient(0,0,0,ALLSYS_DISPLAY_HEIGHT);

	m_gradient.setColorAt(0.0, QColor(10, 10, 10, 255));
	m_gradient.setColorAt(1.0, QColor(10, 10, 10, 255));
	painter.fillRect(QRect(0, 0, ALLSYS_DISPLAY_WIDTH, ALLSYS_DISPLAY_HEIGHT), m_gradient);

	painter.setPen(QColor(252, 252, 255, 255));
	painter.drawText(QRect(1, 1, ALLSYS_DISPLAY_WIDTH-1, 17), Qt::AlignCenter, "All Systems");

	painter.setPen(QColor(45, 229, 171, 255));
	painter.drawText(QRect(1, 20, ALLSYS_DISPLAY_WIDTH-1, 17), Qt::AlignCenter, "NOMINAL");

	QPen borderpen(QColor(45, 229, 171, 255));
	borderpen.setWidth(3);
	painter.setPen(borderpen);
	painter.setBrush(QColor(0,0,0,0));
	painter.drawRect(0, 0, ALLSYS_DISPLAY_WIDTH, ALLSYS_DISPLAY_HEIGHT);

	communication = new SysIndicator(this, "COM");
    communication->setGeometry(10, 49, SYS_INDICATOR_WIDTH+2, SYS_INDICATOR_HEIGHT+2);
	communication->show();

	batteries = new SysIndicator(this, "Batteries");
    batteries->setGeometry(115, 49, SYS_INDICATOR_WIDTH+2, SYS_INDICATOR_HEIGHT+2);
	batteries->show();

    motors = new SysIndicator(this, "Mobility");
    motors->setGeometry(220, 49, SYS_INDICATOR_WIDTH+2, SYS_INDICATOR_HEIGHT+2);
	motors->show();

	arm = new SysIndicator(this, "Arm");
    arm->setGeometry(325, 49, SYS_INDICATOR_WIDTH+2, SYS_INDICATOR_HEIGHT+2);
	arm->show();


}
