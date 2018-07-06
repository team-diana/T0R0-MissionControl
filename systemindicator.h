#ifndef SYSINDICATOR_H
#define SYSINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QString>

#define SYS_INDICATOR_WIDTH 100
#define SYS_INDICATOR_HEIGHT 35

class SysIndicator : public QWidget
{
		Q_OBJECT
	public:
    explicit SysIndicator(QWidget *parent = 0, QString _title = "Generic");
	signals:

	public slots:

protected:
	void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
private:
	QString title;
};

#endif // SYSINDICATOR_H
