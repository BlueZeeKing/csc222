#include <QWidget>
#include "src/board.h"

Board::Board(QWidget *parent) : QWidget(parent) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            Cell* cell = &cells[row][col];
            new (cell) Cell(row, col, this);

            connect(cell, &Cell::clicked, this, &Board::cell_clicked);
        }
    }
}

void Board::cell_clicked(int row, int col) {
    emit clicked(row, col);
}
