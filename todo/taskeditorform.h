#ifndef TASKEDITORFORM_H
#define TASKEDITORFORM_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QMessageBox>

#include "task.h"
#include "taskcategory.h"

namespace Ui {
class TaskEditorForm;
}

class TaskEditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskEditorForm(QVector<TaskCategory>* tasks = nullptr, QWidget *parent = nullptr);
    ~TaskEditorForm();

public slots:
    void viewListRowChanged(int row);

private:
    void populateAllForms();

    Ui::TaskEditorForm *ui;

    QVector<TaskCategory>* tasks;
    QVector<TaskCategory> tempTasks;

    QMap<int,QPair<int,int>> viewIDXtoTaskIDX;

};

#endif // TASKEDITORFORM_H
