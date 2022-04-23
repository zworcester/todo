/* ----------------------------------------------------
 * Filename: taskGraphicsWidget.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Desirae Prather (DesiraePrather@fullerton.edu)
 * Editors:
 *  Zachary Worcester (zworcester0@fullerton.edu)
 *  Desirae Prather (DesiraePrather@fullerton.edu)
 * ----------------------------------------------------
 * Description:
 * TaskGraphicsWidget is a class used to build the widgets that are displayed on the
 * mainwindow. It displays the to do lists which are the categories and tasks in rectangles.
 * it has a constructor. It contains only one function that is used to clears pervious tasks,
 * set new tasks, and creates widgets that is used to display the categories and tasks on the
 * mainwindow. It has one private variable which is the tasks.
 */

#ifndef TASKGRAPHICSWIDGET_H
#define TASKGRAPHICSWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QObject>
#include <QVector>
#include <QRandomGenerator>
#include <QList>
#include <QColor>

#include "parser.h"

#include "taskcategory.h"
#include "task.h"
#include "qgraphicsroundedrectitem.h"


class TaskGraphicsWidget : public QGraphicsWidget
{
    Q_OBJECT
public:
    TaskGraphicsWidget(QGraphicsWidget* parent = nullptr);
    // Clears pervious tasks, set new tasks, and sets and creates
    // the widgets that is used to display the categories and tasks on the mainwindow
    void setTasks(QVector<TaskCategory> tasks);

private:
    QVector<TaskCategory> tasks;
};

#endif // TASKGRAPHICSWIDGET_H
