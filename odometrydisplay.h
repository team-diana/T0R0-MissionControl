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

	void setX(float value);
	void setY(float value);
	void setZ(float value);
	void setPitch(float value);
	void setRoll(float value);
	void setYaw(float value);

signals:

public slots:
    void odometryUpdate (QString, float value);

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
    float x, y, z, pitch, roll, yaw;
};

#endif // ODOMSDISPLAY_H
