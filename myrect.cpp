#include "myrect.h"
#include <QKeyEvent>


void MyRect::keyPressEvent(QKeyEvent *event){

    if (event->key() == Qt::Key_Up){
        if(pos().y() > 0)
        setPos(x(),y()-15);

    } else if (event->key() == Qt::Key_Down){
        if(pos().y() < 400){
            setPos(x(),y()+15);
        }
    }

}

MyRect::MyRect(){

    setPos(0,250);



}
