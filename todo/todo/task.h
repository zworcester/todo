#ifndef TASK_H
#define TASK_H

// Implements a task. Has an id, name, description, and "checked" status.

#include <QString>

class Task
{
public:
    Task(const QString& id, const QString& taskName = "Default Task", const QString& taskDescription = "", bool checked = false);


    QString getID() const;
    QString getName() const;
    QString getDescription() const;
    bool isChecked() const;
    
    void setName(const QString& name);
    void setDescription(const QString& description);
    void check();
    void uncheck();
    
private:
    QString id;
    QString taskName;
    QString taskDescription;
    bool checked;
};

#endif // TASK_H
