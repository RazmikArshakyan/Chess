#ifndef PIECE_H
#define PIECE_H

#include <QGraphicsPixmapItem>
#include <box.h>
#include <QGraphicsSceneMouseEvent>

class CBox;

class Piece : public QGraphicsPixmapItem
{
public:
    Piece(QString team = " ", QGraphicsItem* parent = 0);
    bool first_move;

    QList <CBox*> move_location();
    bool box_setting(CBox* box);
    void decolor();
    virtual void moves() = 0;
    bool get_is_placed();
    void set_is_placed(bool val);
    QString get_side();
    void set_side(QString val);
    virtual void set_image() = 0;
    CBox* get_current_box();
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void set_current_box(CBox* box);

protected:
    bool is_placed;
    CBox* curr_box;
    QString side;
    QList <CBox*> location;
};

#endif
