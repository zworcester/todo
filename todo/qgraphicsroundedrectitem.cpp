#include "qgraphicsroundedrectitem.h"

/*
    QGraphicsRoundedRectItem(int x, int y, int w, int h, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
   */

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent),
      rect{x,y,w,h},
      xRadius{xRadius},
      yRadius{yRadius}
{}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent),
      rect{rect},
      xRadius{xRadius},
      yRadius{yRadius}
{}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent),
      rect{rect},
      xRadius{xRadius},
      yRadius{yRadius}
{}

QRectF QGraphicsRoundedRectItem::boundingRect() const
{
    return rect;
}

void QGraphicsRoundedRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->drawRoundedRect(rect,xRadius,yRadius);
}
