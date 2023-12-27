#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>

class Knight : public Piece
{
public:
    Knight(QString team, QGraphicsItem* parent = 0);

    void set_image();
    void moves();
};

#endif
