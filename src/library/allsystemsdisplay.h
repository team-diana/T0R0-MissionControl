#ifndef ALLSYSDISPLAY_H
#define ALLSYSDISPLAY_H

#include <QWidget>
#include <QPainter>
#include "systemindicator.h"

#define ALLSYS_DISPLAY_POSX 1500
#define ALLSYS_DISPLAY_POSY 15
#define ALLSYS_DISPLAY_WIDTH 650
#define ALLSYS_DISPLAY_HEIGHT 150

class AllSysDisplay : public QWidget
{
		Q_OBJECT
	public:
    explicit AllSysDisplay(QWidget *parent = 0);
	signals:

	public slots:

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
	SysIndicator *communication, *batteries, *motors, *arm;
};

#endif // ALLSYSDISPLAY_H
