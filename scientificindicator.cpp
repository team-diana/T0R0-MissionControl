#include <QDebug>
#include "scientificindicator.h"
#include <QCoreApplication>

/**
    Cargo Bay Indicator
*/

CargoBayIndicator::CargoBayIndicator(QWidget *parent, int id) : QWidget(parent){
    this->id = id;
    this->humidity = 0;
    this->temperature = 0;
    this->weight = 0;
    this->status = 0;
}

void CargoBayIndicator::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, CARGO_BAY_INDICATOR_DISPLAY_WIDTH, CARGO_BAY_INDICATOR_DISPLAY_HEIGHT), QColor(10,10,10,255));

    painter.setPen(QColor(86,193,249));

    QString text;
    text.sprintf("CARGO_BAY#%d", this->id + 1);
    painter.drawText(1, 17, text);

    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, CARGO_BAY_INDICATOR_DISPLAY_WIDTH, CARGO_BAY_INDICATOR_DISPLAY_HEIGHT);

    QString ValueString;

    qDebug() << "TEMPERATURE " << this->temperature;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 20, 135, 20), Qt::AlignLeft, "TEMPERATURE");
    ValueString.sprintf("%5.3f", this->temperature);
    painter.drawText(QRect(110, 20, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "HUMIDITY " << this->humidity;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 35, 135, 20), Qt::AlignLeft, "HUMIDITY");
    ValueString.sprintf("%5.3f", this->humidity);
    painter.drawText(QRect(110, 35, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "WEIGHT " << this->weight;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 50, 135, 20), Qt::AlignLeft, "WEIGHT");
    ValueString.sprintf("%5.3f", this->weight);
    painter.drawText(QRect(110, 50, 220, 65), Qt::AlignLeft, ValueString);

    button = new QPushButton("OPEN", this);
    if(status == 0){
        button->setText("OPEN");
    } else {
        button->setText("CLOSE");
    }
    button->setGeometry(QRect(QPoint(10, 70), QSize(CARGO_BAY_INDICATOR_DISPLAY_WIDTH - 20, 30)));
    button->show();
    connect(button, SIGNAL (pressed()), this, SLOT (buttonPressed()));
}

void CargoBayIndicator::buttonPressed(){
    qDebug() << "PRESSED_ " << id;
    if(status == 0){
        status = 1;
    } else {
        status = 0;
    }
    emit cargoBayButtonPressedEventUpdate(this->id, status);
}

void CargoBayIndicator::setHumidity(float _humidity){
    qDebug() << "humidity " << _humidity;
    this->humidity = _humidity;
    this->update();
}

void CargoBayIndicator::setTemperature(float _temperature){
    qDebug() << "temperature " << _temperature;
    this->temperature = _temperature;
    this->update();
}

void CargoBayIndicator::setWeight(float _weight){
    qDebug() << "weight " << _weight;
    this->weight = _weight;
    this->update();
}

/**
    Drill Indicator
*/

DrillIndicator::DrillIndicator(QWidget *parent, int id) : QWidget(parent){
    this->id = id;
    this->weight = 0;
}

void DrillIndicator::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, DRILL_INDICATOR_DISPLAY_WIDTH, DRILL_INDICATOR_DISPLAY_HEIGHT), QColor(10,10,10,255));

    painter.setPen(QColor(86,193,249));

    QString text;
    text.sprintf("DRILL#%d", this->id + 1);
    painter.drawText(1, 17, text);

    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, DRILL_INDICATOR_DISPLAY_WIDTH, DRILL_INDICATOR_DISPLAY_HEIGHT);

    QString ValueString;

    qDebug() << "WEIGHT " << this->weight;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 20, 135, 20), Qt::AlignLeft, "WEIGHT");
    ValueString.sprintf("%5.3f", this->weight);
    painter.drawText(QRect(80, 20, 220, 65), Qt::AlignLeft, ValueString);
}


void DrillIndicator::setWeight(float _weight){
    qDebug() << "weight " << _weight;
    this->weight = _weight;
    this->update();
}

/**
    Proximity Sensor Indicator
*/

ProximitySensorIndicator::ProximitySensorIndicator(QWidget *parent) : QWidget(parent){
    this->armSensor = 0;
    this->turretSensor = 0;
    this->endEffector = 0;
}

void ProximitySensorIndicator::setArmSensor(float _armSensor){
    qDebug() << "armSensor " << _armSensor;
    this->armSensor = _armSensor;
    this->update();
}

void ProximitySensorIndicator::setTurretSensor(float _turretSensor){
    qDebug() << "turretSensor " << _turretSensor;
    this->turretSensor = _turretSensor;
    this->update();
}

void ProximitySensorIndicator::setEndEffectorSensor(float _endEffectorSensor){
    qDebug() << "endEffectorSensor " << _endEffectorSensor;
    this->endEffector = _endEffectorSensor;
    this->update();
}

void ProximitySensorIndicator::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, PROXIMITY_SENSOR_INDICATOR_DISPLAY_WIDTH, PROXIMITY_SENSOR_INDICATOR_DISPLAY_HEIGHT), QColor(10,10,10,255));

    painter.setPen(QColor(86,193,249));

    QString text;
    text.sprintf("PROXIMITY SENSOR");
    painter.drawText(1, 17, text);

    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, PROXIMITY_SENSOR_INDICATOR_DISPLAY_WIDTH, PROXIMITY_SENSOR_INDICATOR_DISPLAY_HEIGHT);

    QString ValueString;

    qDebug() << "ARM_SENSOR " << this->armSensor;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 20, 135, 20), Qt::AlignLeft, "ARM SENSOR");
    ValueString.sprintf("%5.3f", this->armSensor);
    painter.drawText(QRect(140, 20, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "TURRET_SENSOR " << this->turretSensor;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 35, 135, 20), Qt::AlignLeft, "TURRET SENSOR");
    ValueString.sprintf("%5.3f", this->turretSensor);
    painter.drawText(QRect(140, 35, 220, 65), Qt::AlignLeft, ValueString);    


    ValueString.begin();
    qDebug() << "ENDEFFECTOR_SENSOR " << this->endEffector;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 50, 135, 20), Qt::AlignLeft, "END EFFECTOR");
    ValueString.sprintf("%5.3f", this->endEffector);
    painter.drawText(QRect(140, 50, 220, 65), Qt::AlignLeft, ValueString);
}
