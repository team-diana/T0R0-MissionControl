#ifndef MAP2D_H
#define MAP2D_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QAbstractButton>
#include <QPixmap>

#define MAP2D_POSX 1500
#define MAP2D_POSY 700
#define MAP2D_HEIGTH 350
#define MAP2D_WIDTH 350

class Serie{
private:
    int x, y;
    Serie *next;
    bool nextFlag;

public:
    Serie(int x, int y);

    int getX();
    int getY();
    Serie* getNext();

    void setX(int x);
    void setY(int y);
    void addNext(int x, int y);

    bool haveNext();
};

class Map2d : public QAbstractButton
{
    Q_OBJECT
public:
    explicit Map2d(QWidget *parent = nullptr);
    void setGeometry(int a, int b, int c, int d);

private:

  //  Serie *route, *tailRoute, *i, *obstacles = 0, *obstaclesTail;

    QPainter *painter;
    QPen pen;
    QPixmap *image;

    int  flagZoom = 1, x, y;
    float rx = 1, ry = 1;

    /*
     * rx, ry -> rapporto tra dimensioni della finestra e 350
     *           (350x350 map ideal dimension, 150m of movement, 15m of margin)
     *
     * x,y -> last rover position
     *
     */


    void buildGrid();

protected:
    void paintEvent(QPaintEvent *e);

public slots:
    void addPoint(int x, int y);
    void ultrasonicSensorObstacle(int id, int v);
    void mousePress();
};

#endif // MAP2D_H
