#ifndef RADIODISPLAY_H
#define RADIODISPLAY_H

#include <QWidget>
#include <QPainter>

#define RADIO_DISPLAY_POSX 1500
#define RADIO_DISPLAY_POSY 700
#define RADIO_DISPLAY_WIDTH 334
#define RADIO_DISPLAY_HEIGHT 285

class RadioDisplay : public QWidget
{
		Q_OBJECT
	public:
    explicit RadioDisplay(QWidget *parent = 0);
	signals:

	public slots:

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
};

#endif // RADIODISPLAY_H
