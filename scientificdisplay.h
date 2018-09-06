#ifndef SCIENTIFICDISPLAY_H
#define SCIENTIFICDISPLAY_H

#include <QWidget>
#include <QPainter>
#include "scientificindicator.h"

#define SCIENTIFIC_DISPLAY_POSX 58
#define SCIENTIFIC_DISPLAY_POSY 500
#define SCIENTIFIC_DISPLAY_WIDTH 500
#define SCIENTIFIC_DISPLAY_HEIGHT 300

class ScientificDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit ScientificDisplay(QWidget *parent = nullptr);

public slots:

    void cargoBayWeightUpdate(int ID, float weight);
    void cargoBayHumidityUpdate(int ID, float humidity);
    void cargoBayTemperatureUpdate(int ID, float temperature);
    void drillWeightUpdate(int ID, float weight);
    void proximityArmSensorUpdate(float armSenqsorValue);
    void proximityTurretSensorUpdate(float turretSensorValue);

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    CargoBayIndicator *cargoInd[3];
    DrillIndicator *drillInd[2];
    ProximitySensorIndicator *proxInd;
};

#endif // SCIENTIFICDISPLAY_H
