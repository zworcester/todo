#ifndef QGRAPHICSROUNDEDRECTITEM_H
#define QGRAPHICSROUNDEDRECTITEM_H

#include <QGraphicsItem>
#include <QAbstractGraphicsShapeItem>
#include <QGraphicsLayoutItem>
#include <QObject>
#include <QWidget>
#include <QPainter>

class QGraphicsRoundedRectItem : public QGraphicsItem, public QGraphicsLayoutItem
{
public:
    QGraphicsRoundedRectItem(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(QGraphicsItem* parent = nullptr);

    void setRect(const QRectF& rect, qreal xRadius, qreal yRadius);
    void setRect(qreal x, qreal y, qreal width, qreal height, qreal xRadius, qreal yRadius);
    void setRect(const QRectF& rect);
    void setRect(qreal x, qreal y, qreal width, qreal height);

    QRectF getRect() const;
    qreal getXRadius() const;
    qreal getYRadius() const;

    QPen pen() const;
    QBrush brush() const;
    void setPen(QPen pen);
    void setBrush(QBrush brush);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
    virtual QSizeF sizeHint(Qt::SizeHint which, const QSizeF& constraint = QSizeF()) const override;
    virtual void setGeometry(const QRectF& rect) override;
private:
    QPen _pen;
    QBrush _brush;

    QRectF rect;
    qreal xRadius;
    qreal yRadius;
};

#endif // QGRAPHICSROUNDEDRECTITEM_H
