#include <bishop.h>
#include <QDebug>
#include <game.h>

extern Game* game;

Bishop::Bishop(QString team, QGraphicsItem* parent) : Piece(team, parent)
{
    set_image();
}

void Bishop::set_image()
{
    if (side == "White") {
        setPixmap(QPixmap(":/wbishop.png"));
    }
    else {
        setPixmap(QPixmap(":/bbishop.png"));
    }
}

void Bishop::moves()
{
    location.clear();
    int row = get_current_box()->row;
    int col = get_current_box()->col;
    QString team = get_side();

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
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

    for (int i = row - 1, j = col + 1; i >= 0 && j <= 7; --i, ++j) {
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

    for (int i = row + 1, j = col + 1; i <= 7 && j <= 7; ++i, ++j) {
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

    for (int i = row + 1, j = col - 1; i <= 7 && j >= 0; ++i, --j) {
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
