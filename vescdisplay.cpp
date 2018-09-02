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
