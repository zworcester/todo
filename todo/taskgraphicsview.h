#ifndef TASKGRAPHICSVIEW_H
#define TASKGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QVector>

#include "task.h"
#include "taskcategory.h"
#include "qgraphicsroundedrectitem.h"

typedef QVector<TaskCategory> TaskCatVector;
typedef TaskCatVector::Iterator taskCatIterator;
typedef TaskCatVector::ConstIterator constTaskCatIterator;

class TaskGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    TaskGraphicsView(QWidget* parent);
    ~TaskGraphicsView();

    taskCatIterator begin();
    taskCatIterator end();
    constTaskCatIterator begin() const;
    constTaskCatIterator end() const;

    void setCategories(QVector<TaskCategory>& categories);
    void setCategories(const QVector<TaskCategory>& categories);
    void addCategory(TaskCategory& category);
    void addCategory(const TaskCategory& category);
    void removeCategory(int i);
    const TaskCategory& getCategory(int i) const;
    int size() const;

private:
    QVector<TaskCategory> categories;
    QGraphicsScene* _metascene;
};

#endif // TASKGRAPHICSVIEW_H
