/* ----------------------------------------------------
 * Filename: mainwindow.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Taylor Ramsay (T_Ramsay0@fullerton.edu)
 * Editors:
 *  - Zachary Worcester
 *  - Taylor Ramsay
 * ----------------------------------------------------
 * Description: Displays the main window and associated buttons/listeners
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>
#include <QVector>
#include <QJsonDocument>
#include <QPen>
#include <QBrush>
#include <QSignalMapper>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>

#include "task.h"
#include "taskcategory.h"
#include "qgraphicsroundedrectitem.h"
#include "qrandidgenerator.h"
#include "taskgraphicswidget.h"
#include "parser.h"
#include "serializer.h"
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

    // Loads Tasks from a QVector
    void loadTasks(QVector<TaskCategory> tasks);

signals:
    // Signal for when the editor form is entered
    void editorOpened();

private slots:
    // Listener for edit button press
    void editorButtonClicked();
    // Listener for Task edit button press
    void tasksChanged(QVector<TaskCategory> tasks);
    // Listener for file menu quit trigger
    void quitActionTriggered();
    // Listener for file menu open trigger
    void openActionTriggered();
    // Listener for file menu save trigger
    void saveActionTriggered();
    // Listener for file menu new trigger
    void newActionTriggered();

private:
    Ui::MainWindow *ui;

    QGraphicsScene* metaScene;
    QVector<TaskCategory> tasks;
    TaskEditorForm* form;
};
#endif // MAINWINDOW_H
