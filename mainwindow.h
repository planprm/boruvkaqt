#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGridLayout>
#include <algorithm>
#include "mygraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<int> item;//���������������,���������� ��������
public:
    explicit MainWindow(QWidget *parent = 0);
    MyGraphicsScene *scene;
    void boruvka();//�������� �������
    void showresults();//����������
    QString str;
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
