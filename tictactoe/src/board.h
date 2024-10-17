#include "qwindowdefs.h"
#include "src/cell.h"
#include <QWidget>

class Board: public QWidget {
    Q_OBJECT
    
    public:
        Cell cells[3][3];

        explicit Board(QWidget *parent = 0);

    signals:
        void clicked(int row, int col);
    private slots:
        void cell_clicked(int row, int col);
};
