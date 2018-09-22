#ifndef SCIENTIFICINDICATOR_H
#define SCIENTIFICINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>
#include <QPushButton>

#define CARGO_BAY_INDICATOR_DISPLAY_WIDTH 150
#define CARGO_BAY_INDICATOR_DISPLAY_HEIGHT 110
#define DRILL_INDICATOR_DISPLAY_WIDTH 130
#define DRILL_INDICATOR_DISPLAY_HEIGHT 80
#define PROXIMITY_SENSOR_INDICATOR_DISPLAY_WIDTH 200
#define PROXIMITY_SENSOR_INDICATOR_DISPLAY_HEIGHT 80

class CargoBayIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  CargoBayIndicator(QWidget *parent = nullptr, int id = -1);
    void setWeight(float _weight);
    void setHumidity(float _humidity);
    void setTemperature(float _temperature);
    QPushButton *button;

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

public slots:
    void buttonPressed();

signals:
    void cargoBayButtonPressedEventUpdate (int id, int value);

private:
    int id;
    float weight;
    float humidity;
    float temperature;
    int status;

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
    void setEndEffectorSensor(float _endEffectorSensor);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    float armSensor;
    float turretSensor;
    float endEffector;
};

#endif // SCIENTIFICINDICATOR_H
