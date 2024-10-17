#include "src/cell.h"
#include "qpushbutton.h"

Cell::Cell(int row, int col, QWidget *parent): QPushButton(parent) {
    this->row = row; 
    this->col = col; 

    connect(this, &QPushButton::clicked, this, &Cell::button_clicked);

    set_state(CellState::NONE);
}

Cell::Cell(): QPushButton() {
    this->row = 0; 
    this->col = 0; 

    connect(this, &QPushButton::clicked, this, &Cell::button_clicked);

    set_state(CellState::NONE);
}

void Cell::set_state(CellState state) {
    this->state = state;
    switch (state) {
    case X:
        setText("X");
        break;
    case O:
        setText("O");
        break;
    case NONE:
        setText(" ");
        break;
    }
}

CellState Cell::get_state() {
    return state;
}

void Cell::button_clicked(bool _) {
    emit clicked(row, col);
}
