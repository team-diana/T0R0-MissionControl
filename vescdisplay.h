#ifndef VESCDISPLAY_H
#define VESCDISPLAY_H

#include <QWidget>
#include "vescindicator.h"


#define VESC_DISPLAY_POSX 58
#define VESC_DISPLAY_POSY 80
#define VESC_DISPLAY_WIDTH 350
#define VESC_DISPLAY_HEIGHT 400

class VescDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit VescDisplay(QWidget *parent = nullptr);

public slots:

    void vescErpmUpdate (int vescID, float erpm);
    void vescCurrent_motorUpdate (int vescID, float current_motor);
    void vescCurrent_inputUpdate (int vescID, float current_input);
    void vescVoltage_inputUpdate (int vescID, float voltage_input);
    void vescTemperature_mos1Update (int vescID, float temperature_mos1);
    void vescTemperature_motorUpdate (int vescID, float temperature_motor);

protected:
    void paintEvent (QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    vescIndicator *vesc[4];
};
#endif // VESCDISPLAY_H

