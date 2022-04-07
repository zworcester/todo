#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DEBUG 1
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , metaScene(new QGraphicsScene)
{
    ui->setupUi(this);

    TaskGraphicsWidget* taskGraphics = new TaskGraphicsWidget;

    metaScene->addItem(taskGraphics);

    ui->graphicsView->setScene(metaScene);
    ui->graphicsView->show();

}

MainWindow::~MainWindow()
{
    delete metaScene;
    delete ui;
}
