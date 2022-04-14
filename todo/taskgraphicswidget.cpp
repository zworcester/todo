#include "taskgraphicswidget.h"

TaskGraphicsWidget::TaskGraphicsWidget(QGraphicsWidget* parent)
    :
      QGraphicsWidget(parent)
{
    QGraphicsLinearLayout* widgetLayout = new QGraphicsLinearLayout(Qt::Vertical);
    QGraphicsLinearLayout* linear = new QGraphicsLinearLayout(widgetLayout);
    linear->setOrientation(Qt::Vertical);
    QGraphicsRoundedRectItem* testRec = new QGraphicsRoundedRectItem(0,0,100,100,15,15);
    QGraphicsRoundedRectItem* testRec2 = new QGraphicsRoundedRectItem(0,0,100,100,15,15);
    QGraphicsRoundedRectItem* testRec3 = new QGraphicsRoundedRectItem(0,0,100,100,15,15);


    testRec->setBrush(Qt::red);
    testRec2->setBrush(Qt::yellow);
    testRec3->setBrush(Qt::darkGreen);
    linear->addItem(testRec);
    linear->setStretchFactor(testRec, 1);
    linear->addItem(testRec2);
    linear->setStretchFactor(testRec2, 1);
    linear->addItem(testRec3);
    linear->setStretchFactor(testRec3, 1);

    widgetLayout->addItem(linear);

    this->setLayout(widgetLayout);
    this->show();
}
