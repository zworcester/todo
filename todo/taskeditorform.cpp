#include "taskeditorform.h"
#include "ui_taskeditorform.h"

TaskEditorForm::TaskEditorForm(QVector<TaskCategory>* tasks, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskEditorForm),
    tasks(tasks)
{
    if (this->tasks != nullptr)
    {
        tempTasks = *tasks;
    }

    ui->setupUi(this);

    QObject::connect(ui->viewList, &QListWidget::currentRowChanged, this, &TaskEditorForm::viewListRowChanged);
    populateAllForms();
}

TaskEditorForm::~TaskEditorForm()
{
    delete ui;
}

void TaskEditorForm::populateAllForms()
{
    ui->viewList->reset();
    viewIDXtoTaskIDX.clear();

    // Populate ViewPort

    int itemIdx = 0;
    int categoryIdx = 0;

    for (TaskCategory& tC : this->tempTasks)
    {
        ui->viewList->addItem(tC.getName());
        viewIDXtoTaskIDX.insert(itemIdx, QPair<int,int>(categoryIdx,-1));
        ++itemIdx;
        int taskIdx = 0;
        for(const Task& t : tC)
        {
            ui->viewList->addItem(t.getName());
            //ui->viewList->item(itemIdx)->setData(1, QVariant('T'));
            //ui->viewList->item(itemIdx)->setData(2, QVariant(categoryIdx));
            //ui->viewList->item(itemIdx)->setData(3, QVariant(taskIdx));
            ui->viewList->item(itemIdx)->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
            ui->viewList->item(itemIdx)->setCheckState((t.isChecked() ? Qt::Checked : Qt::Unchecked));
            viewIDXtoTaskIDX.insert(itemIdx, QPair<int,int>(categoryIdx,taskIdx));
            ++itemIdx;
            ++taskIdx;
        }
        ++categoryIdx;
    }

}

void TaskEditorForm::viewListRowChanged(int row)
{

    if(viewIDXtoTaskIDX[row].second == -1)
    {
        ui->listViewStack->setCurrentIndex(0);
        TaskCategory temp = tempTasks[viewIDXtoTaskIDX[row].first];
        ui->catDescLabel->setText("Category ID: <b>" + temp.getName() + "</b>");
    }
    else
    {
       ui->listViewStack->setCurrentIndex(1);
       Task temp = tempTasks[viewIDXtoTaskIDX[row].first][viewIDXtoTaskIDX[row].second];
       ui->catDescLabel->setText("Task ID: <b>" + temp.getName() + "</b>\nDescription: " + temp.getDescription());
    }
}
