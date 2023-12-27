#include <rook.h>
#include <game.h>

extern Game* game;

Rook::Rook(QString team, QGraphicsItem* parent)
    : Piece(team, parent)
{
    set_image();
}

void Rook::set_image()
{
    if (side == "White") {
        setPixmap(QPixmap(":/wrook.png"));
    }
    else {
        setPixmap(QPixmap(":/brook.png"));
    }
}

void Rook::moves()
{
    location.clear();
    int row = this->get_current_box()->row;
    int col = this->get_current_box()->col;
    QString team = this->get_side();

    // For moving up
    for (int i = row - 1, j = col; i >= 0; --i) {
        if (game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else {
            location.append(game->coll[i][j]);
            if (box_setting(location.last())) {
                break;
            }
        }
    }

    // For moving down
    for (int i = row + 1, j = col; i <= 7; ++i) {
        if (game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else {
            location.append(game->coll[i][j]);
            if (box_setting(location.last())) {
                break;
            }
        }
    }

    // For moving left
    for (int i = row, j = col - 1; j >= 0; --j) {
        if (game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else {
            location.append(game->coll[i][j]);
            if (box_setting(location.last())) {
                break;
            }
        }
    }

    // For moving right
    for (int i = row, j = col + 1; j <= 7; ++j) {
        if (game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else {
            location.append(game->coll[i][j]);
            if (box_setting(location.last())) {
                break;
            }
        }
    }
}

