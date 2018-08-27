#ifndef ULTRASONICSENSORINDICATOR_H
#define ULTRASONICSENSORINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>

class UltrasonicSensorIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  UltrasonicSensorIndicator(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

};

#endif // ULTRASONICSENSORINDICATOR_H
