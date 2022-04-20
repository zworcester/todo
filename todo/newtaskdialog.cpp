#include "newtaskdialog.h"
#include "ui_newtaskdialog.h"

NewTaskDialog::NewTaskDialog(Task* task, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTaskDialog),
    task(task)
{
    ui->setupUi(this);

    this->ui->idLabel->setText("<b>" + this->task->getID() + "</b>");
    this->ui->newNameLineEdit->setPlaceholderText(this->task->getName());
    this->ui->descTextEdit->setPlaceholderText(this->task->getDescription());
    this->ui->checkBox->setCheckState(this->task->isChecked() ? Qt::Checked : Qt::Unchecked);
}

NewTaskDialog::~NewTaskDialog()
{
    delete ui;
}

void NewTaskDialog::accept()
{
    this->task->setName(this->ui->newNameLineEdit->text());
    this->task->setDescription(this->ui->descTextEdit->document()->toRawText());
    switch(this->ui->checkBox->checkState())
    {
    case Qt::Checked:
        this->task->check();
        break;
    case Qt::Unchecked:
        this->task->uncheck();
        break;
    default:
        break;
    }

    this->setResult(QDialog::Accepted);
    this->hide();

    emit finished(QDialog::Accepted);
}

void NewTaskDialog::reject()
{
    this->setResult(QDialog::Rejected);
    this->hide();

    emit finished(QDialog::Rejected);
}

void NewTaskDialog::done(int r)
{
    if (r == QDialog::Accepted)
    {
        this->task->setName(this->ui->newNameLineEdit->text());
        this->task->setDescription(this->ui->descTextEdit->document()->toRawText());
        switch(this->ui->checkBox->checkState())
        {
        case Qt::Checked:
            this->task->check();
            break;
        case Qt::Unchecked:
            this->task->uncheck();
            break;
        default:
            break;
        }

        this->setResult(QDialog::Accepted);
    }
    else if (r == QDialog::Rejected)
    {
        this->setResult(QDialog::Rejected);
    }

    this->hide();
    emit finished(r);
}

