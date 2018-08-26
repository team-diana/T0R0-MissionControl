#include "mqttharbinger.h"
#include "config.h"
#include <QDebug>
#include <QtCore/QDateTime>
#include <QtWidgets/QMessageBox>

MqttHarbinger::MqttHarbinger(QWidget *parent) : QWidget(parent)
{
    const QMqttTopicName battopic (QString("testbat"));

    m_client = new QMqttClient(this);
    m_client->setHostname(MQTT_BROKER_IP);
    m_client->setPort(MQTT_BROKER_PORT);
    m_client->connectToHost();

    connect(m_client, &QMqttClient::connected, this, [](){
        qDebug() << "MQTT CONNESSO";
    });

    QString batterytopicstring ("testbat");
    auto subscription = m_client->subscribe(batterytopicstring);
    if (!subscription) {
            QMessageBox::critical(this, QLatin1String("Error"), QLatin1String("Could not subscribe. Is there a valid connection?"));
            return;
    }

    m_client->publish(batterytopicstring, batterytopicstring.toUtf8());
    if (m_client->publish(batterytopicstring, batterytopicstring.toUtf8()) == -1) qDebug() << "MQTT ERRORE PUBBLICAZIONE";
    else qDebug() << "MQTT PUBLISHED";

    //connect(sub.data(), &QMqttSubscription::messageReceived, [&](QMqttMessage msg) {
    //qDebug() << "New Message:" << msg.payload();
    //});


    /*
    auto subscription = m_client->subscribe(QString("testbat"));
        if (!subscription) {
            qDebug() << "Could not subscribe. Is there a valid connection?";
            return;
        }
*/

    connect(m_client, &QMqttClient::messageReceived, this, [this](const QByteArray &message, const QMqttTopicName &topic) {
            const QString content = QDateTime::currentDateTime().toString()
                        + QLatin1String(" Received Topic: ")
                        + topic.name()
                        + QLatin1String(" Message: ")
                        + message
                        + QLatin1Char('\n');
            qDebug() << content;

            if (topic.name() == "testbat") emit mqttBatteryEvent (topic.name(), message);
    });

}



