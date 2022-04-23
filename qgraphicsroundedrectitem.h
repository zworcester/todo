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
 * ----------------------------------------------------
 * Description:
 * QGraphicsRoundedRectItem is a class used to build the rounded rectangles graphics.
 * It contain several different constructors to set the values and is used to
 * setGraphicsItem. It has a deconstuctor. It has functions for the boundary
 * rectangle, paint the rounded rectangle and more. It has return functions to
 * get private variables such as _pen, _brush, rect, xRadius, yRadius
 */
#ifndef QGRAPHICSROUNDEDRECTITEM_H
#define QGRAPHICSROUNDEDRECTITEM_H

#include <QGraphicsItem>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsLayoutItem>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QDebug>

class QGraphicsRoundedRectItem : public QGraphicsItem, public QGraphicsLayoutItem
{
public:
    QGraphicsRoundedRectItem(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(QGraphicsItem* parent = nullptr);
    ~QGraphicsRoundedRectItem() {}

    // Set or changed rect - applies to all setRecs
    void setRect(const QRectF& rect, qreal xRadius, qreal yRadius);
    void setRect(qreal x, qreal y, qreal width, qreal height, qreal xRadius, qreal yRadius);
    void setRect(const QRectF& rect);
    void setRect(qreal x, qreal y, qreal width, qreal height);

    // Returns rect
    QRectF getRect() const;
    // Returns xRadius
    qreal getXRadius() const;
    // Returns yRadius
    qreal getYRadius() const;
    // Returns pen
    QPen pen() const;
    // Returns brush
    QBrush brush() const;

    // Set or changed pen
    void setPen(QPen pen);
    // Set or changed Brush
    void setBrush(QBrush brush);
    // Returns size of bounding rectangle
    QRectF boundingRect() const override;
    // Paints the rectangle onto a scene
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    // Return size of hint for a rounded rectangle
    virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF& constraint = QSizeF()) const override;
    // Set or change the size of the rectangle
    virtual void setGeometry(const QRectF& rect) override;

private:
    QPen _pen;
    QBrush _brush;

    QRectF rect;
    qreal xRadius;
    qreal yRadius;
};

#endif // QGRAPHICSROUNDEDRECTITEM_H
