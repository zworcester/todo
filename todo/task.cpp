/* ----------------------------------------------------
 * Filename: task.cpp
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Taylor Ramsay (T_Ramsay0@fullerton.edu)
 * Editors:
 *  - Zachary Worcester
 *  - Taylor Ramsay
 * ----------------------------------------------------
 */
#include "task.h"

Task::Task(const QString& id, const QString& taskName, const QString& taskDescription, bool checked)
    :
      id(id),
      taskName(taskName),
      taskDescription(taskDescription),
      checked(checked)
{}

// Returns the ID of the Task
QString Task::getID() const
{
    return this->id;
}

// Returns the Name of the Task
QString Task::getName() const
{
    return this->taskName;
}

// Returns the Description of the Task
QString Task::getDescription() const
{
    return this->taskDescription;
}

// Returns the Checked flag of the Task
bool Task::isChecked() const
{
    return this->checked;
}

// Sets the Name of the Task
void Task::setName(const QString& name)
{
    this->taskName = name;
    return;
}

// Sets the Description of the Task
void Task::setDescription(const QString& description)
{
    this->taskDescription = description;
    return;
}

// Marks the Task as complete
void Task::check()
{
    this->checked = true;
    return;
}

// Marks the Task as not complete
void Task::uncheck()
{
    this->checked = false;
    return;
}
