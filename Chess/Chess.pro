QT += core gui

greaterThan(QT_MAJOR_VERSION, 5) : QT += widgets

TARGET = Chess
TEMPLATE = app

SOURCES += \
    bishop.cpp \
    board.cpp \
    box.cpp \
    button.cpp \
    game.cpp \
    king.cpp \
    knight.cpp \
    main.cpp \
    pawn.cpp \
    piece.cpp \
    queen.cpp \
    rook.cpp

HEADERS += \
    bishop.h \
    board.h \
    box.h \
    button.h \
    game.h \
    king.h \
    knight.h \
    pawn.h \
    piece.h \
    queen.h \
    rook.h

DISTFILES += \
    bpawn.png \
    bqueen.png \
    brook.png \
    wbishop.png \
    wking.png \
    wknight.png \
    wpawn.png \
    wqueen.png \
    wrook.png

FORMS +=

RESOURCES += \
    resources.qrc
