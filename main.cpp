#include "inmaco.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InMaCo w;
    w.show();
    return a.exec();
}
