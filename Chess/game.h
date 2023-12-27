#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <board.h>
#include <box.h>

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent = 0);
    CBox* coll[8][8];
    QGraphicsTextItem* check;
    QList<Piece*> alive_piece;
    Piece* piece_to_move;

    void change_turn();
    void set_turn(QString val);
    QString get_turn();
    void add_to_scene(QGraphicsItem* item);
    void remove_from_scene(QGraphicsItem* item);
    void draw_dead_holder(int x, int y, QColor color);
    void draw_chess_board();
    void display_dead_white();
    void display_dead_black();
    void place_in_dead_place(Piece* piece);
    void display_main_menu();
    void game_over();
    void remove_all();
protected:
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void start();

private:
    QGraphicsScene* game_scene;
    QList<Piece*> white_dead;
    QList<Piece*> black_dead;
    QGraphicsRectItem* dead_holder;
    QString turn;
    Board* chess;
    QList<QGraphicsItem*> list_g;
    QGraphicsTextItem* turn_display;
};

#endif
