#include <king.h>
#include <game.h>
#include <pawn.h>

extern Game* game;

King::King(QString team, QGraphicsItem* parent) : Piece(team, parent)
{
    set_image();
}

void King::set_image()
{
    if (side == "White") {
        setPixmap(QPixmap(":/wking.png"));
    }
    else {
        setPixmap(QPixmap(":/bking.png"));
    }
}

void King::moves()
{
    location.clear();
    int row = get_current_box()->row;
    int col = get_current_box()->col;
    QString team = get_side();

    if (col > 0 && row > 0 && !(game->coll[row - 1][col - 1]->get_piece_color() == team )) {
        location.append(game->coll[row - 1][col - 1]);
        game->coll[row - 1][col - 1]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (col < 7 && row > 0 && !(game->coll[row - 1][col + 1]->get_piece_color() == team)) {
        location.append(game->coll[row - 1][col + 1]);
        game->coll[row - 1][col + 1]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (row > 0 && !(game->coll[row - 1][col]->get_piece_color() == team)) {
        location.append(game->coll[row - 1][col]);
        game->coll[row - 1][col]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (row < 7 && !(game->coll[row + 1][col]->get_piece_color() == team)) {
        location.append(game->coll[row + 1][col]);
        game->coll[row + 1][col]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (col > 0 && !(game->coll[row][col - 1]->get_piece_color() == team )) {
        location.append(game->coll[row][col - 1]);
        game->coll[row][col - 1]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (col < 7 && !(game->coll[row][col + 1]->get_piece_color() == team)) {
        location.append(game->coll[row][col + 1]);
        game->coll[row][col + 1]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (col > 0 && row < 7 && !(game->coll[row + 1][col - 1]->get_piece_color() == team)) {
        location.append(game->coll[row + 1][col - 1]);
        game->coll[row + 1][col - 1]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
    if (col < 7 && row < 7 && !(game->coll[row + 1][col + 1]->get_piece_color() == team)) {
        location.append(game->coll[row + 1][col + 1]);
        game->coll[row + 1][col + 1]->set_color(Qt::darkRed);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
    }
}

void King::find_unsafe_location()
{
    QList<Piece*> p_list = game->alive_piece;
    for (size_t i = 0, n = p_list.size(); i < n; ++i) {
        if (p_list[i]->get_side() != this->get_side()) {
            QList<CBox*> b_list = p_list[i]->move_location();
            for (size_t j = 0, n = b_list.size(); j < n; ++j) {
                Pawn* c = dynamic_cast<Pawn*>(p_list[i]);
                if (c) {
                    continue;
                }
                for (size_t k = 0, n = location.size(); k < n; ++k) {
                    if (b_list[j] == location[k]) {
                        location[k]->set_color(Qt::blue);
                    }
                }
            }
        }
    }
}
