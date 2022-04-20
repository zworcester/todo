#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>
#include <QPen>
#include <QBrush>
#include <QSignalMapper>

#include "task.h"
#include "taskcategory.h"
#include "qgraphicsroundedrectitem.h"
#include "taskgraphicswidget.h"
#include "parser.h"
#include "taskeditorform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void editorButtonClicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* metaScene;
    QVector<TaskCategory> tasks;
    TaskEditorForm* form;
};
#endif // MAINWINDOW_H
