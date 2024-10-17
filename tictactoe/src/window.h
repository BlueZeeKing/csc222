#pragma once

#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include "cell.h"
#include "board.h"

class Window: public QWidget {
    Q_OBJECT

    public:
        explicit Window(QWidget *parent = 0);
        ~Window();

    private:
        Board *board;
        QLabel *label;
        QVBoxLayout *layout;

        bool is_x_turn;

        void update_state(int row, int col, CellState new_state);
        bool is_tie();
        CellState winner();

        void update_label(const QString& message);
        void update_label();

    private slots:
        void process_move(int row, int col);
};
