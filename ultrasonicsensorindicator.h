#ifndef ULTRASONICSENSORINDICATOR_H
#define ULTRASONICSENSORINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>

class UltrasonicSensorIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  UltrasonicSensorIndicator(QWidget *parent = nullptr, int _direction = 1);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int direction;

};

#endif // ULTRASONICSENSORINDICATOR_H
