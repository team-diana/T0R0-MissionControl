#ifndef ULTRASONICSENSORINDICATOR_H
#define ULTRASONICSENSORINDICATOR_H

#include <QWidget>
#include <QPainter>
#include <QFont>

#define ULTRASONIC_PIE_WIDTH 450    // Probably modifiyng this value will make glitches # ISSUE
#define ULTRASONIC_PIE_HEIGHT 450  // Probably modifiyng this value will make glitches  # ISSUE

class UltrasonicSensorIndicator : public QWidget
{
    Q_OBJECT

public:
    explicit  UltrasonicSensorIndicator(QWidget *parent = nullptr, int _direction = 1, bool _oblique = 0);
    void setStatus(int _status);
    //void setDirection( int direction);
    //void setOblique(bool oblique);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int direction;
    bool oblique;
    int status;
    float percentage;
};

#endif // ULTRASONICSENSORINDICATOR_H
