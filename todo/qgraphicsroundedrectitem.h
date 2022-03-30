#ifndef QGRAPHICSROUNDEDRECTITEM_H
#define QGRAPHICSROUNDEDRECTITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <QPainter>

class QGraphicsRoundedRectItem : public QGraphicsItem
{
public:
    QGraphicsRoundedRectItem(qreal x, qreal y, qreal w, qreal h, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRectF& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(const QRect& rect, qreal xRadius, qreal yRadius, QGraphicsItem* parent=nullptr);
    QGraphicsRoundedRectItem(QGraphicsItem* parent = nullptr);

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr) override;
private:
    QRectF rect;
    qreal xRadius;
    qreal yRadius;
};

#endif // QGRAPHICSROUNDEDRECTITEM_H
