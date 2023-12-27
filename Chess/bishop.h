#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>

class Bishop: public Piece
{
public:
    Bishop(QString team,QGraphicsItem *parent = 0);

    void set_image();
    void moves();
};

#endif
