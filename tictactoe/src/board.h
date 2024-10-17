#include "src/cell.h"
#include <QWidget>
#include <QGridLayout>

class Board: public QWidget {
    Q_OBJECT

    public:
        Cell cells[3][3];

        explicit Board(QWidget *parent = 0);
        ~Board();

    private:
        QGridLayout *layout;

    signals:
        void clicked(int row, int col);
    private slots:
        void cell_clicked(int row, int col);
};
