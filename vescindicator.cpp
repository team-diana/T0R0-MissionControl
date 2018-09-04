#include "vescindicator.h"
#include <QDebug>

vescIndicator::vescIndicator(QWidget *parent, int id) : QWidget(parent){
    this->id = id;
    this->current_input = 0;
    this->current_motor = 0;
    this->erpm = 0;
    this->temperature_mos1 = 0;
    this->voltage_input = 0;
    this->temperature_motor = 0;
}
//branch scientific
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
}

void vescIndicator::setErpm(float _erpm){
    qDebug() << "erpm" << _erpm;
    this->erpm = _erpm;
    this->update();
}
void vescIndicator::setCurrent_motor(float _current_motor){
    qDebug() << "current_motor" << _current_motor;
    this->current_motor = _current_motor;
    this->update();
}
void vescIndicator::setCurrent_input(float _current_input){
    qDebug() << "current_input" << _current_input;
    this->current_input = _current_input;
    this->update();
}
void vescIndicator::setVoltage_input(float _voltage_input){
    qDebug() << "voltage_input" << _voltage_input;
    this->voltage_input = _voltage_input;
    this->update();
}
void vescIndicator::setTemperature_mos1(float _temperature_mos1){
    qDebug() << "temperature_mos1" << _temperature_mos1;
    this->temperature_mos1 = _temperature_mos1;
    this->update();
}
void vescIndicator::setTemperature_motor(float _temperature_motor){
    qDebug() << "temperature_motor" << _temperature_motor;
    this->temperature_motor = _temperature_motor;
    this->update();
}
