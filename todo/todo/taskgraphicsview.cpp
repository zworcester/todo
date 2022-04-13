#include "taskgraphicsview.h"

/*
    taskCatIterator begin();
    taskCatIterator end();
    constTaskCatIterator begin() const;
    constTaskCatIterator end() const;
*/

TaskGraphicsView::TaskGraphicsView(QGraphicsScene* scene, QWidget* parent)
    :
      QGraphicsView(scene, parent)
{}

TaskGraphicsView::TaskGraphicsView(QWidget* parent)
    :
      QGraphicsView(parent)
{}

taskCatIterator TaskGraphicsView::begin()
{
    return this->categories.begin();
}
taskCatIterator TaskGraphicsView::end()
{
    return this->categories.end();
}
constTaskCatIterator TaskGraphicsView::begin() const
{
    return this->categories.begin();
}
constTaskCatIterator TaskGraphicsView::end() const
{
    return this->categories.end();
}

void TaskGraphicsView::setCategories(QVector<TaskCategory>& categories)
{
    for(TaskCategory& cat : categories)
        this->categories.append(cat);

    return;
}

void TaskGraphicsView::setCategories(const QVector<TaskCategory>& categories)
{
    for(const TaskCategory& cat : categories)
        this->categories.append(cat);

    return;
}

void TaskGraphicsView::addCategory(TaskCategory& cat)
{
    this->categories.append(cat);

    return;
}

void TaskGraphicsView::addCategory(const TaskCategory& cat)
{
    this->categories.append(cat);

    return;
}

void TaskGraphicsView::removeCategory(int i)
{
    this->categories.remove(i);

    return;
}

const TaskCategory& TaskGraphicsView::getCategory(int i) const
{
    return this->categories[i];
}

int TaskGraphicsView::size() const
{
    return this->categories.size();
}
