#ifndef STATUSDISPLAY_H
#define STATUSDISPLAY_H

#include <QWidget>
#include <QPainter>

#include "statusdisplay.h"

#define STATUS_DISPLAY_POSX 58
#define STATUS_DISPLAY_POSY 500
#define STATUS_DISPLAY_WIDTH 350
#define STATUS_DISPLAY_HEIGHT 400

class StatusDisplay : public QWidget
{
		Q_OBJECT
	public:
    explicit StatusDisplay(QWidget *parent = 0);
	signals:

	public slots:

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
};

#endif // STATUSDISPLAY_H
