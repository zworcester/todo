#include "taskcategory.h"

TaskCategory::TaskCategory(const QString& id, const QString& name, TaskInit args)
    :
      id{id},
      name{name},
      tasks{args}
{}

taskIterator TaskCategory::begin()
{
    return tasks.begin();
}

taskIterator TaskCategory::end()
{
    return tasks.end();
}

constTaskIterator TaskCategory::begin() const
{
    return tasks.begin();
}

constTaskIterator TaskCategory::end() const
{
    return tasks.end();
}

QString TaskCategory::getID() const
{
    return id;
}

QString TaskCategory::getName() const
{
    return name;
}

Task& TaskCategory::getTask(int idx)
{
    return tasks[idx];
}

const Task& TaskCategory::getTask(int idx) const
{
    return tasks[idx];
}

const Task& TaskCategory::at(int idx) const
{
    return tasks.at(idx);
}

Task& TaskCategory::operator[](int idx)
{
    return tasks[idx];
}

const Task& TaskCategory::operator[](int idx) const
{
    return tasks[idx];
}

void TaskCategory::setID(const QString& id)
{
    this->id = id;
    return;
}

void TaskCategory::setName(const QString& name)
{
    this->name = name;
    return;
}

void TaskCategory::append(const Task& val)
{
    tasks.append(val);
    return;
}

void TaskCategory::append(Task& val)
{
    tasks.append(val);
    return;
}

void TaskCategory::append(const TaskCategory& other)
{
    for(const Task& task : other)
        tasks.append(task);

    return;
}

void TaskCategory::remove(int idx)
{
    tasks.remove(idx);
    return;
}

void TaskCategory::clear()
{
    tasks.clear();

    return;
}

int TaskCategory::size() const
{
    return tasks.size();
}

bool TaskCategory::empty() const
{
    return this->size();
}
