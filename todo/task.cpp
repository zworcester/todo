#include "task.h"

Task::Task(int id, const QString& taskName = "Default Task", const QString& taskDescription = "", bool checked = false)
    :
      id{id},
      taskName{taskName},
      taskDescription{taskDescription},
      checked{checked}
{}

int Task::getID() const
{
    return this->id;
}


QString Task::getName() const
{
    return this->taskName;
}

QString Task::getDescription() const
{
    return this->taskDescription;
}

bool Task::isChecked() const
{
    return this->checked;
}

void Task::setName(const QString& name)
{
    this->taskName = name;
    return;
}

void Task::setDescription(const QString& description)
{
    this->taskDescription = description;
    return;
}

void Task::check()
{
    this->checked = true;
    return;
}

void Task::uncheck()
{
    this->checked = false;
    return;
}
