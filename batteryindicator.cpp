#include "batteryindicator.h"
#include "colors.h"

BatteryIndicator::BatteryIndicator(QWidget *parent) : QWidget(parent)
{
    charge = -1;
    in_use = false;
}

void BatteryIndicator::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
	QFont font;
	// Draw background indicator
	painter.setRenderHint(QPainter::Antialiasing);

	QPainterPath path1;
	path1.addRoundedRect(QRectF(0, 0, BAT_WIDTH, BAT_HEIGHT), 10, 10);
	QPen pen(QColor(255,255,255,0), 1);
	painter.setPen(pen);
	painter.fillPath(path1, QColor(100, 100, 100));
	painter.drawPath(path1);

	QPainterPath path3;
	path3.addRoundedRect(QRectF(0.5, 0.5, BAT_WIDTH - 1, BAT_HEIGHT - 1), 10, 10);
	//pen.setBrush(QColor(255,255,255, 0), 1);
	painter.setPen(pen);
	painter.fillPath(path3, QColor(40, 40, 40));
	painter.drawPath(path3);

	painter.setBrush(QColor(45, 45, 45));
  //painter.drawRect(0, 0, BAT_WIDTH-1, BAT_HEIGHT-1);

  // Battery charge colors
  /*
	QColor fully(40, 246, 45);
  QColor good(113, 217, 45);
	QColor med(254, 202, 47);
  QColor low(200, 0, 0);
  */

  QColor fully = indicator_green;
  QColor good = indicator_green;
	QColor med = indicator_yellow;
  QColor low = indicator_red;


    // Draw battery charge
	QColor colorIndicator;
  if(charge > GOODCHARGE)
  {
    painter.setPen(fully);
    painter.setBrush(fully);
		colorIndicator = fully;
  }
  else if(charge > MEDCHARGE)
  {
    painter.setPen(good);
    painter.setBrush(good);
		colorIndicator = good;
  }
  else if(charge > LOWCHARGE)
  {
    painter.setPen(med);
    painter.setBrush(med);
		colorIndicator = med;
  }
  else
  {
    painter.setPen(low);
    painter.setBrush(low);
		colorIndicator = low;
  }

  int barPerc = charge * (BAT_WIDTH-1) / 100;
  //painter.drawRect(1, 1, barPerc, BAT_HEIGHT-1);

	// Draw Battery bar-graph
	QPainterPath path2;
	path2.addRoundedRect(QRectF(1, 1, barPerc, BAT_HEIGHT-2), 10, 10);
	//QPen pen(Qt::gray, 2);
	//painter.setPen(pen);
	painter.fillPath(path2, colorIndicator);
	painter.drawPath(path2);

	// Show Text Percentage of charge
  painter.setPen(QColor(255, 255, 255));
	painter.setBrush(QColor(0, 0, 0));

	int fontSize = BAT_HEIGHT-4;
	font.setPixelSize(fontSize);
	painter.setFont(font);

  int fontSizeCorrectionY =  -fontSize;
	QString percentageStr;
	percentageStr.sprintf("%3d%%", charge);
  painter.drawText(QRect(0, 0, BAT_WIDTH, BAT_HEIGHT), Qt::AlignCenter, percentageStr);
	//pen.setWidth(2);
	//pen.setColor(Qt::black);
	//painter.setPen(pen);
	//QPainterPath textPath;
	//textPath.addText(QRect(0, 0, BAT_WIDTH, BAT_HEIGHT), font, percentageStr)
}

void BatteryIndicator::setCharge(int charge)
{
  this->charge = charge;
  this->update();
}

void BatteryIndicator::setInUse(bool status)
{
  in_use = true;
  this->update();
}
