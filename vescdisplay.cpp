#include "vescdisplay.h"
#include <QLabel>
#include <QDebug>

VescDisplay::VescDisplay(QWidget *parent) : QWidget(parent){
    int i;
    for(i=0; i<4; i++){
        vesc[i] = new vescIndicator(this, i);
    }
}

void VescDisplay::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.fillRect(QRect(0, 0, VESC_DISPLAY_WIDTH, VESC_DISPLAY_HEIGHT), QColor(10,10,10,255));

    painter.setPen(QColor(86,193,249));		// Blue vivace
    //painter.setPen(QColor(231,176,64));		// Orange
    //painter.setPen(QColor(186,56,51));		// Red
    //painter.setPen(QColor(109,123,192));		// Purple
    //painter.setPen(QColor(255,255,255));		// White
    painter.drawText(1, 17, "VESC Status");

    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, VESC_DISPLAY_WIDTH, VESC_DISPLAY_HEIGHT);
    for(int i=0; i<4; i++){
        vesc[i]->setGeometry(20, i*90+30, VESC_INDICATOR_DISPLAY_WIDTH + 2, VESC_INDICATOR_DISPLAY_HEIGHT + 2);
    }
}

void VescDisplay::vescErpmUpdate (int vescID, float erpm){
    qDebug() << "VESC" << vescID << " [ERPM] > " << erpm;
    if(vescID < 4) vesc[vescID]->setErpm(erpm);
}
void VescDisplay::vescCurrent_motorUpdate (int vescID, float current_motor){
    qDebug() << "VESC" << vescID << " [current_motor] > " << current_motor;
    if(vescID < 4) vesc[vescID]->setCurrent_motor(current_motor);
}
void VescDisplay::vescCurrent_inputUpdate (int vescID, float current_input){
    qDebug() << "VESC" << vescID << " [current_input] > " << current_input;
    if(vescID < 4) vesc[vescID]->setCurrent_input(current_input);
}
void VescDisplay::vescVoltage_inputUpdate (int vescID, float voltage_input){
    qDebug() << "VESC" << vescID << " [voltage_input] > " << voltage_input;
    if(vescID < 4) vesc[vescID]->setVoltage_input(voltage_input);
}
void VescDisplay::vescTemperature_mos1Update (int vescID, float temperature_mos1){
    qDebug() << "VESC" << vescID << " [temperature_mos1] > " << temperature_mos1;
    if(vescID < 4) vesc[vescID]->setTemperature_mos1(temperature_mos1);
}
void VescDisplay::vescTemperature_motorUpdate (int vescID, float temperature_motor){
    qDebug() << "VESC" << vescID << " [temperature_motor] > " << temperature_motor;
    if(vescID < 4) vesc[vescID]->setTemperature_motor(temperature_motor);
}
