#ifndef KING_H
#define KING_H

#include <piece.h>

class King : public Piece
{
public:
    King(QString team, QGraphicsItem* parent = 0);

    void set_image();
    void find_unsafe_location();
    void moves();
};

#endif
