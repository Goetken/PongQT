#include <QApplication>
#include <qgraphicsscene.h>
#include<QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include "ball.h"
#include "enemy.h"
#include <QTimer>
#include <unistd.h>
#include <QRect>
#include <bounds.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //create a scene
    QGraphicsScene *scene = new QGraphicsScene();

    //create items to put into the scene
    MyRect *rect = new MyRect();
    rect->setRect(0,0,20,100);

    QGraphicsRectItem *rectTop = new QGraphicsRectItem();
    rectTop->setRect(0,0,500,1);
    rectTop->setBrush(Qt::white);
    QGraphicsRectItem *rectBottom = new QGraphicsRectItem();
    rectBottom->setRect(0,499,500,1);
    rectBottom->setBrush(Qt::white);

    Bounds *leftBound = new Bounds();
    leftBound->setRect(0,0,1,500);
    leftBound->setBrush(Qt::white);

    Bounds *rightBound = new Bounds();
    rightBound->setRect(499,0,1,500);
    rightBound->setBrush(Qt::white);



    Ball * ball = new Ball();


    Enemy * enemy = new Enemy();
    enemy->setRect(0,0,20,100);
    enemy->ball = ball;

    enemy->difficulty = 4;





    //add the items to the scene

    scene->addItem(rect);
    rect->setBrush(Qt::white);
    scene->addItem(ball);
    ball->setBrush(Qt::white);
    scene->addItem(enemy);
    enemy->setBrush(Qt::white);

    scene->addItem(rectTop);
    scene->addItem(rectBottom);

    scene->addItem(leftBound);
    scene->addItem(rightBound);



    //make the item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();



    //add a view

    QRect sceneRect = QRect(0,0,500,500);
    scene->setBackgroundBrush(Qt::black);
    scene->setSceneRect(sceneRect);
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(500,500);

    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();


    QWidget window;
    window.resize(500,500);
    window.show();
    window.setWindowTitle(
                QApplication::translate("toplevel","Help"));
    QLabel *label = new QLabel();
    QHBoxLayout *layout = new QHBoxLayout();
    label->setText("Move your player by pressing the Up and Down arrow keys.  "
                   "if the ball turns red, you lose.  If it turns green, you win."
                   "The game will continue forever until you exit out");
    label->setWordWrap(true);
    layout->addWidget(label);

    window.setLayout(layout);


    return a.exec();
}


