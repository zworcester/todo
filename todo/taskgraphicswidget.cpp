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


    testRec->setPen(Qt::NoPen);
    testRec->setBrush(Qt::darkGreen);
    testRec2->setBrush(Qt::red);
    linear->addItem(testRec);
    linear->setStretchFactor(testRec, 1);
    linear->setAlignment(testRec, Qt::AlignLeft);
    linear->addItem(testRec2);
    linear->setStretchFactor(testRec2, 1);
    linear->setAlignment(testRec2, Qt::AlignLeft);

    widgetLayout->addItem(linear);

    this->setLayout(widgetLayout);
    this->show();
}
