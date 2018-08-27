#ifndef ULTRASONICDISPLAY_H
#define ULTRASONICDISPLAY_H

#include <QWidget>
#include "ultrasonicsensorindicator.h"

class UltrasonicDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit UltrasonicDisplay(QWidget *parent = nullptr);

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    UltrasonicSensorIndicator *usIndicator;
};

#endif // ULTRASONICDISPLAY_H
