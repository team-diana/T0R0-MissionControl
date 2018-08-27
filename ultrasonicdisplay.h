#ifndef ULTRASONICDISPLAY_H
#define ULTRASONICDISPLAY_H

#include <QWidget>
#include "ultrasonicsensorindicator.h"

class UltrasonicDisplay : public QWidget
{
public:
    UltrasonicDisplay(QWidget *parent = nullptr);

private:
    UltrasonicSensorIndicator *usIndicator;

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // ULTRASONICDISPLAY_H
