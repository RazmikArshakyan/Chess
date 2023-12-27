#include <board.h>
#include <box.h>
#include <game.h>
#include <queen.h>
#include <rook.h>
#include <pawn.h>
#include <king.h>
#include <knight.h>
#include <bishop.h>

extern Game* game;

Board::Board()
{
    set_up_white();
    set_up_black();
}

void Board::draw_boxes(int x, int y)
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            CBox* box = new CBox();
            game->coll[i][j] = box;
            box->row = i;
            box->col = j;
            box->setPos(x + 100 * j, y + 100 * i);
            if ((i + j) % 2 == 0) {
                box->set_original_color(QColorConstants::Svg::bisque);
            }
            else {
                box->set_original_color(QColorConstants::Svg::peru);
            }
            game->add_to_scene(box);
        }
    }
}

void Board::set_up_white()
{
    Piece *piece;
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("White");
        white.append(piece);
    }

    piece = new Rook("White");
    white.append(piece);
    piece = new Knight("White");
    white.append(piece);
    piece = new Bishop("White");
    white.append(piece);
    piece = new Queen("White");
    white.append(piece);
    piece = new King("White");
    white.append(piece);
    piece = new Bishop("White");
    white.append(piece);
    piece = new Knight("White");
    white.append(piece);
    piece = new Rook("White");
    white.append(piece);
}

void Board::set_up_black()
{
    Piece *piece;
    piece = new Rook("Black");
    black.append(piece);
    piece = new Knight("Black");
    black.append(piece);
    piece = new Bishop("Black");
    black.append(piece);
    piece = new Queen("Black");
    black.append(piece);
    piece = new King("Black");
    black.append(piece);
    piece = new Bishop("Black");
    black.append(piece);
    piece = new Knight("Black");
    black.append(piece);
    piece = new Rook("Black");
    black.append(piece);
    for(int i = 0; i < 8; i++) {
        piece = new Pawn("Black");
        black.append(piece);
    }
}

void Board::reset()
{
    int k = 0; int h = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            CBox *box =game->coll[i][j];
            box->set_has_piece(false);
            box->set_piece_color("None");
            box->curr_piece = NULL;
            if(i < 2) {
                box->place_piece(black[k]);
                black[k]->set_is_placed(true);
                black[k]->first_move = true;
                game->alive_piece.append(black[k++]);
            }
            if(i > 5) {
                box->place_piece(white[h]);
                white[h]->set_is_placed(true);
                white[h]->first_move = true;
                game->alive_piece.append(white[h++]);
            }
        }
    }
}

void Board::add_piece()
{
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            CBox* box = game->coll[i][j];
            if (i < 2) {
                static int k;
                box->place_piece(black[k]);
                game->alive_piece.append(black[k]);
                game->add_to_scene(black[k++]);
            }
            if (i > 5) {
                static int h;
                box->place_piece(white[h]);
                game->alive_piece.append(white[h]);
                game->add_to_scene(white[h++]);
            }
        }
    }
}

