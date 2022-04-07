#include "qgraphicsroundedrectitem.h"

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect{x,y,w,h},
      xRadius{xRadius},
      yRadius{yRadius}
{
    this->setGraphicsItem(this);
}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect{rect},
      xRadius{xRadius},
      yRadius{yRadius}
{
    this->setGraphicsItem(this);
}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect{rect},
      xRadius{xRadius},
      yRadius{yRadius}
{
    this->setGraphicsItem(this);
}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect(QRectF(0,0,100,100)),
      xRadius(50),
      yRadius(50)
{
    this->setGraphicsItem(this);
}

void QGraphicsRoundedRectItem::setRect(const QRectF& rect, qreal xRadius, qreal yRadius)
{
    this->rect = rect;
    this->xRadius = xRadius;
    this->yRadius = yRadius;
    return;
}

void QGraphicsRoundedRectItem::setRect(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius)
{
    this->rect = QRectF(x,y,w,h);
    this->xRadius = xRadius;
    this->yRadius = yRadius;
    return;
}

void QGraphicsRoundedRectItem::setRect(const QRectF& rect)
{
    this->rect = rect;
    return;
}

void QGraphicsRoundedRectItem::setRect(qreal x, qreal y, qreal w, qreal h)
{
    this->rect = QRectF(x,y,w,h);
    return;
}

QRectF QGraphicsRoundedRectItem::getRect() const
{
    return rect;
}

qreal QGraphicsRoundedRectItem::getXRadius() const
{
    return xRadius;
}

qreal QGraphicsRoundedRectItem::getYRadius() const
{
    return yRadius;
}

QRectF QGraphicsRoundedRectItem::boundingRect() const
{
    return rect;
}

void QGraphicsRoundedRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawRoundedRect(rect,xRadius,yRadius);
}

QSizeF QGraphicsRoundedRectItem::sizeHint(Qt::SizeHint which, const QSizeF& constraint) const
{
    Q_UNUSED(which);
    Q_UNUSED(constraint);

    return boundingRect().size();
}

void QGraphicsRoundedRectItem::setGeometry(const QRectF& rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(rect);
    setPos(rect.topLeft());
}

QPen QGraphicsRoundedRectItem::pen() const
{
    return this->_pen;
}

QBrush QGraphicsRoundedRectItem::brush() const
{
    return this->_brush;
}

void QGraphicsRoundedRectItem::setPen(QPen pen)
{
    this->_pen = pen;

    return;
}

void QGraphicsRoundedRectItem::setBrush(QBrush brush)
{
    this->_brush = brush;

    return;
}
