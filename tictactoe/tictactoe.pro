TEMPLATE = app
TARGET = tictactoe

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += src/main.cpp src/window.cpp src/cell.cpp src/board.cpp
HEADERS += src/window.h src/cell.h src/board.h
