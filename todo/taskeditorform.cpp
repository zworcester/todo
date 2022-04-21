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


}

TaskEditorForm::~TaskEditorForm()
{
    delete ui;
}

void TaskEditorForm::populateForms(QVector<TaskCategory> tasks)
{
    tempTasks = tasks;

    ui->viewList->clear();
    viewIDXtoTaskIDX.clear();

    // Populate ViewPort

    int itemIdx = 0;
    int categoryIdx = 0;

    for (TaskCategory& tC : this->tempTasks)
    {
        ui->viewList->addItem(tC.getName());
        viewIDXtoTaskIDX.insert(itemIdx, QPair<int,int>(categoryIdx,-1));
        int taskIdx = 0; 
        for(const Task& t : tC)
        {
            ui->viewList->addItem(t.getName());
            ++itemIdx;
            //ui->viewList->item(itemIdx)->setData(1, QVariant('T'));
            //ui->viewList->item(itemIdx)->setData(2, QVariant(categoryIdx));
            //ui->viewList->item(itemIdx)->setData(3, QVariant(taskIdx));
            ui->viewList->item(itemIdx)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->viewList->item(itemIdx)->setCheckState((t.isChecked() ? Qt::Checked : Qt::Unchecked));
            viewIDXtoTaskIDX.insert(itemIdx, QPair<int,int>(categoryIdx,taskIdx));
            ++taskIdx;
        }
        ++categoryIdx;
        ++itemIdx;
    }

}

void TaskEditorForm::viewListRowChanged(int row)
{
    if (tempTasks.size() > 0)
    {
        if(viewIDXtoTaskIDX[row].second == -1)
        {
            ui->listViewStack->setCurrentIndex(0);
            TaskCategory temp = tempTasks[viewIDXtoTaskIDX[row].first];
            ui->catDescLabel->setText("Category ID: <b>" + temp.getID() + "</b>");
        }
        else
        {
           ui->listViewStack->setCurrentIndex(1);
           Task temp = tempTasks[viewIDXtoTaskIDX[row].first][viewIDXtoTaskIDX[row].second];
           ui->taskDescLabel->setText("Task ID: <b>" + temp.getID() + "</b><br/>Description: " + temp.getDescription());
        }
    }
    else
    {
        ui->listViewStack->setCurrentIndex(0);
        ui->catDescLabel->setText("No Categories.");
    }
}

void TaskEditorForm::viewListItemChanged(QListWidgetItem* item)
{
    int itemIDX = ui->viewList->row(item);

    if (viewIDXtoTaskIDX[itemIDX].second != -1)
    {
        bool checkState = item->checkState() == Qt::Checked ? true : false;
        if (checkState)
        {
            tempTasks[viewIDXtoTaskIDX[itemIDX].first][viewIDXtoTaskIDX[itemIDX].second].check();
        }
        else
        {
            tempTasks[viewIDXtoTaskIDX[itemIDX].first][viewIDXtoTaskIDX[itemIDX].second].uncheck();
        }
    }
}

void TaskEditorForm::saveChangesClicked()
{
    QMessageBox::StandardButton answer = QMessageBox::question(this, "Are You Sure", "Are you sure you would like to save your changes?\nThis cannot be undone.", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if(answer == QMessageBox::Yes)
    {
        emit tasksSaved(tempTasks);
        this->hide();
    }
}

void TaskEditorForm::deleteCategoryClicked()
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

void TaskEditorForm::addCategoryClicked()
{
    TaskCategory tempCat("C_" + idGenerator->get(), "New Category");
    Task tempTask("T_" + idGenerator->get());

    tempCat.append(tempTask);

    tempTasks.append(tempCat);

    populateForms(tempTasks);
}

void TaskEditorForm::exitWithoutSaveClicked()
{
    this->close();
}

void TaskEditorForm::editTaskClicked()
{
    currentTask = &tempTasks[viewIDXtoTaskIDX[ui->viewList->currentRow()].first][viewIDXtoTaskIDX[ui->viewList->currentRow()].second];

    ui->taskEditIDLabel->setText("<b>" + currentTask->getID() + "</b>");
    ui->taskNameLineEdit->setText(currentTask->getName());
    ui->taskDescTextEdit->document()->setPlainText(currentTask->getDescription());
    ui->checkedBox->setCheckState(currentTask->isChecked() ? Qt::Checked : Qt::Unchecked);
    ui->editorStack->setCurrentIndex(2);
}

void TaskEditorForm::cancelTaskChangeClicked()
{
    currentTask = nullptr;
    ui->editorStack->setCurrentIndex(0);
}

void TaskEditorForm::confirmTaskChangeClicked()
{
    if(ui->taskNameLineEdit->text().isEmpty())
    {
        QMessageBox::information(this,"No Name", "A task must have a name.\nWhat is wrong with you?");
    }
    else
    {
        QMessageBox::StandardButton answer = QMessageBox::question(this, "Are You Sure", "Are you sure you would like to save the changes to " + currentTask->getName() + "?\nThis cannot be undone.", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

        if(answer == QMessageBox::Yes)
        {
            currentTask->setName(ui->taskNameLineEdit->text());
            currentTask->setDescription(ui->taskDescTextEdit->document()->toPlainText());
            if(ui->checkedBox->checkState() == Qt::Checked)
            {
                currentTask->check();
            }
            else
            {
                currentTask->uncheck();
            }

            populateForms(tempTasks);
            currentTask = nullptr;
            ui->editorStack->setCurrentIndex(0);
        }
    }
}

void TaskEditorForm::editCategoryButtonClicked()
{
    currentCategory = &tempTasks[viewIDXtoTaskIDX[ui->viewList->currentRow()].first];

    ui->catIDLabel->setText("<b>" + currentCategory->getID() + "</b>");
    ui->categoryNameLineEdit->setText(currentCategory->getName());
    ui->editorStack->setCurrentIndex(1);

    for(const Task& task : *currentCategory)
        ui->taskList->addItem(task.getName());
}

void TaskEditorForm::deleteTaskButtonClicked()
{
    if(ui->taskList->count() > 0)
    {
        if(ui->taskList->currentRow() < 0)
        {
            QMessageBox::information(this, "No Tasks Selected", "Select a task, then we'll talk.");
        }
        else
        {
            ui->taskList->takeItem(ui->taskList->currentRow());
        }
    }
    else
    {
        QMessageBox::information(this, "No Tasks to Delete", "There is no task to delete.\nWhat do you want from me?");
    }
}

void TaskEditorForm::cancelCatChangeClicked()
{
    currentCategory = nullptr;
    ui->taskList->clear();
    ui->editorStack->setCurrentIndex(0);
}
