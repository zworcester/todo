#include "mainwindow.h"
#include "ui_mainwindow.h"

#define DEBUG 1
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

#ifdef DEBUG
    // Create Dummy Categories
    ui->graphicsView->setCategories(QVector<TaskCategory>(
    {
        TaskCategory("0", "Dummy 1", {Task("0.0"), Task("0.1"), Task("0.2")}),
        TaskCategory("1", "Dummy 2", {Task("1.0"), Task("1.1"), Task("1.2")}),
        TaskCategory("2", "Dummy 3", {Task("2.0"), Task("2.1"), Task("2.2")}),
        TaskCategory("3", "Dummy 4", {Task("3.0"), Task("3.1"), Task("3.2")})
    }));
#else

#endif


}

MainWindow::~MainWindow()
{
    delete ui;
}

