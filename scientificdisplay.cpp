#include "scientificdisplay.h"
#include <QDebug>

ScientificDisplay::ScientificDisplay(QWidget *parent) : QWidget(parent) {
    int i;
    for(i=0; i<3; i++){
        cargoInd[i] = new CargoBayIndicator(this, i);
    }
    for(i=0; i<2; i++){
        drillInd[i] = new DrillIndicator(this, i);
    }
    proxInd = new ProximitySensorIndicator(this);
}

void ScientificDisplay::cargoBayWeightUpdate(int ID, float weight){
    qDebug() << "CARGO_BAY" << ID << " [WEIGHT] > " << weight;
    if(ID < 3) cargoInd[ID]->setWeight(weight);
}

void ScientificDisplay::cargoBayHumidityUpdate(int ID, float humidity){
    qDebug() << "CARGO_BAY" << ID << " [HUMIDITY] > " << humidity;
    if(ID < 3) cargoInd[ID]->setHumidity(humidity);
}

void ScientificDisplay::cargoBayTemperatureUpdate(int ID, float temperature){
    qDebug() << "CARGO_BAY" << ID << " [TEMPERATURE] > " << temperature;
    if(ID < 3) cargoInd[ID]->setTemperature(temperature);
}

void ScientificDisplay::drillWeightUpdate(int ID, float weight){
    qDebug() << "DRILL" << ID << " [WEIGHT] > " << weight;
    if(ID < 3) drillInd[ID]->setWeight(weight);
}

void ScientificDisplay::proximityArmSensorUpdate(float armSensorValue){
    qDebug() << "PROXIMITY_SENSOR" << " [ARM_SENSOR] > " << armSensorValue;
    proxInd->setArmSensor(armSensorValue);
}

void ScientificDisplay::proximityTurretSensorUpdate(float turretSensorValue){
    qDebug() << "PROXIMITY_SENSOR" << " [TURRET_SENSOR] > " << turretSensorValue;
    proxInd->setTurretSensor(turretSensorValue);
}

void ScientificDisplay::paintEvent (QPaintEvent *){
    QPainter painter(this);

    painter.setBrush(QColor(255,0,0,255));  // Initialize red color for debugging purpouses
    painter.setPen(QColor(255,0,0,255));   // Initialize red color for debugging purpouses

    painter.fillRect(QRect(0, 0, SCIENTIFIC_DISPLAY_WIDTH, SCIENTIFIC_DISPLAY_HEIGHT), QColor(10,10,10,255));

    painter.setPen(QColor(86,193,249));
    painter.drawText(3, 17, "SCIENTIFIC DATA");

    painter.setBrush(QColor(0,0,0,0));
    painter.drawRect(0, 0, SCIENTIFIC_DISPLAY_WIDTH, SCIENTIFIC_DISPLAY_HEIGHT);

    cargoInd[0]->setGeometry(10,40, CARGO_BAY_INDICATOR_DISPLAY_WIDTH+2, CARGO_BAY_INDICATOR_DISPLAY_HEIGHT+2);
    cargoInd[1]->setGeometry(170,40, CARGO_BAY_INDICATOR_DISPLAY_WIDTH+2, CARGO_BAY_INDICATOR_DISPLAY_HEIGHT+2);
    cargoInd[2]->setGeometry(330,40, CARGO_BAY_INDICATOR_DISPLAY_WIDTH+2, CARGO_BAY_INDICATOR_DISPLAY_HEIGHT+2);
    drillInd[0]->setGeometry(10,180,DRILL_INDICATOR_DISPLAY_WIDTH+2, DRILL_INDICATOR_DISPLAY_HEIGHT+2);
    drillInd[1]->setGeometry(360,180,DRILL_INDICATOR_DISPLAY_WIDTH+2, DRILL_INDICATOR_DISPLAY_HEIGHT+2);
    proxInd->setGeometry(150,180, PROXIMITY_SENSOR_INDICATOR_DISPLAY_WIDTH+2, PROXIMITY_SENSOR_INDICATOR_DISPLAY_HEIGHT+2);
}
