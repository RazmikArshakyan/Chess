#include <knight.h>
#include <game.h>

extern Game* game;

Knight::Knight(QString team, QGraphicsItem* parent)
    : Piece(team, parent)
{
    set_image();
}

void Knight::set_image()
{
    if (side == "White") {
        setPixmap(QPixmap(":/wknight.png"));
    }
    else {
        setPixmap(QPixmap(":/bknight.png"));
    }
}

void Knight::moves()
{
    int row = this->get_current_box()->row;
    int col = this->get_current_box()->col;
    QString team = this->get_side();

    // Up up left
    int i = row - 2;
    int j = col - 1;
    if (i >= 0 && j >= 0 && (game->coll[i][j]->get_piece_color() != team)) {
        location.append(game->coll[i][j]);
        if (location.last()->get_has_piece()) {
            location.last()->set_color(Qt::red);
        }
        else {
            location.last()->set_color(Qt::darkRed);
        }
    }

    // Up up right
    i = row - 2;
    j = col + 1;
    if(i >=0 && j<=7 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }

    // Down down left
    i = row + 2;
    j = col - 1;
    if(i <= 7 && j>=0 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }

    // Down down right
    i = row + 2;
    j = col + 1;
    if(i <=7 && j<=7 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }

    // Left left up
    i = row - 1;
    j = col - 2;
    if(i >=0 && j>=0 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }

    // Left left down
    i = row + 1;
    j = col - 2;
    if(i <=7 && j>=0 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }

    // Right right up
    i = row - 1;
    j = col + 2;
    if(i >=0 && j<=7 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }

    // Right right down
    i = row + 1;
    j = col +  2;
    if(i <=7 && j<=7 && (game->coll[i][j]->get_piece_color() != team) ) {
        location.append(game->coll[i][j]);
        if(location.last()->get_has_piece())
            location.last()->set_color(Qt::red);
        else
            location.last()->set_color(Qt::darkRed);
    }
}
