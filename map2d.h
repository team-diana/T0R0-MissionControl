#ifndef MAP2D_H
#define MAP2D_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QPen>

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

    void addNext(int x, int y);

    bool haveNext();
};

class Map2d : public QWidget
{
    Q_OBJECT
public:
    explicit Map2d(QWidget *parent = nullptr);

private:
    int X, x, Y, y;
    Serie *serie, *coda, *i;

    QPainter *painter;
    QPen pen;

protected:
    void paintEvent(QPaintEvent *e);

public slots:
    void addPoint(int x, int y);
};

#endif // MAP2D_H
