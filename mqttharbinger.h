#ifndef MQTTHARBINGER_H
#define MQTTHARBINGER_H

#include <QWidget>
#include <QtCore/QDateTime>
#include <QMqttClient>

class MqttHarbinger : public QWidget
{
    Q_OBJECT

public:
    explicit MqttHarbinger(QWidget *parent = nullptr);
    void testMqtt();
    void batterySubscription();
    void ultrasonicSensorSubscription();
    void vescSubscription();
    void scientificSubscription();

    QMqttClient *m_client;

signals:

    void batteryChargeEvent (int idCell, int value);
    void batteryTemperatureEvent (int idCell, float value);
    void batteryVoltageEvent (int idCell, float value);
    void batteryCurrentEvent (int idCell, float value);
    void ultrasonicSensorStatusEvent (int sensorID, int status);
    void vescErpmEvent (int vescID, float erpm);
    void vescCurrent_motorEvent (int vescID, float current_motor);
    void vescCurrent_inputEvent (int vescID, float current_input);
    void vescVoltage_inputEvent (int vescID, float voltage_input);
    void vescTemperature_mos1Event (int vescID, float temperature_mos1);
    void vescTemperature_motorEvent (int vescID, float temperature_motor);
    void scientific_cargoBayTemperatureEvent (int ID, float temperature);
    void scientific_cargoBayHumidityEvent (int ID, float temperature);
    void scientific_cargoBayWeightEvent (int ID, float weight);
    void scientific_drillWeightEvent (int ID, float weight);
    void scientific_proximityArmSensorEvent (float value);
    void scientific_proximityTurretSensorEvent (float value);

public slots:

private:

};

#endif // MQTTHARBINGER_H
