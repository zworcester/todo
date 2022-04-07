#ifndef TASKGRAPHICSWIDGET_H
#define TASKGRAPHICSWIDGET_H

#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QObject>

#include "qgraphicsroundedrectitem.h"

class TaskGraphicsWidget : public QGraphicsWidget
{
    Q_OBJECT
public:
    TaskGraphicsWidget(QGraphicsWidget* parent = nullptr);
};

#endif // TASKGRAPHICSWIDGET_H
