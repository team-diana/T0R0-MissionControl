#include "map2d.h"
#include <QAbstractButton>
#include <unistd.h>
#include <QPixmap>
#include <QRect>

Serie::Serie(int x, int y){
    this->x = x;
    this->y = y;
    this->next = 0;
    this->nextFlag = false;
}

int Serie::getX(){
    return x;
}

void Serie::setX(int x){
    this->x = x;
}

int Serie::getY(){
    return y;
}

void Serie::setY(int y){
    this->y = y;
}

Serie* Serie::getNext(){
    return next;
}

void Serie::addNext(int x, int y){
    next = new Serie(x, y);
    nextFlag = true;
}

bool Serie::haveNext(){
    return nextFlag;
}

Map2d::Map2d(QWidget *parent) : QAbstractButton (parent)
{

    /*QPalette pal = QPalette();
    pal.setColor(QPalette::Background, QColor(14, 14, 14));
    this->setPalette(pal);
    this->setAutoFillBackground(true);*/

    pen.setWidth(1);

//    route = new Serie(0, 0);
//    tailRoute = route;

//    obstacles = new Serie(0, 0);
//    obstaclesTail = obstacles;

    painter = new QPainter();

    image = new QPixmap(350, 350);// dimensioni ideali
    x = image->width()/2;
    y = image->height()/2;
    image->fill(QColor(14, 14, 14));
    buildGrid();

    connect(this, &Map2d::clicked, this, &Map2d::mousePress);
}

void Map2d::buildGrid(){
    painter->begin(image);
    painter->setPen(pen);

    pen.setColor(Qt::gray);
    pen.setWidth(1);
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);

    painter->drawLine(image->width()/2 + rx*150/4, image->height()/2 - ry*150, image->width()/2 + rx*150/4, image->height()/2 + ry*150);
    painter->drawLine(image->width()/2 + rx*75, image->height()/2 - ry*150, image->width()/2 + rx*75, image->height()/2 + ry*150);
    painter->drawLine(image->width()/2 + rx*450/4, image->height()/2 - ry*150, image->width()/2 + rx*450/4, image->height()/2 + ry*150);

    painter->drawLine(image->width()/2 - rx*150/4, image->height()/2 - ry*150, image->width()/2 - rx*150/4, image->height()/2 + ry*150);
    painter->drawLine(image->width()/2 - rx*75, image->height()/2 - ry*150, image->width()/2 - rx*75, image->height()/2 + ry*150);
    painter->drawLine(image->width()/2 - rx*450/4, image->height()/2 - ry*150, image->width()/2 - rx*450/4, image->height()/2 + ry*150);

    painter->drawLine(image->width()/2 - rx*150, image->height()/2 - ry*150/4, image->width()/2 + rx*150, image->height()/2 - ry*150/4);
    painter->drawLine(image->width()/2 - rx*150, image->height()/2 - ry*75, image->width()/2 + rx*150, image->height()/2 - ry*75);
    painter->drawLine(image->width()/2 - rx*150, image->height()/2 - ry*450/4, image->width()/2 + rx*150, image->height()/2 - ry*450/4);

    painter->drawLine(image->width()/2 - rx*150, image->height()/2 + ry*150/4, image->width()/2 + rx*150, image->height()/2 + ry*150/4);
    painter->drawLine(image->width()/2 - rx*150, image->height()/2 + ry*75, image->width()/2 + rx*150, image->height()/2 + ry*75);
    painter->drawLine(image->width()/2 - rx*150, image->height()/2 + ry*450/4, image->width()/2 + rx*150, image->height()/2 + ry*450/4);

    pen.setColor(QColor(240, 169, 2, 255));
    pen.setWidth(2);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    painter->drawLine(image->width()/2, 0, image->width()/2, image->height());
    painter->drawLine(0, image->height()/2, image->width(), image->height()/2);

    painter->end();
}

void Map2d::paintEvent(QPaintEvent *e){
    painter->begin(this);
    painter->drawPixmap(QRect(0, 0, this->width(), this->height()), *image, QRect(0, 0, image->width(), image->height()));
    painter->end();
}

/*
 * Allow to double dimension on click
 * Use auto zoom, so image dimension change is not needed
 */
void Map2d::mousePress(){
    if(flagZoom == 2){
        this->QAbstractButton::setGeometry(MAP2D_POSX, MAP2D_POSY, this->width()/2, this->height()/2);// CABIARE 0, 50
        flagZoom = 1;
        pen.setWidth(2);
    } else {
        this->QAbstractButton::setGeometry(MAP2D_POSX - this->width(), MAP2D_POSY - this->height(), this->width()*2, this->height()*2);//CAMBIARE 0, 50
        flagZoom = 2;
        pen.setWidth(3);
    }

    //AGGIUNGERE LA POSSIBILITA DI INGRANDIRE IN VARIE DIREZIONI
    update();
}

void Map2d::addPoint(int x, int y){
//    tailRoute->addNext(x, y);
//    tailRoute = tailRoute->getNext();

    pen.setWidth(1);
    pen.setColor(Qt::red);
    pen.setStyle(Qt::SolidLine);

    painter->begin(image);
    painter->setPen(pen);

    painter->drawLine(this->x, this->y, image->width()/2 + x*rx, image->height()/2 + y*ry);
    this->x = image->width()/2 + x*rx;
    this->y = image->height()/2 + y*ry;

    painter->end();
    update();
}

void Map2d::ultrasonicSensorObstacle(int id, int v){
    pen.setWidth(1);
    pen.setColor(Qt::white);
    pen.setStyle(Qt::SolidLine);

    painter->begin(image);
    painter->setPen(pen);

    // each group sensor (front, left, rear and right) are ussumed as unique sensor
    // 1 pixel = 1 metre if image dimension is 350x350
    // rx, ry allow to mantein le proportion when dimension are not 350x350
    // obliqued ultrasonic senso not used
    switch (id) {
    //FRONT
    case 0:
    case 1:
    case 2:
        painter->drawPoint(x , y + ((int) v/25)*ry);
        break;
    //LEFT
    case 3:
    case 4:
    case 5:
    case 6:
        painter->drawPoint(x - ((int) v/25)*ry, y);
        break;
    //REAR
    case 7:
    case 8:
    case 9:
        painter->drawPoint(x , y - ((int) v/25)*ry);
        break;
    //BACK
    case 10:
    case 11:
    case 12:
    case 13:
        painter->drawPoint(x - ((int) v/25)*ry, y);
        break;

    }

    painter->end();
    update();
}

void Map2d::setGeometry(int a, int b, int c, int d){
    this->QAbstractButton::setGeometry(a, b, c, d);
    free(image);

    image = new QPixmap(this->width(), this->height());
    x = image->width()/2;
    y = image->height()/2;
    rx = image->width()/((float)350);
    ry = image->height()/((float)350);
    image->fill(QColor(14, 14, 14));
    buildGrid();

    //AGGIUNGERE STA PARTE SE LE DIMENSIONI CAMBIANO QUANDO HO GIA INZIATO A DISEGNARE
    //    painter->begin(this);
    //    pen.setColor(QColor(240, 169, 2, 255));
    //    painter->setPen(pen);

    //    painter->drawLine(0, this->height()/2, this->width(), this->height()/2);
    //    painter->drawLine(this->width()/2, 0, this->width()/2, this->height());

    //    pen.setColor(Qt::red);
    //    painter->setPen(pen);

    //    for(i = route; i->haveNext(); i=i->getNext()){
    //        painter->drawLine((this->width()/2 + flagZoom*i->getX()),
    //                          (this->height()/2 + flagZoom*i->getY()),
    //                          (this->width()/2 + flagZoom*i->getNext()->getX()),
    //                          (this->height()/2 + flagZoom*i->getNext()->getY()));
    //    }

    //    pen.setColor(Qt::white);

    //    for(i = obstacles; i->haveNext(); i=i->getNext()){
    //        painter->drawPoint((this->width()/2 + flagZoom*i->getX()),
    //                           (this->height()/2 + flagZoom*i->getY()));
    //    }

    //    painter->end();
}
