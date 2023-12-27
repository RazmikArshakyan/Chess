#include <game.h>
#include <button.h>
#include <QPixmap>
#include <king.h>
#include <QDebug>

Game::Game(QWidget* parent) : QGraphicsView(parent)
{
    game_scene = new QGraphicsScene();
    game_scene->setSceneRect(0, 0, 1400, 900);

    // Making of interface (view)
    setFixedSize(1400, 900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(game_scene);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBackgroundBrush(brush);
    piece_to_move = NULL;

    // Display turn
    turn_display = new QGraphicsTextItem();
    turn_display->setPos(width() / 2 - 100, 10);
    turn_display->setZValue(1);
    turn_display->setDefaultTextColor(Qt::white);
    turn_display->setFont(QFont("", 18));
    turn_display->setPlainText("Turn : White");

    // Display check
    check = new QGraphicsTextItem();
    check->setPos(width() / 2 - 100, 860);
    check->setZValue(4);
    check->setDefaultTextColor(Qt::red);
    check->setFont(QFont("", 18));
    check->setPlainText("Check!");
    check->setVisible(false);
    set_turn("White");

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void Game::resizeEvent(QResizeEvent* event)
{
    QGraphicsView::resizeEvent(event);

    QRectF newSceneRect(0, 0, viewport()->width(), viewport()->height());
    game_scene->setSceneRect(newSceneRect);

    setMinimumSize(viewport()->size());
    setMaximumSize(viewport()->size());

    turn_display->setPos(viewport()->width() / 2 - 100, 10);
    check->setPos(viewport()->width() / 2 - 100, viewport()->height() - 40);

    draw_chess_board();
}


void Game::change_turn()
{
    if (get_turn() == "White") {
        set_turn("Black");
    }
    else {
        set_turn("White");
    }
    turn_display->setPlainText("Turn : " + get_turn());
}

void Game::set_turn(QString val)
{
    turn = val;
}

QString Game::get_turn()
{
    return turn;
}

void Game::add_to_scene(QGraphicsItem* item)
{
    game_scene->addItem(item);
}

void Game::remove_from_scene(QGraphicsItem* item)
{
    game_scene->removeItem(item);
}

void Game::draw_dead_holder(int x, int y, QColor color)
{
    dead_holder = new QGraphicsRectItem(x, y, 300, 900);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    dead_holder->setBrush(brush);
    add_to_scene(dead_holder);
}

void Game::draw_chess_board()
{
    chess = new Board();
    draw_dead_holder(0, 0, Qt::lightGray);
    draw_dead_holder(1100, 0, Qt::lightGray);
    chess->draw_boxes(width() / 2 - 400, 50);
}

void Game::display_dead_white()
{
    int j = 0, k = 0;
    for (size_t i = 0, n = white_dead.size(); i < n; ++i) {
        if (j == 4) {
            k++, j = 0;
        }
        white_dead[i]->setPos(40 + 50 * j++, 100 + 50 * 2 * k);
    }
}

void Game::display_dead_black()
{
    int j = 0, k = 0;
    for (size_t i = 0, n = black_dead.size(); i < n; ++i) {
        if (j == 4) {
            k++, j = 0;
        }
        black_dead[i]->setPos(1140 + 50 * j++, 100 + 50 * 2 * k);
    }
}

void Game::place_in_dead_place(Piece* piece)
{
    if (piece->get_side() == "White") {
        white_dead.append(piece);
        King* g = dynamic_cast<King*>(piece);
        if (g) {
            check->setPlainText("Black Won");
            game_over();
        }
        display_dead_white();
    }
    else {
        black_dead.append(piece);
        King* g = dynamic_cast<King*>(piece);
        if (g) {
            check->setPlainText("White Won");
            game_over();
        }
        display_dead_black();
    }
    alive_piece.removeAll(piece);
}

void Game::display_main_menu()
{
    QGraphicsPixmapItem* wking = new QGraphicsPixmapItem();
    wking->setPixmap(QPixmap(":/wking.png"));
    wking->setPos(420, 170);
    add_to_scene(wking);
    list_g.append(wking);

    QGraphicsPixmapItem* bking = new QGraphicsPixmapItem();
    bking->setPixmap(QPixmap(":/bking.png"));
    bking->setPos(920, 170);
    add_to_scene(bking);
    list_g.append(bking);

    QGraphicsTextItem* title_text = new QGraphicsTextItem("<Chess>");
    QFont title_font("arial", 50);
    title_text->setFont(title_font);
    int xp = width() / 2 - title_text->boundingRect().width() / 2;
    int yp = 150;
    title_text->setPos(xp, yp);
    add_to_scene(title_text);
    list_g.append(title_text);

    Button* play_button = new Button("Play 1 v 1");
    int pxp = width() / 2 - play_button->boundingRect().width() / 2;
    int pyp = 300;
    play_button->setPos(pxp, pyp);
    connect(play_button, SIGNAL(clicked()), this, SLOT(start()));
    add_to_scene(play_button);
    list_g.append(play_button);

    Button* quit_button = new Button("Quit");
    int qxp = width() / 2 - quit_button->boundingRect().width() / 2;
    int qyp = 375;
    quit_button->setPos(qxp, qyp);
    connect(quit_button, SIGNAL(clicked()), this, SLOT(close()));
    add_to_scene(quit_button);
    draw_chess_board();
    list_g.append(quit_button);
}

void Game::game_over()
{
    set_turn("White");
    alive_piece.clear();
    chess->reset();
}

void Game::remove_all()
{
    QList<QGraphicsItem*> items_list = game_scene->items();
    for (size_t i = 0, n = items_list.size(); i < n; ++i) {
        if (items_list[i] != check) {
            remove_from_scene(items_list[i]);
        }
    }
}

void Game::start()
{
    qDebug();
    for(size_t i =0, n = list_g.size(); i < n; i++) {
         remove_from_scene(list_g[i]);
    }
    add_to_scene(turn_display);

    QGraphicsTextItem* white_piece = new QGraphicsTextItem();
    white_piece->setPos(70,10);
    white_piece->setZValue(1);
    white_piece->setDefaultTextColor(Qt::white);
    white_piece->setFont(QFont("",14));
    white_piece->setPlainText("White Piece");
    add_to_scene(white_piece);

    QGraphicsTextItem *black_piece = new QGraphicsTextItem();
    black_piece->setPos(1170,10);
    black_piece->setZValue(1);
    black_piece->setDefaultTextColor(Qt::black);
    black_piece->setFont(QFont("",14));
    black_piece->setPlainText("Black Piece");
    add_to_scene(black_piece);
    add_to_scene(check);
    chess->add_piece();
}

