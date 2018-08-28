#ifndef ULTRASONICDISPLAY_H
#define ULTRASONICDISPLAY_H

#include <QWidget>
#include "ultrasonicsensorindicator.h"

#define ULTRASONIC_WIDTH 600
#define ULTRASONIC_HEIGHT 750

class UltrasonicDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit UltrasonicDisplay(QWidget *parent = nullptr);

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    UltrasonicSensorIndicator *usIndicator[18];
};

#endif // ULTRASONICDISPLAY_H
