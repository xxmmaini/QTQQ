#include "qtqq.h"
#include "signin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::addLibraryPath("./plugins");
    Qtqq w;
    return a.exec();
}
