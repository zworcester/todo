#ifndef TASKGRAPHICSWIDGET_H
#define TASKGRAPHICSWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QObject>
#include <QVector>

#include "taskcategory.h"
#include "task.h"
#include "qgraphicsroundedrectitem.h"

class TaskGraphicsWidget : public QGraphicsWidget
{
    Q_OBJECT
public:
    TaskGraphicsWidget(QGraphicsWidget* parent = nullptr);
    QVector<TaskCategory> tasks;
};

#endif // TASKGRAPHICSWIDGET_H
