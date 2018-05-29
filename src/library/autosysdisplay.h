#ifndef AUTOSYSDISPLAY_H
#define AUTOSYSDISPLAY_H

#include <QWidget>
#include <QPainter>

#define AUTOSYS_DISPLAY_POSX 1500
#define AUTOSYS_DISPLAY_POSY 50
#define AUTOSYS_DISPLAY_WIDTH 334
#define AUTOSYS_DISPLAY_HEIGHT 285

class AutoSysDisplay : public QWidget
{
		Q_OBJECT
	public:
    explicit AutoSysDisplay(QWidget *parent = 0);
	signals:

	public slots:

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
};

#endif // AUTOSYSDISPLAY_H
