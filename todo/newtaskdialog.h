#ifndef NEWTASKDIALOG_H
#define NEWTASKDIALOG_H

#include <QDialog>

#include "task.h"

namespace Ui {
class NewTaskDialog;
}

class NewTaskDialog : public QDialog
{
    Q_OBJECT

public:
    NewTaskDialog(Task* task, QWidget *parent = nullptr);
    ~NewTaskDialog();


public slots:
    virtual void accept() override;
    virtual void reject() override;
    virtual void done(int r) override;

private:
    Ui::NewTaskDialog *ui;
    Task* task;
};

#endif // NEWTASKDIALOG_H
