#include <QWidget>
#include "src/board.h"

Board::Board(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout(this);

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            Cell* cell = &cells[row][col];
            new (cell) Cell(row, col);
            cell->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding));
            layout->addWidget(cell, row, col);

            connect(cell, &Cell::clicked, this, &Board::cell_clicked);
        }
    }
}

void Board::cell_clicked(int row, int col) {
    emit clicked(row, col);
}

Board::~Board() {
    delete layout;
}
