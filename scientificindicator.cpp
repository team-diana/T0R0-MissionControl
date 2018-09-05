#include <QDebug>
#include "scientificindicator.h"

/**
    Carbo Bay Indicator
*/

CargoBayIndicator::CargoBayIndicator(QWidget *parent, int id) : QWidget(parent){
    this->id = id;
    this->humidity = 0;
    this->temperature = 0;
    this->weight = 0;
}

void CargoBayIndicator::paintEvent(QPaintEvent *event){

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

void ProximitySensorIndicator::paintEvent(QPaintEvent *event){

}

/*
void vescIndicator::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, VESC_INDICATOR_DISPLAY_WIDTH, VESC_INDICATOR_DISPLAY_HEIGHT), QColor(10,10,10,255));

    painter.setPen(QColor(86,193,249));		// Blue vivace
    //painter.setPen(QColor(231,176,64));		// Orange
    //painter.setPen(QColor(186,56,51));		// Red
    //painter.setPen(QColor(109,123,192));		// Purple
    //painter.setPen(QColor(255,255,255));		// White
    QString text;
    text.sprintf("VESC %d - ", this->id+1);
    text.append(vescPos[this->id]);
    painter.drawText(1, 17, text);

    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, VESC_INDICATOR_DISPLAY_WIDTH, VESC_INDICATOR_DISPLAY_HEIGHT);

    QString ValueString;

    qDebug() << "ERPM " << this->erpm;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 20, 135, 20), Qt::AlignLeft, "ERPM");
    ValueString.sprintf("%5.3f", this->erpm);
    painter.drawText(QRect(135, 20, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "CURRENT_MOTOR " << this->current_motor;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 40, 135, 20), Qt::AlignLeft, "MOTOR CURRENT");
    ValueString.sprintf("%5.3f", this->current_motor);
    painter.drawText(QRect(135, 40, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "CURRENT_INPUT " << this->current_input;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(2, 60, 220, 65), Qt::AlignLeft, "INPUT CURRENT");
    ValueString.sprintf("%5.3f", this->current_input);
    painter.drawText(QRect(135, 60, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "VOLTAGE_INPUT " << this->voltage_input;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(190, 20, 220, 65), Qt::AlignLeft, "INPUT VOLTAGE");
    ValueString.sprintf("%5.3f", this->voltage_input);
    painter.drawText(QRect(325, 20, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "TEMPERATURE_MOS1 " << this->temperature_mos1;
    painter.setPen(QColor(222, 61, 25));
    painter.drawText(QRect(190, 40, 220, 65), Qt::AlignLeft, "MOS TEMP");
    ValueString.sprintf("%5.3f", this->temperature_mos1);
    painter.drawText(QRect(325, 40, 220, 65), Qt::AlignLeft, ValueString);

    ValueString.begin();
    qDebug() << "TEMPERATURE_MOTOR " << this->temperature_motor;
    painter.setPen(QColor(222, 61, 25));// 255,0,0,255));
    painter.drawText(QRect(190, 60, 220, 65), Qt::AlignLeft, "MOTOR TEMP");
    ValueString.sprintf("%5.3f", this->temperature_motor);
    painter.drawText(QRect(325, 60, 220, 65), Qt::AlignLeft, ValueString);
}*/
