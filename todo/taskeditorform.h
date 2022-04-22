#ifndef TASKEDITORFORM_H
#define TASKEDITORFORM_H

#include <QWidget>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QListWidgetItem>
#include <QMessageBox>

#include "task.h"
#include "taskcategory.h"
#include "qrandidgenerator.h"

namespace Ui {
class TaskEditorForm;
}

class TaskEditorForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskEditorForm(QWidget *parent = nullptr);
    ~TaskEditorForm();

    void populateForms(QVector<TaskCategory> tasks);

signals:
    void tasksSaved(QVector<TaskCategory> tasks);

public slots:
    void viewListRowChanged(int row);
    void viewListItemChanged(QListWidgetItem* item);

    void saveChangesClicked();
    void deleteCategoryClicked();
    void addCategoryClicked();
    void exitWithoutSaveClicked();
    void editTaskClicked();
    void cancelTaskChangeClicked();
    void confirmTaskChangeClicked();
    void editCategoryButtonClicked();
    void deleteTaskButtonClicked();
    void cancelCatChangeClicked();
    void addTaskButtonClicked();
    void catConfirmClicked();

private:
    Ui::TaskEditorForm *ui;

    QVector<TaskCategory> tempTasks;

    QMap<int,QPair<int,int>> viewIDXtoTaskIDX;

    QRandIDGenerator* idGenerator;

    Task* currentTask{nullptr};
    TaskCategory* currentCategory{nullptr};

};

#endif // TASKEDITORFORM_H
