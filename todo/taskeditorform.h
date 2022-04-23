/* ----------------------------------------------------
 * Filename: taskeditorform.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Zachary Worcester (zworcester0@fullerton.edu
 * ----------------------------------------------------
 * Description:
 * This file implements the editor functionality. A user can
 * edit both tasks and categories, as well as delete and create them.
 * It also doubles as a checklist for the tasks.
 */

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

    // Populate all forms in the initital editor screen with
    // data from the given task vector.
    void populateForms(QVector<TaskCategory> tasks);

signals:
    // Emit a signal signifying that changes were made
    // to the tasks, passing those changes to the waiting slot.
    void tasksSaved(QVector<TaskCategory> tasks);

public slots:
    // Slot for when the user selects a row in the main category/task view
    // list.
    void viewListRowChanged(int row);

    // Slot for when the user changes an item in the category/task view list.
    void viewListItemChanged(QListWidgetItem* item);

    // Listener for when the Save Changes button pressed.
    void saveChangesClicked();
    // Listener for when the Delete Category button pressed.
    void deleteCategoryClicked();
    // Listener for when the Add Category button pressed.
    void addCategoryClicked();
    // Listener for when the Exit Without Save button pressed.
    void exitWithoutSaveClicked();
    // Listener for when the Edit Task button pressed.
    void editTaskClicked();
    // Listener for when the Cancel Task Change button pressed.
    void cancelTaskChangeClicked();
    // Listener for when the Confirm Task Change button pressed.
    void confirmTaskChangeClicked();
    // Listener for when the Edit Category button pressed.
    void editCategoryButtonClicked();
    // Listener for when the Delete Task button pressed.
    void deleteTaskButtonClicked();
    // Listener for when the Cancel Category Change button pressed.
    void cancelCatChangeClicked();
    // Listener for when the Add Task button pressed.
    void addTaskButtonClicked();
    // Listener for when the Category Change Confirm button pressed.
    void catConfirmClicked();

private:
    Ui::TaskEditorForm *ui;

    QVector<TaskCategory> tempTasks;

    QMap<int,QPair<int,int>> viewIDXtoTaskIDX;
    QMap<QString,QString> tempDescriptions;

    QRandIDGenerator* idGenerator;

    Task* currentTask{nullptr};
    TaskCategory* currentCategory{nullptr};

};

#endif // TASKEDITORFORM_H
