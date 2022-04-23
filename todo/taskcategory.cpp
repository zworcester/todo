/* ----------------------------------------------------
 * Filename: taskeditorform.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Zachary Worcester (zworcester0@fullerton.edu
 * ----------------------------------------------------
 */

#include "taskcategory.h"

TaskCategory::TaskCategory(const QString& id, const QString& name, TaskInit args)
    :
      id(id),
      name(name),
      tasks(args)
{}

// Wrapper for iterator begin of internal task list.
taskIterator TaskCategory::begin()
{
    return tasks.begin();
}

// Wrapper for iterator end of internal task list.
taskIterator TaskCategory::end()
{
    return tasks.end();
}

// Wrapper for const iterator begin of internal task list.
constTaskIterator TaskCategory::begin() const
{
    return tasks.begin();
}

// Wrapper for const iterator end of internal task list.
constTaskIterator TaskCategory::end() const
{
    return tasks.end();
}

// Get the ID of the task category.
QString TaskCategory::getID() const
{
    return id;
}

// Get the name of the task category.
QString TaskCategory::getName() const
{
    return name;
}

// Get the requested Task at the index.
Task& TaskCategory::getTask(int idx)
{
    return tasks[idx];
}

// Get the requested Task at the index.
const Task& TaskCategory::getTask(int idx) const
{
    return tasks[idx];
}

const Task& TaskCategory::at(int idx) const
{
    return tasks.at(idx);
}

// Get the requested Task at the index.
Task& TaskCategory::operator[](int idx)
{
    return tasks[idx];
}

// Get the requested Task at the index.
const Task& TaskCategory::operator[](int idx) const
{
    return tasks[idx];
}

// Set the ID of the task category.
void TaskCategory::setID(const QString& id)
{
    this->id = id;
    return;
}

// Set the name of the task category.
void TaskCategory::setName(const QString& name)
{
    this->name = name;
    return;
}

// Add tasks to the internal task vector.
void TaskCategory::append(const Task& val)
{
    tasks.append(val);
    return;
}

// Add tasks to the internal task vector.
void TaskCategory::append(Task& val)
{
    tasks.append(val);
    return;
}

// Add tasks to the internal task vector.
void TaskCategory::append(const TaskCategory& other)
{
    for(const Task& task : other)
        tasks.append(task);

    return;
}

// Remove the requested Task at the index.
void TaskCategory::remove(int idx)
{
    tasks.remove(idx);
    return;
}

// Clear the task vector.
void TaskCategory::clear()
{
    tasks.clear();

    return;
}

// Empty the internal task list.
bool TaskCategory::empty() const
{
    return tasks.empty();
}

// Return the size of the task vector.
int TaskCategory::size() const
{
    return tasks.size();
}
