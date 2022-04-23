/* ----------------------------------------------------
 * Filename: task.h
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
 * Description: Implements a Task class which has an id, name, decription, and "checked" status
 */
#ifndef TASK_H
#define TASK_H

#include <QString>

class Task
{
public:
    Task(const QString& id, const QString& taskName = "Default Task", const QString& taskDescription = "", bool checked = false);

    // Returns the ID of the Task
    QString getID() const;
    // Returns the Name of the Task
    QString getName() const;
    // Returns the Description of the Task
    QString getDescription() const;
    // Returns the Checked flag of the Task
    bool isChecked() const;

    // Sets the name of the Task
    void setName(const QString& name);
    // Sets the description of the Task
    void setDescription(const QString& description);
    // Marks the Task as complete
    void check();
    // Marks the Task an not complete
    void uncheck();
    
private:
    QString id;
    QString taskName;
    QString taskDescription;
    bool checked;
};

#endif // TASK_H
