#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsRectItem>
#include <piece.h>

class Board
{
public:
    Board();

    void draw_boxes(int x, int y);
    void set_up_white();
    void set_up_black();
    void reset();
    void add_piece();

private:
    QList<Piece*> white;
    QList<Piece*> black;
};

#endif
