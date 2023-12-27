#include <queen.h>
#include <game.h>

extern Game* game;

Queen::Queen(QString team, QGraphicsItem* parent)
    : Piece(team, parent)
{
    set_image();
}

void Queen::set_image()
{
    if (side == "White")
        setPixmap(QPixmap(":/wqueen.png"));
    else
        setPixmap(QPixmap(":/bqueen.png"));
}

void Queen::moves()
{
    location.clear();
    int row = this->get_current_box()->row;
    int col = this->get_current_box()->col;
    QString team = this->get_side();

    //For up
    for(int i = row-1, j = col; i >= 0 ; i--) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last()))
                break;
        }
    }

    //For Down
    for(int i = row+1,j = col; i <= 7 ; i++) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last())){
                break;
            }
        }
    }

    //For left
    for(int i = row,j = col-1; j >= 0 ; j--) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last()))
                break;
        }
    }

    //For Right
    for(int i = row,j = col+1; j <= 7 ; j++)
    {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last()))
                break;
        }

    }

    //For upper Left
    for(int i = row-1,j = col-1; i >= 0 && j >=0; i--,j--) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last()) ){
                break;
            }
        }
    }

    //For upper right
    for(int i = row-1,j = col+1; i >= 0 && j <= 7; i--,j++) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last())){
                break;
            }
        }
    }

    //For downward right
    for(int i = row+1,j = col+1; i <= 7 && j <= 7; i++,j++) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last())){
                break;
            }
        }
    }

    //For downward left
    for(int i = row+1,j = col-1; i <= 7 && j >= 0; i++,j--) {
        if(game->coll[i][j]->get_piece_color() == team) {
            break;
        }
        else
        {
            location.append(game->coll[i][j]);
            if(box_setting(location.last())){
                break;
            }
        }
    }
}

