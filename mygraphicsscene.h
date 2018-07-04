#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyGraphicsScene();
    QPointF point;//�����
    QVector <QPointF> vertex;//�������
    int count;
    int rowCount;
    int columnCount;
private:
signals:
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYGRAPHICSVIEW_H
