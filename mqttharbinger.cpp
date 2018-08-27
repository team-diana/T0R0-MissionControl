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
    m_client->setHostname("194.116.126.73");
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

            // if (query.at(0) == "battery") emit mqttBatteryEvent (query.at(1).toInt(), query.at(2), message);
    });

}

void MqttHarbinger::testMqtt () {
    qDebug() << "MQTT CONNESSO";
    QString batterytopicstring ("diagnosys");
    auto subscription = m_client->subscribe(batterytopicstring);
    if (!subscription) {
        qDebug() << "Error: MQTT subscription";
    }

    batterySubscription();

    QString connectionMessage = "["
            + QDateTime::currentDateTime().toString()
            + "] Mission Control: Connesso al Broker MQTT";

    if (m_client->publish(batterytopicstring, connectionMessage.toUtf8()) == -1) qDebug() << "MQTT PUBLISH ERROR";
    else qDebug() << "MQTT PUBLISHED";
}

void MqttHarbinger::batterySubscription () {

    int i, j;
    QString batterytopicstring;
    QString argumentsArray[4] = {
        "charge",
        "voltage",
        "temperature",
        "current"
    };

    for (i=1; i<=5; i++)
    {
        for (j=0; j<4; j++)
        {
            batterytopicstring = "battery/"
                    + QString::number(i)
                    + "/"
                    + argumentsArray[j];

            auto subscription = m_client->subscribe(batterytopicstring);
            if (!subscription) {
                qDebug() << "ERROR: MQTT subscription on Topic[" << batterytopicstring << "]";
            } else qDebug() << "OK: MQTT: subscribed on Topic[" << batterytopicstring << "]";
        }
    }
}
