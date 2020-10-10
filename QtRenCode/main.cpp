#include "QtRenCode.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtRenCode w;
    w.show();
    return a.exec();
}
