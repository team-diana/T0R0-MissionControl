#ifndef ULTRASONICDISPLAY_H
#define ULTRASONICDISPLAY_H

#include <QWidget>
#include "ultrasonicsensorindicator.h"

#define ULTRASONIC_WIDTH 600
#define ULTRASONIC_HEIGHT 750
#define N_ULTRASSONIC_SENSORS 18

class UltrasonicDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit UltrasonicDisplay(QWidget *parent = nullptr);

public slots:

    //void ultrasonicSensorDirectionUpdate (int sensorID, int direction);
    //void ultrasonicSensorObliqueUpdate (int sensorID, bool oblique);
    void ultrasonicSensorStatusUpdate (int sensorID, int status);

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    UltrasonicSensorIndicator *usIndicator[N_ULTRASSONIC_SENSORS];
};

#endif // ULTRASONICDISPLAY_H
