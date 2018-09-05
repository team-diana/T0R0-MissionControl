#include "mqttharbinger.h"
#include "config.h"
#include <QDebug>
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>

#include <unistd.h>

MqttHarbinger::MqttHarbinger(QWidget *parent) : QWidget(parent)
{
    const QMqttTopicName battopic (QString("testbat"));

    m_client = new QMqttClient(this);
    m_client->setHostname(MQTT_BROKER_IP);
    m_client->setPort(MQTT_BROKER_PORT);
    m_client->connectToHost();

    usleep(2000);
    connect(m_client, &QMqttClient::connected, this, &MqttHarbinger::testMqtt);

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
            const QString content = QDateTime::currentDateTime().toString()
                        + QLatin1String(" Received Topic: ")
                        + topic.name()
                        + QLatin1String(" Message: ")
                        + message
                        + QLatin1Char('\n');
            qDebug() << content;

            QRegExp rx("(\\/|\\t)"); //RegEx for ' ' or ',' or '.' or ':' or '\t'
            QStringList query = topic.name().split(rx);
            qDebug() << query;

            if (query.at(0) == "battery")
            {
                if      (query.at(2) == "charge")       emit batteryChargeEvent(query.at(1).toInt(), message.toInt());
                else if (query.at(2) == "voltage")      emit batteryVoltageEvent(query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "temperature")  emit batteryTemperatureEvent(query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "current")      emit batteryCurrentEvent(query.at(1).toInt(), message.toFloat());
            }
            else if (query.at(0) == "ultrasonicSensor")
            {
                emit ultrasonicSensorStatusEvent(query.at(1).toInt(), message.toInt());
            }
            else if (query.at(0) == "vesc")
            {
                if      (query.at(2) == "erpm")                 emit vescErpmEvent (query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "current_motor")        emit vescCurrent_motorEvent (query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "current_input")        emit vescCurrent_inputEvent (query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "voltage_input")        emit vescVoltage_inputEvent (query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "temperature_mos1")     emit vescTemperature_mos1Event (query.at(1).toInt(), message.toFloat());
                else if (query.at(2) == "temperature_motor")    emit vescTemperature_motorEvent (query.at(1).toInt(), message.toFloat());
            }
            else if (query.at(0) == "scientific")
            {
                if(query.at(1) == "cargoBay")
                {
                    if(query.at(3) == "temperature")            emit scientific_cargoBayTemperatureEvent (query.at(2).toInt(), message.toFloat());
                    else if(query.at(3) == "humidity")          emit scientific_cargoBayHumidityEvent (query.at(2).toInt(), message.toFloat());
                    else if(query.at(3) == "weight")            emit scientific_cargoBayWeightEvent (query.at(2).toInt(), message.toFloat());
                }
                else if(query.at(1) == "drill")
                {
                    if(query.at(3) == "weight")                 emit scientific_drillWeightEvent (query.at(2).toInt(), message.toFloat());
                }
                else if(query.at(1) == "proximitySensor")
                {
                    if(query.at(2) == "armSensor" && query.at(3) == "weight")           emit scientific_proximityArmSensorEvent (message.toFloat());
                    else if(query.at(2) == "turretSensor" && query.at(3) == "weight")   emit scientific_proximityTurretSensorEvent (message.toFloat());
                }
            }

    });

}

void MqttHarbinger::testMqtt ()
{
    qDebug() << "MQTT CONNESSO";
    QString batterytopicstring ("diagnostics");
    auto subscription = m_client->subscribe(batterytopicstring);
    if (!subscription) {
        qDebug() << "Error: MQTT subscription";
    }

    batterySubscription();
    ultrasonicSensorSubscription();
    vescSubscription();

    QString connectionMessage = "["
            + QDateTime::currentDateTime().toString()
            + "] Mission Control: Connesso al Broker MQTT";

    if (m_client->publish(batterytopicstring, connectionMessage.toUtf8()) == -1) qDebug() << "MQTT PUBLISH ERROR";
    else qDebug() << "MQTT PUBLISHED";
}

void MqttHarbinger::ultrasonicSensorSubscription()
{
    QString topicString("ultrasonicSensor/#");
    m_client->subscribe(topicString);
}


void MqttHarbinger::vescSubscription(){
    QString topicString("vesc/#");
    m_client->subscribe(topicString);
}

void MqttHarbinger::batterySubscription ()
{
    QString topicString("battery/#");
    m_client->subscribe(topicString);
}

void MqttHarbinger::scientificSubscription(){
    QString topicString("scientific/#");
    m_client->subscribe(topicString);
}
