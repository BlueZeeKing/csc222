#include "src/window.h"
#include "qboxlayout.h"
#include "src/cell.h"
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>

Window::Window(QWidget *parent) : QWidget(parent) {
    layout = new QVBoxLayout(this);

    board = new Board();
    connect(board, &Board::clicked, this, &Window::process_move);


    label = new QLabel(this);

    layout->addWidget(board);
    layout->addWidget(label);

    update_label();
    is_x_turn = true;
}

void Window::process_move(int row, int col) {
    if (board->cells[row][col].get_state() != CellState::NONE || is_tie() || winner() != CellState::NONE) {
        return; 
    }

    if (is_x_turn) {
        update_state(row, col, CellState::X);
        is_x_turn = false;
        update_label();
    } else {
        update_state(row, col, CellState::O);
        is_x_turn = true;
        update_label();
    }

    if (is_tie()) {
        update_label("Tie game!");
    }

    CellState current_winner = winner();

    if (current_winner == CellState::X) {
        update_label("X Won!");
    } else if (current_winner == CellState::O) {
        update_label("O Won!");
    }
}

void Window::update_state(int row, int col, CellState new_state) {
    board->cells[row][col].set_state(new_state);
}

bool Window::is_tie() {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (board->cells[row][col].get_state() == CellState::NONE) {
                return false;
            }
        }
    }

    return true;
}

CellState Window::winner() {
    if (board->cells[0][0].get_state() != CellState::NONE && board->cells[0][0].get_state() == board->cells[0][1].get_state() && board->cells[0][0].get_state() == board->cells[0][2].get_state()) {
        return board->cells[0][0].get_state();
    } else if (board->cells[1][0].get_state() != CellState::NONE && board->cells[1][0].get_state() == board->cells[1][1].get_state() && board->cells[1][0].get_state() == board->cells[1][2].get_state()) {
        return board->cells[1][0].get_state();
    } else if (board->cells[2][0].get_state() != CellState::NONE && board->cells[2][0].get_state() == board->cells[2][1].get_state() && board->cells[2][0].get_state() == board->cells[2][2].get_state()) {
        return board->cells[2][0].get_state();
    } else if (board->cells[0][0].get_state() != CellState::NONE && board->cells[0][0].get_state() == board->cells[1][0].get_state() && board->cells[0][0].get_state() == board->cells[2][0].get_state()) {
        return board->cells[0][0].get_state();
    } else if (board->cells[0][1].get_state() != CellState::NONE && board->cells[0][1].get_state() == board->cells[1][1].get_state() && board->cells[0][1].get_state() == board->cells[2][1].get_state()) {
        return board->cells[0][1].get_state();
    } else if (board->cells[0][2].get_state() != CellState::NONE && board->cells[0][2].get_state() == board->cells[1][2].get_state() && board->cells[0][2].get_state() == board->cells[2][2].get_state()) {
        return board->cells[0][2].get_state();
    } else if (board->cells[0][0].get_state() != CellState::NONE && board->cells[0][0].get_state() == board->cells[1][1].get_state() && board->cells[0][0].get_state() == board->cells[2][2].get_state()) {
        return board->cells[0][0].get_state();
    } else if (board->cells[0][2].get_state() != CellState::NONE && board->cells[0][2].get_state() == board->cells[1][1].get_state() && board->cells[0][2].get_state() == board->cells[2][0].get_state()) {
        return board->cells[0][2].get_state();
    } else {
        return CellState::NONE;
    }
}

Window::~Window() {
    delete board;
}

void Window::update_label(const QString& message) {
    label->setText(message);
}

void Window::update_label() {
    if (is_x_turn) {
        update_label("X's turn");
    } else {
        update_label("O's turn");
    }
}
