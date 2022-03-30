#ifndef TASKCATEGORY_H
#define TASKCATEGORY_H

#include <QString>
#include <QVector>
#include "task.h"

/* Implements a Task Category using a QVector as a container.
 * Wraps some basic QVector functionality as well as
 * adds some Task-Specific functions. The most important methods
 * are append(), remove(), and getTask(). Range-based for-loops
 * work with this class.
 */

typedef QVector<Task> TaskVector;
typedef std::initializer_list<Task> TaskInit;
typedef TaskVector::Iterator taskIterator;
typedef TaskVector::ConstIterator constTaskIterator;


class TaskCategory
{
public:

    TaskCategory(const QString& id, const QString& name, TaskInit args);

    taskIterator begin();
    taskIterator end();
    constTaskIterator begin() const;
    constTaskIterator end() const;

    QString getID() const;
    QString getName() const;

    Task& getTask(int idx);
    const Task& getTask(int idx) const;
    const Task& at(int i) const;
    Task& operator[](int i);
    const Task& operator[](int i) const;

    void setID(const QString& id);
    void setName(const QString& name);

    void append(const Task& val);
    void append(Task& val);
    void append(const TaskCategory& other);

    void remove(int i);

    void clear();

    bool empty();
    int size();


private:
    QString id;
    QString name;
    TaskVector tasks;
};

#endif // TASKCATEGORY_H
