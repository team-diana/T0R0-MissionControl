#include "map2d.h"

Serie::Serie(int x, int y){
    this->x = x;
    this->y = y;
    this->next = 0;
    this->nextFlag = false;
}

int Serie::getX(){
    return x;
}

int Serie::getY(){
    return y;
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

Map2d::Map2d(QWidget *parent) : QWidget(parent)
{
    X = this->width()/2;
    Y = this->height()/2;

  //  QPalette pal = QPalette();
  //  pal.setColor(QPalette::Background, QColor(14, 14, 14));
  //  this->setPalette(pal);

    serie = new Serie(X, Y);
    coda = serie;
    painter = new QPainter();
}

void Map2d::paintEvent(QPaintEvent *e){
    painter->begin(this);
    pen.setColor(QColor(240, 169, 2, 255));
    painter->setPen(pen);

    painter->drawLine(0, this->height()/2, this->width(), this->height()/2);
    painter->drawLine(this->width()/2, 0, this->width()/2, this->height());

    pen.setColor(Qt::red);
    painter->setPen(pen);

    for(i = serie; i->haveNext(); i=i->getNext()){
        painter->drawLine(i->getX(), i->getY(), i->getNext()->getX(), i->getNext()->getY());
    }

    painter->end();
}

void Map2d::addPoint(int x, int y){
    coda->addNext(this->width()/2 + x,this->height()/2 + y);
    coda = coda->getNext();
    update();
}
