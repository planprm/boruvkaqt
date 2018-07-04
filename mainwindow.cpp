#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MyGraphicsScene();
    scene->setSceneRect(0,0,300,300);
    ui->label_2->setText("");
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing,true);
}

void MainWindow::boruvka()// Алгоритм Борувка - Солина
{
    QVector<int> t;
    int MAXV = 100;
    int mas[MAXV+1][MAXV+1];
    int minEdge[MAXV+1];
    int n = 0;

    for(int i=0;i<MAXV;++i)
        for(int j=0;j<MAXV;++j)
            mas[i][j] = 0;


    // Заполнение массива mas весами ребер
    for(int i=0;i<scene->count;++i)
    {
        for(int j=0;j<scene->count;++j)
        {
            if(ui->tableWidget->item(i,j) != 0)
            {
                mas[i][n] = ui->tableWidget->item(i,j)->text().toInt();
                n++;
            }
        }
    }

    //алгоритм
    while(t.size() < scene->count - 1)
    {
        int k = 0;
        while(k != scene->count)
        {
            for(int j=0;j<MAXV;++j)
                if(mas[k][j] != 0)
                {
                    if(mas[k][j] < mas[k][j+1])
                        minEdge[k] = mas[k][j];
                    else minEdge[k] = mas[k][j+1];
                    k++;
                }
        }
        for(int i=0;i<scene->count;++i)
        {
            for(int j=0;j<scene->count;++j)
            {
                if(ui->tableWidget->item(i,j) != 0)
                {
                    if(minEdge[i] == ui->tableWidget->item(i,j)->text().toInt())
                    {
                        scene->addLine(scene->vertex[i].x()+12,scene->vertex[i].y()+12,
                                       scene->vertex[j].x()+12,scene->vertex[j].y()+12);
                        int p = (scene->vertex[i].x() + scene->vertex[j].x()) / 2;
                        int l = (scene->vertex[i].y() + scene->vertex[j].y()) / 2;

                        QGraphicsTextItem * io = new QGraphicsTextItem;
                        io->setPos(p-20,l-20);
                        io->setPlainText(QString::number(minEdge[i]));
                        scene->addItem(io);
                    }
                }
            }
        }
        for(int i=0;i<scene->count;++i)
            t.push_back(minEdge[i]);
        scene->update();
    }
}

void MainWindow::showresults()
{
    ui->label_2->setText(str);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        ui->tableWidget->setColumnCount(scene->columnCount);
        ui->tableWidget->setRowCount(scene->rowCount);
      //ui->tableWidget->setItem(0,0,new QTableWidgetItem("0"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    scene->clear();
    str = "";
    scene->vertex.clear();
    ui->label_2->setText("");
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);

    for(int i=0;i<scene->rowCount;i++)
        ui->tableWidget->removeRow(i);
    for(int j=0;j<scene->columnCount;j++)
        ui->tableWidget->removeColumn(j);
    scene->columnCount = 0;
    scene->rowCount = 0;
    scene->count = 0;
    ui->tableWidget->clear();
    ui->tableWidget->clearContents();
}

void MainWindow::on_pushButton_clicked()
{
    this->boruvka();
    this->showresults();
}
