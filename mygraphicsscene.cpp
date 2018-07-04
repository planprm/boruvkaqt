#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene()
{
    count = 0;
    rowCount = 0;
    columnCount = 0;
}

void MyGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        point = event->scenePos();
        addEllipse(point.x(), point.y(),25.0,25.0,
                    QPen(Qt::black), QBrush(Qt::gray));
        count++;
        rowCount = count;
        columnCount = count;
        QGraphicsTextItem * io = new QGraphicsTextItem;
        io->setPos(point.x()+5,point.y()+2);
        io->setPlainText(QString::number(count));
        addItem(io);
        vertex.append(point);
    }

}
