#include "Bomberman.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Bomberman w;
    w.show();
    return a.exec();
}
