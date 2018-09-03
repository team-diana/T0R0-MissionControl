#ifndef VESCINDICATOR_H
#define VESCINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>

#define VESC_INDICATOR_DISPLAY_WIDTH 400
#define VESC_INDICATOR_DISPLAY_HEIGHT 80

//set the vesc position
const QString vescPos[] = {"FRONT LEFT", "REAR LEFT", "FRONT RIGHT", "REAR RIGHT"};

class vescIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  vescIndicator(QWidget *parent = nullptr, int id = -1);
    void setErpm(float _erpm);
    void setCurrent_motor(float _current_motor);
    void setCurrent_input(float _current_input);
    void setVoltage_input(float _voltage_input);
    void setTemperature_mos1(float _temperature_mos1);
    void setTemperature_motor(float _temperature_motor);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int id;
    float erpm;
    float current_motor;
    float current_input;
    float voltage_input;
    float temperature_mos1;
    float temperature_motor;
};

#endif // VESCINDICATOR_H
