/* ----------------------------------------------------
 * Filename: qgraphicsroundedrectitem.h
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
#include "qgraphicsroundedrectitem.h"

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect(x,y,w,h),
      xRadius(xRadius),
      yRadius(yRadius)
{
    this->setGraphicsItem(this);
}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect(rect),
      xRadius(xRadius),
      yRadius(yRadius)
{
    this->setGraphicsItem(this);
}

QGraphicsRoundedRectItem::QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent)
    :
      QGraphicsItem(parent), QGraphicsLayoutItem(),
      rect(rect),
      xRadius(xRadius),
      yRadius(yRadius)
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

// Set or changed rect
void QGraphicsRoundedRectItem::setRect(const QRectF& rect, qreal xRadius, qreal yRadius)
{
    this->rect = rect;
    this->xRadius = xRadius;
    this->yRadius = yRadius;
    return;
}

// Set or changed rect
void QGraphicsRoundedRectItem::setRect(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius)
{
    this->rect = QRectF(x,y,w,h);
    this->xRadius = xRadius;
    this->yRadius = yRadius;
    return;
}

// Set or changed rect
void QGraphicsRoundedRectItem::setRect(const QRectF& rect)
{
    this->rect = rect;
    return;
}

// Set or changed rect
void QGraphicsRoundedRectItem::setRect(qreal x, qreal y, qreal w, qreal h)
{
    this->rect = QRectF(x,y,w,h);
    return;
}

// Returns rect
QRectF QGraphicsRoundedRectItem::getRect() const
{
    return rect;
}

// Returns xRadius
qreal QGraphicsRoundedRectItem::getXRadius() const
{
    return xRadius;
}

// Returns yRadius
qreal QGraphicsRoundedRectItem::getYRadius() const
{
    return yRadius;
}

// Returns size of bounding rectangle
QRectF QGraphicsRoundedRectItem::boundingRect() const
{
    return rect;
}

// Paints the rectangle onto a scene
void QGraphicsRoundedRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(this->pen());
    painter->setBrush(this->brush());
    painter->drawRoundedRect(rect,xRadius,yRadius);
}

// Return size of hint for a rounded rectangle
QSizeF QGraphicsRoundedRectItem::sizeHint(Qt::SizeHint which, const QSizeF& constraint) const
{
    Q_UNUSED(which);
    Q_UNUSED(constraint);

    return boundingRect().size();
}

// Set or change the size of the rectangle
void QGraphicsRoundedRectItem::setGeometry(const QRectF& rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(rect);
    setPos(rect.topLeft());
}

// Returns pen
QPen QGraphicsRoundedRectItem::pen() const
{
    return this->_pen;
}

// Returns brush
QBrush QGraphicsRoundedRectItem::brush() const
{
    return this->_brush;
}

// Set or changed pen
void QGraphicsRoundedRectItem::setPen(QPen pen)
{
    this->_pen = pen;

    return;
}

// Set or changed Brush
void QGraphicsRoundedRectItem::setBrush(QBrush brush)
{
    this->_brush = brush;

    return;
}
