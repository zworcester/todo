#ifndef TASKGRAPHICSVIEW_H
#define TASKGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QVector>

#include "task.h"
#include "taskcategory.h"

typedef QVector<TaskCategory> TaskCatVector;
typedef TaskCatVector::Iterator taskCatIterator;
typedef TaskCatVector::ConstIterator constTaskCatIterator;

class TaskGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    TaskGraphicsView(QGraphicsScene* scene, QWidget* parent);
    TaskGraphicsView(QWidget* parent);

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
};

#endif // TASKGRAPHICSVIEW_H
