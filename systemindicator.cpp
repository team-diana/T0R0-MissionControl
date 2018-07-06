#include "systemindicator.h"


SysIndicator::SysIndicator(QWidget *parent, QString _title) : QWidget(parent)
{
	title=_title;
}



void SysIndicator::paintEvent(QPaintEvent *)
{

	QPainter painter(this);

	//QLinearGradient m_gradient(0,0,0,SYS_INDICATOR_HEIGHT);

	//m_gradient.setColorAt(0.0, QColor(10, 10, 10, 255));
	//m_gradient.setColorAt(1.0, QColor(10, 10, 10, 255));
	//painter.fillRect(QRect(0, 0, SYS_INDICATOR_WIDTH, SYS_INDICATOR_HEIGHT), m_gradient);


	QPen borderpen(QColor(255, 255, 255, 255));
	//borderpen.setWidth(3);
	painter.setPen(borderpen);
	//painter.setBrush(QColor(255, 255, 255, 255), Qt::BDiagPattern);
	//painter.setBrush(Qt::BDiagPattern);
	painter.setPen(QColor(255, 255, 255, 0));
	QBrush good(QColor(45, 229, 171, 255), Qt::SolidPattern);
	painter.setBrush(good);
	painter.drawRect(0, 0, SYS_INDICATOR_WIDTH, SYS_INDICATOR_HEIGHT);



	painter.setBrush(QColor(0,0,0,255));
	painter.drawRect(5, 5, SYS_INDICATOR_WIDTH-10, SYS_INDICATOR_HEIGHT-10);
	painter.setPen(QColor(255, 255, 255, 255));
	painter.drawText(QRect(5, 5, SYS_INDICATOR_WIDTH-10, SYS_INDICATOR_HEIGHT-10), Qt::AlignCenter, title);

}
