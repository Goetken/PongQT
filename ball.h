#ifndef BALL_H
#define BALL_H
//#include "enemy.h"
#include "myrect.h"
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <stdlib.h>
#include <stdio.h>

#include <time.h>


class Ball: public QObject, public QGraphicsRectItem{
  Q_OBJECT

public:
    Ball();
    int coefficient = 1;
    int speed;
    int angle;

    QRectF boundingRect() const override;
    void handleCollision();

    int randX = rand() % 10;
    int randY = rand() % 10 -10;




public slots:
    void move();

};




#endif // BALL_H
