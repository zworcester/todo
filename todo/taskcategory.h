/* ----------------------------------------------------
 * Filename: taskecategory.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Zachary Worcester (zworcester0@fullerton.edu
 * ----------------------------------------------------
 * Description:
 * Implements a Task Category using a QVector as a container.
 * Wraps some basic QVector functionality as well as
 * adds some Task-Specific functions. The most important methods
 * are append(), remove(), and getTask(). Range-based for-loops
 * work with this class.
 */

#ifndef TASKCATEGORY_H
#define TASKCATEGORY_H

#include <QString>
#include <QVector>
#include "task.h"

typedef QVector<Task> TaskVector;
typedef std::initializer_list<Task> TaskInit;
typedef TaskVector::Iterator taskIterator;
typedef TaskVector::ConstIterator constTaskIterator;


class TaskCategory
{
public:

    TaskCategory(const QString& id, const QString& name = "Default Category", TaskInit args = {});

    // Wrapper for iterator begin of internal task list.
    taskIterator begin();
    // Wrapper for iterator end of internal task list.
    taskIterator end();
    // Wrapper for const iterator begin of internal task list.
    constTaskIterator begin() const;
    // Wrapper for const iterator end of internal task list.
    constTaskIterator end() const;

    // Get the ID of the task category.
    QString getID() const;
    // Get the name of the task category.
    QString getName() const;

    // Get the requested Task at the index.
    Task& getTask(int idx);
    const Task& getTask(int idx) const;
    const Task& at(int i) const;
    Task& operator[](int i);
    const Task& operator[](int i) const;

    // Set the ID of the task category.
    void setID(const QString& id);
    // Set the name of the task category.
    void setName(const QString& name);

    // Add tasks to the internal task vector.
    void append(const Task& val);
    void append(Task& val);
    void append(const TaskCategory& other);

    // Remove the requested Task at the index.
    void remove(int i);

    // Clear the task vector.
    void clear();

    // Empty the internal task list.
    bool empty() const;
    // Return the size of the task vector.
    int size() const;


private:
    QString id;
    QString name;
    TaskVector tasks;
};

#endif // TASKCATEGORY_H
