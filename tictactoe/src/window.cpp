#include "src/window.h"
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>

Window::Window(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout(this);
    is_x_turn = true;

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            Cell* cell = &cells[row][col];
            new (cell) Cell(row, col);
            cell->setSizePolicy(QSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed));
            layout->addWidget(cell, row, col);

            connect(cell, &Cell::clicked, this, &Window::process_move);
        }
    }
}

void Window::process_move(int row, int col) {
    if (cells[row][col].get_state() != CellState::NONE || is_tie() || winner() != CellState::NONE) {
        return; 
    }

    if (is_x_turn) {
        update_state(row, col, CellState::X);
        is_x_turn = false;
    } else {
        update_state(row, col, CellState::O);
        is_x_turn = true;
    }
}

void Window::update_state(int row, int col, CellState new_state) {
    cells[row][col].set_state(new_state);
}

bool Window::is_tie() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (cells[row][col].get_state() == CellState::NONE) {
                return false;
            }
        }
    }

    return true;
}

CellState Window::winner() {
    if (cells[0][0].get_state() != CellState::NONE && cells[0][0].get_state() == cells[0][1].get_state() && cells[0][0].get_state() == cells[0][2].get_state()) {
        return cells[0][0].get_state();
    } else if (cells[1][0].get_state() != CellState::NONE && cells[1][0].get_state() == cells[1][1].get_state() && cells[1][0].get_state() == cells[1][2].get_state()) {
        return cells[1][0].get_state();
    } else if (cells[2][0].get_state() != CellState::NONE && cells[2][0].get_state() == cells[2][1].get_state() && cells[2][0].get_state() == cells[2][2].get_state()) {
        return cells[2][0].get_state();
    } else if (cells[0][0].get_state() != CellState::NONE && cells[0][0].get_state() == cells[1][0].get_state() && cells[0][0].get_state() == cells[2][0].get_state()) {
        return cells[0][0].get_state();
    } else if (cells[0][1].get_state() != CellState::NONE && cells[0][1].get_state() == cells[1][1].get_state() && cells[0][1].get_state() == cells[2][1].get_state()) {
        return cells[0][1].get_state();
    } else if (cells[0][2].get_state() != CellState::NONE && cells[0][2].get_state() == cells[1][2].get_state() && cells[0][2].get_state() == cells[2][2].get_state()) {
        return cells[0][2].get_state();
    } else if (cells[0][0].get_state() != CellState::NONE && cells[0][0].get_state() == cells[1][1].get_state() && cells[0][0].get_state() == cells[2][2].get_state()) {
        return cells[0][0].get_state();
    } else if (cells[0][2].get_state() != CellState::NONE && cells[0][2].get_state() == cells[1][1].get_state() && cells[0][2].get_state() == cells[2][0].get_state()) {
        return cells[0][2].get_state();
    } else {
        return CellState::NONE;
    }
}
