#include "ball.h"
#include <QTimer>
#include "enemy.h"
#include "myrect.h"
#include <QList>
#include <QDebug>
#include <cstdlib>
#include <time.h>
#include <QGraphicsView>
#include <QPoint>

Ball::Ball(){

    setRect(0,0,20,20);


    setPos(100,100);

    //random start rotation
    angle = (qrand() % 360);
    setRotation(angle);

    //set the speed;
    speed = 5;



    //random start position
    srand(time(NULL));
    int StartX = 0;
    int StartY = 0;

    if((qrand() % 1)){
        StartX = (qrand()%200);
        StartY = (qrand()%200);
    }else{
        StartX = (qrand()%-100);
        StartY = (qrand()%-100);
    }

    setPos(mapToParent(StartX,StartY));




    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);



}

QRectF Ball::boundingRect() const
{
 return QRectF(0,0,20,20);
}

void Ball::handleCollision()
{
    //Get a new position

    //Change the angle with a little randomness.
    if((qrand()%1)){
        setRotation(rotation()+(180+(qrand()%10)));
    } else {
        setRotation(rotation()+(180+(qrand() % -10)));
    }

    //see if the new position is in bounds
    QPointF newPoint = mapToParent(-(boundingRect().width()),-(boundingRect().width() + 2));

    if(!scene()->sceneRect().contains((newPoint))){
        //move it back in bounds
        newPoint = mapToParent(0,0);
    } else {
        //set the new position
        setPos(newPoint);
    }

}

void Ball::move()
{
    srand(time(NULL));


    QPointF location = this->pos();

    setPos(mapToParent(0,-(speed)));

    if(scene()->collidingItems(this).isEmpty()==false){
        //there is a collision!
        handleCollision();
    }


    //do collision detection
//    QList<QGraphicsItem *> colliding_items = collidingItems();
//    for (int i =0;i<colliding_items.size();i++)
//    {
//        if (typeid(*(colliding_items[i])) == typeid(Enemy) || typeid(*(colliding_items[i])) == typeid(MyRect) ){
//            qDebug() << QString::fromStdString("We hit a player");
//            handleCollision();

//        } else if(typeid(*(colliding_items[i])) == typeid(QGraphicsRectItem)){
//            qDebug() << QString::fromStdString("We hit a QGraphicsRectItem");
//            handleCollision();


//        }
//    }





//    setPos(x()+this->randX,y()+this->randY);
//    if(pos().y()+rect().height() <0){
//        scene()->removeItem(this);
//        delete this;
//    }


}




