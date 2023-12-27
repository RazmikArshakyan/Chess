#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>

class Queen : public Piece
{
public:
    Queen(QString team, QGraphicsItem* parent = 0);

    void set_image();
    void moves();
};

#endif
