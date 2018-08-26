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

signals:
    void mqttBatteryEvent (QString topic, QString message);

public slots:

private:
    QMqttClient *m_client;
};

#endif // MQTTHARBINGER_H
