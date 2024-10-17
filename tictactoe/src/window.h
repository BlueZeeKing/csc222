#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include "cell.h"

class Window: public QWidget {
    Q_OBJECT

    public:
        explicit Window(QWidget *parent = 0);
    private:
        Cell cells[3][3];
        QGridLayout *layout;

        bool is_x_turn;

        void update_state(int row, int col, CellState new_state);
        bool is_tie();
        CellState winner();

    private slots:
        void process_move(int row, int col);
};
