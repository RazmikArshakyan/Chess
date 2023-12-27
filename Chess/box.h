#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QBrush>
//#include <piece.h>
#include <QGraphicsSceneMouseEvent>

class Piece;

class CBox : public QGraphicsRectItem
{
public:
    CBox(QGraphicsItem* parent = 0);
    ~CBox();
    int row;
    int col;
    Piece* curr_piece;

    void set_piece_color(QString val);
    QString get_piece_color();
    bool get_has_piece();
    void set_has_piece(bool val, Piece* piece = 0);
    void reset_original_color();
    void set_original_color(QColor val);
    void check_for_check();
    void place_piece(Piece* piece);
    void set_color(QColor val);
    void mousePressEvent(QGraphicsSceneMouseEvent* event);

private:
    bool has_piece;
    QBrush brush;
    QColor original_color;
    QString piece_color;
};

#endif
