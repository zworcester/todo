/* ----------------------------------------------------
 * Filename: taskGraphicsWidget.h
 * Project: Todo
 * Licence: GPL
 * ----------------------------------------------------
 * Date of Last Edit:
 * APRIL 22nd, 2022
 * Last Edit: Desirae Prather (DesiraePrather@fullerton.edu)
 * Editors:
 *  Zachary Worcester (zworcester0@fullerton.edu)
 *  Desirae Prather (DesiraePrather@fullerton.edu)
 */
#include "taskgraphicswidget.h"

TaskGraphicsWidget::TaskGraphicsWidget(QGraphicsWidget* parent)
    :
      QGraphicsWidget(parent)
{
    QGraphicsLinearLayout* widgetLayout = new QGraphicsLinearLayout(Qt::Vertical);
    QGraphicsLinearLayout* linear = new QGraphicsLinearLayout(widgetLayout);
    this->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);

    linear->setOrientation(Qt::Vertical);

    widgetLayout->addItem(linear);

    this->setLayout(widgetLayout);
    this->show();
}

// Clears pervious tasks, set new tasks, and sets and creates
// the widgets that is used to display the categories and tasks on the mainwindow
void TaskGraphicsWidget::setTasks(QVector<TaskCategory> tasks)
{
    this->tasks.clear();
    this->tasks = tasks;

    QGraphicsLinearLayout* widgetLayout = new QGraphicsLinearLayout(Qt::Vertical);
    QGraphicsLinearLayout* linear = new QGraphicsLinearLayout(widgetLayout);
    linear->setOrientation(Qt::Vertical);

    for (TaskCategory& category : tasks) {
        QGraphicsRoundedRectItem* rect = new QGraphicsRoundedRectItem(0,0,750, 100,15,15);
        rect->setBrush(QColor::fromHsvF(QRandomGenerator::global()->generateDouble(),0.33,1));
        QString textBoxText;
        textBoxText += (category.getName() + '\n');
        //QGraphicsTextItem* catName = new QGraphicsTextItem(category.getName(),rect);

        if (category.empty()) {
            textBoxText += " - This Category Has No Tasks - ";
        } else {
           for (Task& task : category) {
               textBoxText += (((task.isChecked()) ? QChar(0x2612) : QChar(0x2610)) + ' ' + task.getName() + '\n');
               if (task.getDescription() != "") {
                   textBoxText += "\tDescription: "  + task.getDescription() + '\n';
               }
           }
        }

        QGraphicsTextItem* catName = new QGraphicsTextItem(textBoxText.trimmed(),rect);
        //rect->setAcceptedMouseButtons(Qt::MouseButtons(Qt::LeftButton));
        rect->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable);
        rect->setRect(0,0,750,catName->boundingRect().height() + 10,15,15);
        linear->addItem(rect);
        linear->setStretchFactor(rect, 1);
    }

    widgetLayout->addItem(linear);


    this->setLayout(widgetLayout);
    this->update();
}
