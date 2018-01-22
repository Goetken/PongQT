#ifndef ENEMY_H
#define ENEMY_H

#include "myrect.h"
#include <QObject>
#include <QGraphicsRectItem>
#include <ball.h>

class Enemy: public QObject, public MyRect{
    Q_OBJECT
public:

    Enemy();
    bool moveUp = true;
    Ball *ball;
public slots:
    void move();
};

#endif // ENEMY_H
