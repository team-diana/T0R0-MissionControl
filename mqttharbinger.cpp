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
    m_client->setHostname("192.168.1.164");
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
            if (query.at(0) == "battery") emit mqttBatteryEvent (query.at(1).toInt(), query.at(2), message);
    });

}

void MqttHarbinger::testMqtt () {
    qDebug() << "MQTT CONNESSO";
    QString batterytopicstring ("testtopic");
    auto subscription = m_client->subscribe(batterytopicstring);
    if (!subscription) {
        qDebug() << "Error: MQTT subscription";
    }

    batterySubscription();

    m_client->publish(batterytopicstring, batterytopicstring.toUtf8());
    if (m_client->publish(batterytopicstring, batterytopicstring.toUtf8()) == -1) qDebug() << "MQTT PUBLISH ERROR";
    else qDebug() << "MQTT PUBLISHED";
}

void MqttHarbinger::batterySubscription () {
    QString batterytopicstring ("battery/1/voltage");
    auto subscription = m_client->subscribe(batterytopicstring);
    if (!subscription) {
        qDebug() << "Error: MQTT subscription";
    } else qDebug() << "MQTT: battery subscribed";
}
