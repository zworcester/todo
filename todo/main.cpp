#include "mainwindow.h"

#include <QApplication>
#include <QTest>
#include "basictest.h"

int main(int argc, char *argv[])
{
    BasicTest h;
    QObject* t = &h;
    QTest::qExec(t);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
