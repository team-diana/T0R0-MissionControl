#ifndef ODOMSDISPLAY_H
#define ODOMSDISPLAY_H

#include <QWidget>
#include <QPainter>
#include "colors.h"

#define ODOM_DISPLAY_POSX 1500
#define ODOM_DISPLAY_POSY 370
#define ODOM_DISPLAY_WIDTH 334
#define ODOM_DISPLAY_HEIGHT 285

class OdomDisplay : public QWidget
{
	Q_OBJECT
public:
    explicit OdomDisplay(QWidget *parent = nullptr);
	~OdomDisplay();

	signals:

	public slots:

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
};

#endif // ODOMSDISPLAY_H
