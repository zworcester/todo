#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DEBUG 1
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsRoundedRectItem* testrect = new QGraphicsRoundedRectItem(-100,0,100,100,10,10);
    testrect->setPen(Qt::NoPen);
    testrect->setBrush(QBrush(Qt::green));
    metaScene.addItem(testrect);

    ui->graphicsView->setScene(&metaScene);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
