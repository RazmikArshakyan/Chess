#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

#include "button.h"

Button::Button(QString name, QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor((Qt::darkRed));
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    int xp = rect().width() / 2 - text->boundingRect().width() / 2;
    int yp = rect().height() / 2 - text->boundingRect().height() / 2;
    text->setPos(xp, yp);
    text->setDefaultTextColor(Qt::white);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event) {
        emit clicked();
    }
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
    if (event) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::red);
        setBrush(brush);
    }
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
    if (event) {
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(Qt::darkRed);
        setBrush(brush);
    }
}
