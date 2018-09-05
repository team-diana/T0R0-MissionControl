#ifndef SCIENTIFICINDICATOR_H
#define SCIENTIFICINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>

#define SCIENTIFIC_INDICATOR_DISPLAY_WIDTH 150
#define SCIENTIFIC_INDICATOR_DISPLAY_HEIGHT 80

class CargoBayIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  CargoBayIndicator(QWidget *parent = nullptr, int id = -1);
    void setWeight(float _weight);
    void setHumidity(float _humidity);
    void setTemperature(float _temperature);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int id;
    float weight;
    float humidity;
    float temperature;

};

class DrillIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  DrillIndicator(QWidget *parent = nullptr, int id = -1);
    void setWeight(float _weight);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int id;
    float weight;
};

class ProximitySensorIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  ProximitySensorIndicator(QWidget *parent = nullptr);
    void setArmSensor(float _armSensor);
    void setTurretSensor(float _turretSensor);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    float armSensor;
    float turretSensor;
};

#endif // SCIENTIFICINDICATOR_H
