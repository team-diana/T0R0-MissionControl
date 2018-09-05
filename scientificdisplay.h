#ifndef SCIENTIFICDISPLAY_H
#define SCIENTIFICDISPLAY_H

#include <QWidget>
#include <QPainter>
#include "scientificindicator.h"

#define SCIENTIFIC_DISPLAY_POSX 58
#define SCIENTIFIC_DISPLAY_POSY 300
#define SCIENTIFIC_DISPLAY_WIDTH 600
#define SCIENTIFIC_DISPLAY_HEIGHT 600

class scientificDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit scientificDisplay(QWidget *parent = nullptr);

public slots:

    void cargoBayWeightUpdate(int ID, float weight);
    void cargoBayHumidityUpdate(int ID, float humidity);
    void cargoBayTemperatureUpdate(int ID, float temperature);
    void drillWeightUpdate(int ID, float weight);
    void proximityArmSensorUpdate(float armSensorValue);
    void proximityTurretSensorUpdate(float turretSensorValue);

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    cargoBayIndicator *cargoInd[3];
    drillIndicator *drillInd[2];
    proximitySensorIndicator *proxInd;
};

#endif // SCIENTIFICDISPLAY_H
