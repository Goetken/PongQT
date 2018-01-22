#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem{

public:
    void keyPressEvent(QKeyEvent * event);
    MyRect();



};




#endif // MYRECT_H
