#include <piece.h>
#include <king.h>
#include <game.h>
#include <QDebug>

extern Game* game;

Piece::Piece(QString team, QGraphicsItem* parent)
    : QGraphicsPixmapItem(parent)
{
    side = team;
    is_placed = true;
    first_move = true;
}

QList<CBox*> Piece::move_location()
{
    return location;
}

bool Piece::box_setting(CBox* box)
{
    if (box->get_has_piece()) {
        King* p = dynamic_cast<King*>(location.last()->curr_piece);
        if (p) {
            box->set_color(Qt::blue);
        }
        else {
            box->set_color(Qt::red);
        }
        return true;
    }
    else {
        location.last()->set_color(Qt::darkRed);
    }
    return false;
}

void Piece::decolor()
{
    for (size_t i = 0, n = location.size(); i < n; ++i) {
        location[i]->reset_original_color();
    }
}

bool Piece::get_is_placed()
{
    return is_placed;
}

void Piece::set_is_placed(bool val)
{
    is_placed = val;
}

QString Piece::get_side()
{
    return side;
}

void Piece::set_side(QString val)
{
    side = val;
}

CBox* Piece::get_current_box()
{
    return curr_box;
}

void Piece::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (this == game->piece_to_move) {
        game->piece_to_move->get_current_box()->reset_original_color();
        game->piece_to_move->decolor();
        game->piece_to_move = NULL;
        return;
    }

    if ((!get_is_placed()) || ((game->get_turn() != this->get_side()) && (!game->piece_to_move))) {
        return;
    }

    if (!game->piece_to_move) {
        game->piece_to_move = this;
        game->piece_to_move->get_current_box()->set_color(Qt::red);
        game->piece_to_move->moves();
    }
    else if (this->get_side() != game->piece_to_move->get_side()) {
        this->get_current_box()->mousePressEvent(event);
    }
}

void Piece::set_current_box(CBox* box)
{
    curr_box = box;
}
