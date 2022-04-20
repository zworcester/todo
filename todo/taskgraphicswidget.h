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
    void setTasks(QVector<TaskCategory> tasks);

private:
    QVector<TaskCategory> tasks;
};

#endif // TASKGRAPHICSWIDGET_H
