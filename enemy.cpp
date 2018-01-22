#include "enemy.h"
#include <QTimer>
#include <ball.h>
Enemy::Enemy(){

    setPos(480,250);

    //connect
    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);


}

void Enemy::move()
{
   setPos(pos().x(),ball->pos().y());



}

