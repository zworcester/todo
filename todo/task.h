#ifndef TASK_H
#define TASK_H

// Implements a task. Has an id, name, description, and "checked" status.

#include <QString>

class Task
{
public:
    Task(int id, const QString& taskName, const QString& taskDescription, bool checked);
    
    int getID() const;
    QString getName() const;
    QString getDescription() const;
    bool isChecked() const;
    
    void setName(const QString& name);
    void setDescription(const QString& description);
    void check();
    void uncheck();
    
private:
    int id;
    QString taskName;
    QString taskDescription;
    bool checked;
};

#endif // TASK_H
