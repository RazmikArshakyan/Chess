#include <pawn.h>
#include <game.h>
#include <typeinfo>
#include <king.h>

extern Game* game;

Pawn::Pawn(QString team, QGraphicsItem* parent)
    : Piece(team, parent)
{
    set_image();
}

void Pawn::set_image()
{
    if(side == "White")
        setPixmap(QPixmap(":/wpawn.png"));
    else
        setPixmap(QPixmap(":/bpawn.png"));
}

void Pawn::moves()
{
    location.clear();
    int row = this->get_current_box()->row;
    int col = this->get_current_box()->col;

    if(this->get_side() == "White")  {
        if(col > 0 && row > 0 && game->coll[row-1][col-1]->get_piece_color() == "Black") {
            location.append(game->coll[row-1][col-1]);
            box_setting(location.last());
        }
        if(col < 7 && row > 0 && game->coll[row-1][col+1]->get_piece_color() == "Black") {
            location.append(game->coll[row-1][col+1]);
            box_setting(location.last());
        }
        if(row>0 && (!game->coll[row-1][col]->get_has_piece())) {
            location.append(game->coll[row-1][col]);
            box_setting(location.last());
            if(first_move && !game->coll[row-2][col]->get_has_piece()){
                location.append(game->coll[row-2][col]);
                box_setting(location.last());
            }
        }

    }
    else{
        if(col > 0 && row < 7 && game->coll[row+1][col-1]->get_piece_color() == "White") {
            location.append(game->coll[row+1][col-1]);
            box_setting(location.last());
        }
        if(col < 7 && row <  7 && game->coll[row+1][col+1]->get_piece_color() == "White") {
            location.append(game->coll[row+1][col+1]);
            box_setting(location.last());
        }
        if(row<7 && (!game->coll[row+1][col]->get_has_piece())) {
            location.append(game->coll[row+1][col]);
            box_setting(location.last());
            if(first_move && !game->coll[row+2][col]->get_has_piece()){
                location.append(game->coll[row+2][col]);
                box_setting(location.last());
            }

        }
    }
}
