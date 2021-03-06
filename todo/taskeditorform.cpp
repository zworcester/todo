/* ----------------------------------------------------
 * Filename: taskeditorform.cpp
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Zachary Worcester (zworcester0@fullerton.edu
 * ----------------------------------------------------
 */

#include "taskeditorform.h"
#include "ui_taskeditorform.h"

TaskEditorForm::TaskEditorForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskEditorForm)
{
    ui->setupUi(this);

    QObject::connect(ui->viewList, &QListWidget::currentRowChanged, this, &TaskEditorForm::viewListRowChanged);
    QObject::connect(ui->viewList, &QListWidget::itemChanged, this, &TaskEditorForm::viewListItemChanged);
    QObject::connect(ui->saveChanges, &QPushButton::pressed, this, &TaskEditorForm::saveChangesClicked);
    QObject::connect(ui->deleteCategoryButton, &QPushButton::pressed, this, &TaskEditorForm::deleteCategoryClicked);
    QObject::connect(ui->addCategoryButton, &QPushButton::pressed, this, &TaskEditorForm::addCategoryClicked);
    QObject::connect(ui->exitButton, &QPushButton::pressed, this, &TaskEditorForm::exitWithoutSaveClicked);
    QObject::connect(ui->editTaskButton, &QPushButton::pressed, this, &TaskEditorForm::editTaskClicked);
    QObject::connect(ui->cancelTaskChange, &QPushButton::pressed, this, &TaskEditorForm::cancelTaskChangeClicked);
    QObject::connect(ui->confirmTaskChange, &QPushButton::pressed, this, &TaskEditorForm::confirmTaskChangeClicked);
    QObject::connect(ui->editCategoryButton, &QPushButton::pressed, this, &TaskEditorForm::editCategoryButtonClicked);
    QObject::connect(ui->deleteTaskButton, &QPushButton::pressed, this, &TaskEditorForm::deleteTaskButtonClicked);
    QObject::connect(ui->catCancelButton, &QPushButton::pressed, this, &TaskEditorForm::cancelCatChangeClicked);
    QObject::connect(ui->addTaskButton, &QPushButton::pressed, this, &TaskEditorForm::addTaskButtonClicked);
    QObject::connect(ui->catConfirmChangesButton, &QPushButton::pressed, this, &TaskEditorForm::catConfirmClicked);
}

TaskEditorForm::~TaskEditorForm()
{
    delete ui;
}

// Populate all forms in the initital editor screen with
// data from the given task vector.
void TaskEditorForm::populateForms(QVector<TaskCategory> tasks)
{
    tempTasks = tasks;

    ui->viewList->clear();
    viewIDXtoTaskIDX.clear();

    // Populate ViewPort

    int itemIdx = 0;
    int categoryIdx = 0;

    for (TaskCategory& tC : this->tempTasks) {
        ui->viewList->addItem(tC.getName());
        viewIDXtoTaskIDX.insert(itemIdx, QPair<int,int>(categoryIdx,-1));
        int taskIdx = 0; 
        for(const Task& t : tC) {
            ui->viewList->addItem(t.getName());
            ++itemIdx;
            ui->viewList->item(itemIdx)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->viewList->item(itemIdx)->setCheckState((t.isChecked() ? Qt::Checked : Qt::Unchecked));
            viewIDXtoTaskIDX.insert(itemIdx, QPair<int,int>(categoryIdx,taskIdx));
            ++taskIdx;
        }
        ++categoryIdx;
        ++itemIdx;
    }

}

// Slot for when the user selects a row in the main category/task view
// list.
void TaskEditorForm::viewListRowChanged(int row)
{
    if (tempTasks.size() > 0) {
        if(viewIDXtoTaskIDX[row].second == -1) {
            ui->listViewStack->setCurrentIndex(0);
            TaskCategory temp = tempTasks[viewIDXtoTaskIDX[row].first];
            ui->catDescLabel->setText("Category ID: <b>" + temp.getID() + "</b>");
        }
        else {
           ui->listViewStack->setCurrentIndex(1);
           Task temp = tempTasks[viewIDXtoTaskIDX[row].first][viewIDXtoTaskIDX[row].second];
           ui->taskDescLabel->setText("Task ID: <b>" + temp.getID() + "</b><br/>Description: " + temp.getDescription());
        }
    }
    else {
        ui->listViewStack->setCurrentIndex(0);
        ui->catDescLabel->setText("No Categories.");
    }
}

// Slot for when the user changes an item in the category/task view list.
void TaskEditorForm::viewListItemChanged(QListWidgetItem* item)
{
    int itemIDX = ui->viewList->row(item);

    if (viewIDXtoTaskIDX[itemIDX].second != -1) {
        bool checkState = item->checkState() == Qt::Checked ? true : false;
        if (checkState) {
            tempTasks[viewIDXtoTaskIDX[itemIDX].first][viewIDXtoTaskIDX[itemIDX].second].check();
        }
        else {
            tempTasks[viewIDXtoTaskIDX[itemIDX].first][viewIDXtoTaskIDX[itemIDX].second].uncheck();
        }
    }
}

// Listener for when the Save Changes button pressed.
void TaskEditorForm::saveChangesClicked()
{
    QMessageBox::StandardButton answer = QMessageBox::question(this, "Are You Sure", "Are you sure you would like to save your changes?\nThis cannot be undone.", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if(answer == QMessageBox::Yes) {
        emit tasksSaved(tempTasks);
        this->hide();
    }
}

// Listener for when the Delete Category button pressed.
void TaskEditorForm::deleteCategoryClicked()
{
    if(ui->viewList->currentRow() < 0)
    {
        QMessageBox::information(this, "No Category Selected", "Select a category, dude.");
    }
    else
    {
        int categoryRow = viewIDXtoTaskIDX[ui->viewList->row(ui->viewList->currentItem())].first;
        QString categoryName = tempTasks[categoryRow].getName();
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Are You Sure", "Are you sure you would like to delete " + categoryName + "?\nThis cannot be undone.", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

        if(answer == QMessageBox::Yes)
        {
            ui->viewList->setCurrentRow(-1);
            ui->listViewStack->setCurrentIndex(0);
            ui->catDescLabel->setText(("Category ID: <b>None Selected</b>"));
            ui->taskDescLabel->setText(("Task ID: <b>None Selected</b><br/>Description: <b>Default</b>"));
            tempTasks.remove(categoryRow);

            populateForms(tempTasks);
        }
    }
}

// Listener for when the Add Category button pressed.
void TaskEditorForm::addCategoryClicked()
{
    TaskCategory tempCat("C_" + idGenerator->get(), "New Category");
    Task tempTask("T_" + idGenerator->get());

    tempCat.append(tempTask);

    tempTasks.append(tempCat);

    populateForms(tempTasks);
}

// Listener for when the Exit Without Save button pressed.
void TaskEditorForm::exitWithoutSaveClicked()
{
    this->close();
}

// Listener for when the Edit Task button pressed.
void TaskEditorForm::editTaskClicked()
{
    currentTask = &tempTasks[viewIDXtoTaskIDX[ui->viewList->currentRow()].first][viewIDXtoTaskIDX[ui->viewList->currentRow()].second];

    ui->taskEditIDLabel->setText("<b>" + currentTask->getID() + "</b>");
    ui->taskNameLineEdit->setText(currentTask->getName());
    ui->taskDescTextEdit->document()->setPlainText(currentTask->getDescription());
    ui->checkedBox->setCheckState(currentTask->isChecked() ? Qt::Checked : Qt::Unchecked);
    ui->editorStack->setCurrentIndex(2);
}

// Listener for when the Cancel Task Change button pressed.
void TaskEditorForm::cancelTaskChangeClicked()
{
    currentTask = nullptr;
    ui->editorStack->setCurrentIndex(0);
}

// Listener for when the Confirm Task Change button pressed.
void TaskEditorForm::confirmTaskChangeClicked()
{
    if(ui->taskNameLineEdit->text().isEmpty()) {
        QMessageBox::information(this,"No Name", "A task must have a name.\nWhat is wrong with you?");
    }
    else {
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Are You Sure", "Are you sure you would like to save the changes to " + currentTask->getName() + "?\nThis cannot be undone.", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

        if(answer == QMessageBox::Yes) {
            currentTask->setName(ui->taskNameLineEdit->text());
            currentTask->setDescription(ui->taskDescTextEdit->document()->toPlainText());
            if(ui->checkedBox->checkState() == Qt::Checked) {
                currentTask->check();
            }
            else {
                currentTask->uncheck();
            }

            populateForms(tempTasks);
            currentTask = nullptr;
            ui->editorStack->setCurrentIndex(0);
        }
    }
}

// Listener for when the Edit Category button pressed.
void TaskEditorForm::editCategoryButtonClicked()
{
    if(ui->viewList->currentRow() < 0)
    {
        QMessageBox::information(this, "No Category Selected", "Select a category, dude.");
    }
    else
    {
        currentCategory = &tempTasks[viewIDXtoTaskIDX[ui->viewList->currentRow()].first];

        for(const Task& t : *currentCategory)
            taskDescs.insert(t.getID(), t.getDescription());

        ui->catIDLabel->setText("<b>" + currentCategory->getID() + "</b>");
        ui->categoryNameLineEdit->setText(currentCategory->getName());
        ui->editorStack->setCurrentIndex(1);

        ui->taskList->clear();
        for(const Task& task : *currentCategory)
            ui->taskList->addItem(task.getName());
    }
}

// Listener for when the Delete Task button pressed.
void TaskEditorForm::deleteTaskButtonClicked()
{
    if(ui->taskList->count() > 0) {
        if(ui->taskList->currentRow() < 0) {
            QMessageBox::information(this, "No Tasks Selected", "Select a task, then we'll talk.");
        }
        else {
            ui->taskList->takeItem(ui->taskList->currentRow());
        }
    }
    else {
        QMessageBox::information(this, "No Tasks to Delete", "There is no task to delete.\nWhat do you want from me?");
    }
}

// Listener for when the Cancel Category Change button pressed.
void TaskEditorForm::cancelCatChangeClicked()
{
    currentCategory = nullptr;
    taskDescs.clear();
    ui->taskList->clear();
    ui->editorStack->setCurrentIndex(0);
}

// Listener for when the Add Task button pressed.
void TaskEditorForm::addTaskButtonClicked()
{
    if(ui->newTaskNameLineEdit->text().isEmpty()) {
        QMessageBox::information(this, "Task Has No Name", "Give the task a name, or no dice.");
    }
    else {
        ui->taskList->addItem(ui->newTaskNameLineEdit->text());
    }
}

// Listener for when the Category Change Confirm button pressed.
void TaskEditorForm::catConfirmClicked()
{
    if(ui->categoryNameLineEdit->text().isEmpty()) {
        QMessageBox::information(this, "Category Has No Name", "Give the Category a name, or no dice.");
    }
    else if(ui->taskList->count() < 1) {
        QMessageBox::information(this, "No Tasks", "Add at least one task to this category.");
    }
    else {
        currentCategory->setName(ui->categoryNameLineEdit->text());
        currentCategory->clear();

        for(int i = 0; i < ui->taskList->count(); ++i)
        {
            QString name = ui->taskList->item(i)->text();
            QString desc = "";
            if(taskDescs.contains(name))
            {
                desc = taskDescs[name];
            }

            Task t("T_" + idGenerator->get(), name, desc);
            currentCategory->append(t);


        }

        currentCategory = nullptr;
        ui->taskList->clear();
        populateForms(this->tempTasks);
        ui->editorStack->setCurrentIndex(0);
    }
}

void TaskEditorForm::closeEvent(QCloseEvent* event)
{
    this->ui->editorStack->setCurrentIndex(0);
    this->ui->listViewStack->setCurrentIndex(0);

    QWidget::closeEvent(event);
}

void TaskEditorForm::openWindow()
{
    ui->editorStack->setCurrentIndex(0);
    ui->listViewStack->setCurrentIndex(0);
}
