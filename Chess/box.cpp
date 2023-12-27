#include <box.h>
#include <game.h>
#include <king.h>
#include <QDebug>

extern Game* game;

CBox::CBox(QGraphicsItem* parent)
    : QGraphicsRectItem(parent)
{
    setRect(0, 0, 100, 100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    set_has_piece(false);
    set_piece_color("None");
    curr_piece = NULL;
}

CBox::~CBox()
{
    delete this;
}

void CBox::set_piece_color(QString val)
{
    piece_color = val;
}

QString CBox::get_piece_color()
{
    return piece_color;
}

bool CBox::get_has_piece()
{
    return has_piece;
}

void CBox::set_has_piece(bool val, Piece* piece)
{
    has_piece = val;
    if (val) {
        set_piece_color(piece->get_side());
    }
    else
        set_piece_color("None");
}

void CBox::reset_original_color()
{
    set_color(original_color);
}

void CBox::set_original_color(QColor val)
{
    original_color = val;
    set_color(original_color);
}

void CBox::check_for_check()
{
    int c = 0;
    QList<Piece*> p_list = game->alive_piece;
    for (size_t i = 0, n = p_list.size(); i < n; ++i) {
        King* p = dynamic_cast<King*>(p_list[i]);
        if (p) {
            continue;
        }
        p_list[i]->moves();
        p_list[i]->decolor();

        QList<CBox*> b_list = p_list[i]->move_location();
        for (size_t j = 0, n = b_list.size(); j < n; ++j) {
            King* p = dynamic_cast<King*>(b_list[j]->curr_piece);
            if (p) {
                if (p->get_side() == p_list[i]->get_side()) {
                    continue;
                }
                b_list[j]->set_color(Qt::blue);
                p_list[i]->get_current_box()->set_color(Qt::darkRed);
                if (!game->check->isVisible()) {
                    game->check->setVisible(true);
                }
                else {
                    b_list[j]->reset_original_color();
                    p_list[i]->get_current_box()->reset_original_color();
                    game->game_over();
                }
                ++c;
            }
        }
    }

    if (!c) {
        game->check->setVisible(false);
        for (size_t i = 0, n = p_list.size(); i < n; ++i) {
            p_list[i]->get_current_box()->reset_original_color();
        }
    }
}

void CBox::place_piece(Piece* piece)
{
    piece->setPos(x() + 50 - piece->pixmap().width() / 2, y() + 50 - piece->pixmap().width() / 2);
    piece->set_current_box(this);
    set_has_piece(true, piece);
    curr_piece = piece;
}

void CBox::set_color(QColor val)
{
    brush.setColor(val);
    setBrush(val);
}

void CBox::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (curr_piece == game->piece_to_move && curr_piece) {
        curr_piece->mousePressEvent(event);
        return;
    }

    if (game->piece_to_move) {
        if (this->get_piece_color() == game->piece_to_move->get_side()) {
            return;
        }
        QList<CBox*> mov_loc = game->piece_to_move->move_location();
        int check = 0;
        for (size_t i = 0, n = mov_loc.size(); i < n; ++i) {
            if (mov_loc[i] == this) {
                ++check;
            }
        }

        if (check == 0) {
            return;
        }

        game->piece_to_move->decolor();
        game->piece_to_move->first_move = false;

        if (this->get_has_piece()) {
            this->curr_piece->set_is_placed(false);
            this->curr_piece->set_current_box(NULL);
            game->place_in_dead_place(this->curr_piece);
        }

        game->piece_to_move->get_current_box()->set_has_piece(false);
        game->piece_to_move->get_current_box()->curr_piece = NULL;
        game->piece_to_move->get_current_box()->reset_original_color();
        place_piece(game->piece_to_move);

        game->piece_to_move = NULL;
        game->change_turn();
        check_for_check();
    }
    else if (this->get_has_piece()) {
        this->curr_piece->mousePressEvent(event);
    }
}
