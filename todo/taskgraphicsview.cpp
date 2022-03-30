#include "taskgraphicsview.h"

TaskGraphicsView::TaskGraphicsView(QWidget* parent)
    :
      QGraphicsView(parent),
      _metascene{new QGraphicsScene}
{
    _metascene->addItem(new QGraphicsRoundedRectItem(100,100,100,100,15,15));

    this->setScene(_metascene);
    this->show();

}

TaskGraphicsView::~TaskGraphicsView()
{
    if (_metascene != nullptr) delete _metascene;


}

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
