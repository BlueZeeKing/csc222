#pragma once

#include <QWidget>
#include <QPushButton>

enum CellState {
    X,
    O,
    NONE,
};

class Cell: public QPushButton {
    Q_OBJECT

    private:
        int row;
        int col;
        CellState state;

    public:
        Cell();
        explicit Cell(int row, int col, QWidget *parent = 0);
        void set_state(CellState state);
        CellState get_state();

    signals:
        void clicked(int row, int col);
    private slots:
        void button_clicked(bool checked);
};
