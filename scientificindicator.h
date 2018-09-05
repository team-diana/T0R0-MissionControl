#ifndef SCIENTIFICINDICATOR_H
#define SCIENTIFICINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>

#define SCIENTIFIC_INDICATOR_DISPLAY_WIDTH 150
#define SCIENTIFIC_INDICATOR_DISPLAY_HEIGHT 80

class cargoBayIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  cargoBayIndicator(QWidget *parent = nullptr, int id = -1);
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

class drillIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  drillIndicator(QWidget *parent = nullptr, int id = -1);
    void setWeight(float _weight);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int id;
    float weight;
};

class proximitySensorIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  proximitySensorIndicator(QWidget *parent = nullptr);
    void setArmSensor(float _armSensor);
    void setTurretSensor(float _turretSensor);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    float armSensor;
    float turretSensor;
};

#endif // SCIENTIFICINDICATOR_H
